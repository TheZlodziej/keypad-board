#ifndef __BUTTON_MATRIX_H
#define __BUTTON_MATRIX_H

#include <Arduino.h>
#include <functional>

template <uint8_t rows, uint8_t cols>
class ButtonMatrix
{
private:
    const uint32_t m_debounce_time{10}; // ms
    const uint8_t *m_row_pins;
    const uint8_t *m_col_pins;
    bool m_state[rows * cols];
    uint32_t m_last_pressed[rows * cols];
    std::function<void()> m_onClicked[rows * cols];
    std::function<void()> m_onPressed[rows * cols];
    std::function<void()> m_onReleased[rows * cols];

    uint8_t coords2index(uint8_t row, uint8_t col) const
    {
        return row * cols + col;
    }

public:
    ButtonMatrix(const uint8_t *row_pins, const uint8_t *col_pins) : m_row_pins(row_pins), m_col_pins(col_pins)
    {
        for (uint8_t row = 0; row < rows; row++)
        {
            pinMode(row_pins[row], OUTPUT);
            digitalWrite(row_pins[row], LOW);
            for (uint8_t col = 0; col < cols; col++)
            {
                pinMode(col_pins[col], INPUT_PULLDOWN);
                const uint8_t button_idx = coords2index(row, col);
                m_state[button_idx] = false;
                m_last_pressed[button_idx] = m_debounce_time;
                m_onClicked[button_idx] = nullptr;
                m_onPressed[button_idx] = nullptr;
                m_onReleased[button_idx] = nullptr;
            }
        }
    }

    void update()
    {
        const uint32_t now = millis();

        for (uint8_t row = 0; row < rows; row++)
        {
            digitalWrite(m_row_pins[row], HIGH);
            for (uint8_t col = 0; col < cols; col++)
            {
                const uint8_t button_idx = coords2index(row, col);

                if (now - m_last_pressed[button_idx] < m_debounce_time)
                {
                    continue;
                }

                const bool button_pressed = digitalRead(m_col_pins[col]) == HIGH;
                if (button_pressed != m_state[button_idx])
                {
                    if (button_pressed && m_onClicked[button_idx])
                    {
                        // clicked
                        m_onClicked[button_idx]();
                    }

                    else if (!button_pressed && m_onReleased[button_idx])
                    {
                        // released
                        m_onReleased[button_idx]();
                    }

                    m_last_pressed[button_idx] = now;
                }

                if (button_pressed && m_onPressed[button_idx])
                {
                    // pressed
                    m_onPressed[button_idx]();
                }

                m_state[button_idx] = button_pressed;
            }
            digitalWrite(m_row_pins[row], LOW);
        }

#ifdef DEBUG
        print();
#endif
    }

#ifdef DEBUG
    void print()
    {
        Serial.println("BUTTON MATRIX:");
        Serial.println();
        for (uint8_t row = 0; row < rows; row++)
        {
            for (uint8_t col = 0; col < cols; col++)
            {
                Serial.print(m_state[coords2index(row, col)]);
            }
            Serial.println();
        }
    }
#endif

    bool *getState()
    {
        return m_state;
    }

    bool isPressed(uint8_t row, uint8_t col) const
    {
        if (row < rows && col < cols)
        {
            return m_state[coords2index(row, col)];
        }

        return false;
    }

    void setButtonClickedCallback(uint8_t row, uint8_t col, std::function<void()> onClicked)
    {
        if (row < rows && col < cols)
        {
            m_onClicked[coords2index(row, col)] = onClicked;
        }
    }

    void setButtonPressedCallback(uint8_t row, uint8_t col, std::function<void()> onPressed)
    {
        if (row < rows && col < cols)
        {
            m_onPressed[coords2index(row, col)] = onPressed;
        }
    }

    void setButtonReleasedCallback(uint8_t row, uint8_t col, std::function<void()> onReleased)
    {
        if (row < rows && col < cols)
        {
            m_onReleased[coords2index(row, col)] = onReleased;
        }
    }
};

#endif
