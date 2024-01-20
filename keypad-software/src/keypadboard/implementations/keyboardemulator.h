#ifndef __KEYBOARD_EMULATOR_H
#define __KEYBOARD_EMULATOR_H

#include "dummy.h"

#include <BleKeyboard.h>

class KeyboardEmulator : public DummyKeypadImplementation
{
private:
    BleKeyboard m_keyboard;

public:
    KeyboardEmulator() : m_keyboard("Keypad Board", "minekuba", 69)
    {
        m_keyboard.begin();
    }

    virtual void onButtonClicked(uint8_t row, uint8_t col) override
    {
        if (!m_keyboard.isConnected())
            return;

        if (row == 1 && col == 0)
        {
            m_keyboard.print("Hello, World!");
        }
        else if (row == 2 && col == 0)
        {
            m_keyboard.write('z');
        }
    }

    virtual void onButtonReleased(uint8_t row, uint8_t col) override
    {
        if (row == 2 && col == 3)
        {
            m_keyboard.releaseAll();
        }
    }

    virtual void onLeftEncoderIncremented() override
    {
        if (m_keyboard.isConnected())
            m_keyboard.write(KEY_MEDIA_VOLUME_UP);
    }

    virtual void onLeftEncoderDecremented() override
    {
        if (m_keyboard.isConnected())
            m_keyboard.write(KEY_MEDIA_VOLUME_DOWN);
    }
};

#endif
