#ifndef __INCREMENTAL_ENCODER_H
#define __INCREMENTAL_ENCODER_H

#include <Arduino.h>
#include <functional>

class IncrementalEncoder
{
private:
    const int8_t m_dir_table[16] = {
        0, -1, 1, 0,
        1, 0, 0, -1,
        -1, 0, 0, 1,
        0, 1, -1, 0};
    uint8_t m_counter;
    uint8_t m_prev_state;
    uint8_t m_pin_a;
    uint8_t m_pin_b;
    uint8_t m_resolution;
    std::function<void()> m_onIncremented;
    std::function<void()> m_onDecremented;
    std::function<void(uint8_t)> m_onValueChanged;

public:
    IncrementalEncoder(uint8_t pin_a, uint8_t pin_b, uint8_t resolution) : m_counter(0),
                                                                           m_pin_a(pin_a),
                                                                           m_pin_b(pin_b),
                                                                           m_resolution(resolution)
    {
        pinMode(m_pin_a, INPUT_PULLUP);
        pinMode(m_pin_b, INPUT_PULLUP);
        m_prev_state = digitalRead(m_pin_a) | (digitalRead(m_pin_b) << 1);
    }

    void update()
    {
        const uint8_t state = digitalRead(m_pin_a) | (digitalRead(m_pin_b) << 1);
        const uint8_t dir_idx = state | (m_prev_state << 2);
        const int8_t dir = m_dir_table[dir_idx];
        if (state == 1 || state == 2)
        {
            if (dir == 1)
            {
                if (m_counter > 0)
                    m_counter--;
                else
                    m_counter = m_resolution - 1;

                if (m_onIncremented)
                    m_onIncremented();
            }
            else if (dir == -1)
            {
                if (m_counter < m_resolution - 1)
                    m_counter++;
                else
                    m_counter = 0;

                if (m_onDecremented)
                    m_onDecremented();
            }

            if (m_onValueChanged)
                m_onValueChanged(m_counter);
        }
        m_prev_state = state;
#ifdef DEBUG_ENCODER
        print();
#endif
    }

#ifdef DEBUG_ENCODER
    void
    print()
    {
        Serial.println("Encoder - pins<" + String(m_pin_a) + ", " + String(m_pin_b) + ">:");
        Serial.println(String(m_counter) + "/" + String(m_resolution));
        Serial.println();
    }
#endif

    uint8_t getCounter() const
    {
        return m_counter;
    }

    void setOnIncrementedCallback(std::function<void()> onIncremented)
    {
        m_onIncremented = onIncremented;
    }

    void setOnDecrementedCallback(std::function<void()> onDecremented)
    {
        m_onDecremented = onDecremented;
    }

    void setOnValueChangedCallback(std::function<void(uint8_t)> onValueChanged)
    {
        m_onValueChanged = onValueChanged;
    }
};

#endif
