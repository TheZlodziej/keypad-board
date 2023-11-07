#ifndef __USB_KEYBOARD_EMULATOR_H
#define __USB_KEYBOARD_EMULATOR_H

#include "dummy.h"

#include <USB.h>
#include <USBHIDKeyboard.h>

class USBKeyboardEmulator : public DummyKeypadImplementation
{
private:
    USBHIDKeyboard m_keyboard;

public:
    USBKeyboardEmulator()
    {
        m_keyboard.begin();
        USB.begin();
    }

    virtual void onButtonClicked(uint8_t row, uint8_t col) override
    {
        if (row == 1 && col == 0)
        {
            m_keyboard.print("Hello, World!");
        }
        else if (row == 2 && col == 0)
        {
            m_keyboard.press('z');
        }
    }

    virtual void onButtonReleased(uint8_t row, uint8_t col) override
    {
        if (row == 2 && col == 0)
        {
            m_keyboard.release('z');
        }
    }

    virtual void onLeftEncoderIncremented() override
    {
        m_keyboard.write(HID_KEY_VOLUME_UP);
    }

    virtual void onLeftEncoderDecremented() override
    {
        m_keyboard.write(HID_KEY_VOLUME_DOWN);
    }
};

#endif
