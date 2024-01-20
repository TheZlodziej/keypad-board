#ifndef __ANALOG_INPUT_H
#define __ANALOG_INPUT_H

#include <Arduino.h>
#include <functional>

struct AnalogInputConfig
{
  uint8_t pin;
  uint32_t debounce_time; // ms
  float change_value_threshhold;
  uint16_t adc_resolution;
};

class AnalogInput
{
private:
  const AnalogInputConfig m_config;
  float m_value; // <0; 1>
  uint32_t m_last_changed;
  std::function<void(float)> m_onValueChanged;

public:
  AnalogInput(const AnalogInputConfig &config)
      : m_config(config), m_last_changed(config.debounce_time)
  {
    pinMode(config.pin, INPUT);
  }

  void setOnValueChangedCallback(std::function<void(float)> onValueChanged)
  {
    m_onValueChanged = onValueChanged;
  }

  void update()
  {
    const uint32_t now = millis();
    const uint16_t raw_reading = analogRead(m_config.pin);
    const float new_value =
        static_cast<float>(raw_reading) / ((1 << m_config.adc_resolution) - 1);
    if (fabs(new_value - m_value) >= m_config.change_value_threshhold)
    {
      if (now - m_last_changed > m_config.debounce_time)
      {
        m_value = new_value;
        if (m_onValueChanged)
          m_onValueChanged(m_value);
        m_last_changed = now;
      }
    }
    else
    {
      m_last_changed = now;
    }

#ifdef DEBUG_ANALOG_INPUT
    print();
#endif
  }

#ifdef DEBUG_ANALOG_INPUT
  void print()
  {
    Serial.println("Analog Input (pin" + String(m_config.pin) + "):");
    Serial.println(m_value, 2);
  }
#endif

  float getValue() const { return m_value; }
};

#endif
