#ifndef __KEYPAD_IMPLEMENTATION_INTERFACE
#define __KEYPAD_IMPLEMENTATION_INTERFACE

#include <Arduino.h>

class IKeypadImplementation
{
public:
    virtual void onButtonClicked(uint8_t, uint8_t) = 0;
    virtual void onButtonPressed(uint8_t, uint8_t) = 0;
    virtual void onButtonReleased(uint8_t, uint8_t) = 0;
    virtual void onSliderValueChanged(float) = 0;
    virtual void onLeftEncoderValueChanged(uint8_t) = 0;
    virtual void onLeftEncoderIncremented() = 0;
    virtual void onLeftEncoderDecremented() = 0;
    virtual void onRightEncoderValueChanged(uint8_t) = 0;
    virtual void onRightEncoderIncremented() = 0;
    virtual void onRightEncoderDecremented() = 0;
    virtual void update() = 0;
};

#endif
