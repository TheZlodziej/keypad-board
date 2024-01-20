#include "keypadboard/keypadboard.h"
// #include "keypadboard/implementations/keyboardemulator.h"
#include "keypadboard/implementations/usbkeyboardemulator.h"

void setup()
{
  // KeypadBoard::setImplementation(new DummyKeypadImplementation); // init
  // KeypadBoard::setImplementation(new KeyboardEmulator); // init
  KeypadBoard::setImplementation(new USBKeyboardEmulator); // init

#ifdef DEBUG
  Serial.begin(115200);
#endif
}

void loop()
{
  KeypadBoard::update();
  delay(1);
}
