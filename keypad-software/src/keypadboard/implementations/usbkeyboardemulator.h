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
        if (row == 0 && col == 0)
        {
            m_keyboard.press(HID_KEY_GUI_LEFT);
            m_keyboard.press(HID_KEY_SPACE);
            m_keyboard.releaseAll();
            m_keyboard.println("terminal");
        }
        else if (row == 0 && col == 1)
        {
            m_keyboard.press(HID_KEY_GUI_LEFT);
            m_keyboard.write('r');
        }
        else if (row == 1 && col == 0)
        {
            m_keyboard.println(R"(explorer https://i.makeagif.com/media/3-09-2021/YYrqBc.gif | open https://i.makeagif.com/media/3-09-2021/YYrqBc.gif)");
        }
        else if (row == 2 && col == 3)
        {
            m_keyboard.press(HID_KEY_RETURN);
        }
    }

    virtual void onButtonReleased(uint8_t row, uint8_t col) override
    {
        // if (row == 2 && col == 0)
        // {
        //     m_keyboard.release('z');
        // }
        // if (row == 2 && col == 3)
        // {
        //     m_keyboard.releaseAll();
        // }
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
