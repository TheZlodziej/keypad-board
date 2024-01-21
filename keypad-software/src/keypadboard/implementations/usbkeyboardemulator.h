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
        m_keyboard.releaseAll();
    }

    virtual void onButtonClicked(uint8_t row, uint8_t col) override
    {
        if (row == 0 && col == 0)
        {
            m_keyboard.press(KEY_LEFT_GUI);
            m_keyboard.press(' ');
            delay(200);
            m_keyboard.releaseAll();
            m_keyboard.println("terminal");
        }
        else if (row == 1 && col == 0)
        {
            m_keyboard.press(KEY_LEFT_GUI);
            m_keyboard.press('r');
            delay(200);
            m_keyboard.releaseAll();
        }
        else if (row == 2 && col == 0)
        {
            m_keyboard.println(R"(cmd /c explorer https://i.makeagif.com/media/3-09-2021/YYrqBc.gif || open https://i.makeagif.com/media/3-09-2021/YYrqBc.gif)");
        }
        else if (row == 2 && col == 3)
        {
            m_keyboard.releaseAll();
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
        m_keyboard.pressRaw(HID_KEY_VOLUME_UP);
        m_keyboard.releaseRaw(HID_KEY_VOLUME_DOWN);
    }

    virtual void onLeftEncoderDecremented() override
    {
        m_keyboard.pressRaw(HID_KEY_VOLUME_DOWN);
        m_keyboard.releaseRaw(HID_KEY_VOLUME_DOWN);
    }
};

#endif
