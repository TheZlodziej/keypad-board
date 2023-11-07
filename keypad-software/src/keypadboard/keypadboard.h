#ifndef __KEYPAD_BOARD_H
#define __KEYPAD_BOARD_H

#include "../configuration.h"
#include "../analoginput.h"
#include "../buttonmatrix.h"
#include "../incrementalencoder.h"
#include "implementations/i_implementation.h"

#include <FastLED.h>

class KeypadBoard
{
private:
    static KeypadBoard *m_instance;

    IKeypadImplementation *m_implementation;
    ButtonMatrix<KEYPAD_ROW_COUNT, KEYPAD_COL_COUNT> m_buttons;
    AnalogInput m_slider;
    CRGB m_leds[KEYPAD_LED_COUNT];
    IncrementalEncoder m_left_encoder;
    IncrementalEncoder m_right_encoder;

    void onLeftEncoderIncremented()
    {
        m_implementation->onLeftEncoderIncremented();
    }

    void onLeftEncoderDecremented()
    {
        m_implementation->onLeftEncoderDecremented();
    }

    void onLeftEncoderValueChanged(uint8_t value)
    {
        m_implementation->onLeftEncoderValueChanged(value);
    }

    void onRightEncoderIncremented()
    {
        m_implementation->onLeftEncoderIncremented();
    }

    void onRightEncoderDecremented()
    {
        m_implementation->onLeftEncoderDecremented();
    }

    void onRightEncoderValueChanged(uint8_t value)
    {
        m_implementation->onLeftEncoderValueChanged(value);
    }

    void onButtonClicked(uint8_t row, uint8_t col)
    {
        tone(BUZZER_PIN, 1200, 100);
        const uint8_t led_idx = row * KEYPAD_COL_COUNT + col;
        m_leds[led_idx].setHue(map(led_idx, 0, KEYPAD_LED_COUNT, 0, 255));
        FastLED.show();

        if (m_implementation)
        {
            m_implementation->onButtonClicked(row, col);
        }
    }

    void onButtonReleased(uint8_t row, uint8_t col)
    {
        const uint8_t led_idx = row * KEYPAD_COL_COUNT + col;
        m_leds[led_idx].fadeToBlackBy(255);
        FastLED.show();

        if (m_implementation)
        {
            m_implementation->onButtonReleased(row, col);
        }
    }

    void onButtonPressed(uint8_t row, uint8_t col)
    {
        if (m_implementation)
        {
            m_implementation->onButtonPressed(row, col);
        }
    }

    void setupLEDs()
    {
        FastLED.addLeds<SK6812, KEYPAD_LED_DATA_PIN, GRB>(m_leds, KEYPAD_LED_COUNT);
        FastLED.setBrightness(m_slider.getValue() * 255);
        for (uint8_t led_idx = 0; led_idx < KEYPAD_LED_COUNT; led_idx++)
        {
            m_leds[led_idx].setRGB(0, 0, 0);
        }
        FastLED.show();
    }

    void setupBuzzer()
    {
        pinMode(BUZZER_PIN, OUTPUT);
        digitalWrite(BUZZER_PIN, LOW);
    }

    void setupSlider()
    {
        m_slider.setOnValueChangedCallback([](float new_value)
                                           { FastLED.setBrightness(new_value * 255); });
    }

    void setupButtons()
    {
        for (uint8_t row = 0; row < KEYPAD_ROW_COUNT; row++)
        {
            for (uint8_t col = 0; col < KEYPAD_COL_COUNT; col++)
            {
                m_buttons.setButtonClickedCallback(row, col, [row, col, this]()
                                                   { onButtonClicked(row, col); });

                m_buttons.setButtonPressedCallback(row, col, [row, col, this]()
                                                   { onButtonPressed(row, col); });

                m_buttons.setButtonReleasedCallback(row, col, [row, col, this]()
                                                    { onButtonReleased(row, col); });
            }
        }
    }

    void setupEncoders()
    {
        m_left_encoder.setOnIncrementedCallback([this]()
                                                { onLeftEncoderIncremented(); });
        m_left_encoder.setOnDecrementedCallback([this]()
                                                { onLeftEncoderDecremented(); });
        m_left_encoder.setOnValueChangedCallback([this](uint8_t new_value)
                                                 { onLeftEncoderValueChanged(new_value); });

        m_right_encoder.setOnIncrementedCallback([this]()
                                                 { onRightEncoderIncremented(); });
        m_right_encoder.setOnDecrementedCallback([this]()
                                                 { onRightEncoderDecremented(); });
        m_right_encoder.setOnValueChangedCallback([this](uint8_t new_value)
                                                  { onRightEncoderValueChanged(new_value); });
    }

protected:
    explicit KeypadBoard() : m_implementation(nullptr),
                             m_buttons(KEYPAD_ROW_PINS, KEYPAD_COL_PINS),
                             m_slider({SLIDER_PIN, SLIDER_DEBOUNCE_TIME, SLIDER_CHANGE_VALUE_THRESHHOLD, ADC_RESOLUTION}),
                             m_left_encoder(ENCODER_LEFT_PIN_A, ENCODER_LEFT_PIN_B, ENCODER_RESOLUTION),
                             m_right_encoder(ENCODER_RIGHT_PIN_A, ENCODER_RIGHT_PIN_B, ENCODER_RESOLUTION)
    {
        analogWriteResolution(ADC_RESOLUTION);
        setupLEDs();
        setupBuzzer();
        setupButtons();
        setupEncoders();
    }

public:
    KeypadBoard(const KeypadBoard &) = delete;
    KeypadBoard(KeypadBoard &&) = delete;

    static KeypadBoard &getInstance()
    {
        if (!m_instance)
        {
            m_instance = new KeypadBoard();
        }

        return *m_instance;
    }

    static void setImplementation(IKeypadImplementation *implementation)
    {
        auto &instance = getInstance();
        delete instance.m_implementation;
        instance.m_implementation = implementation;
    }

    static void update()
    {
        KeypadBoard &instance = getInstance();
        instance.m_buttons.update();
        instance.m_slider.update();
        instance.m_left_encoder.update();
        instance.m_right_encoder.update();
        instance.m_implementation->update();
    }
};

KeypadBoard *KeypadBoard::m_instance = nullptr;

#endif
