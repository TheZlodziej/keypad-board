#ifndef __KEYPAD_DUMMY_IMPLEMENTATION
#define __KEYPAD_DUMMY_IMPLEMENTATION

#include "i_implementation.h"

class DummyKeypadImplementation : public IKeypadImplementation
{
public:
    virtual void onButtonClicked(uint8_t, uint8_t) override{};
    virtual void onButtonPressed(uint8_t, uint8_t) override{};
    virtual void onButtonReleased(uint8_t, uint8_t) override{};
    virtual void onSliderValueChanged(float) override{};
    virtual void update() override{};
    virtual void onLeftEncoderValueChanged(uint8_t) override {}
    virtual void onLeftEncoderIncremented() override {}
    virtual void onLeftEncoderDecremented() override {}
    virtual void onRightEncoderValueChanged(uint8_t) override {}
    virtual void onRightEncoderIncremented() override {}
    virtual void onRightEncoderDecremented() override {}
};

#endif
