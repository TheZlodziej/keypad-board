#include "keypadboard/keypadboard.h"
// #include "keypadboard/implementations/keyboardemulator.h"
#include "keypadboard/implementations/usbkeyboardemulator.h"

#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C // I2C address of your OLED display

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup()
{
  Serial.begin(115200);

  // Initialize I2C communication with specific SDA and SCL pins
  Wire.begin(39, 38);

  // Initialize with the I2C addr 0x3D (for the 128x64)
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }

  // Clear the buffer
  display.clearDisplay();

  // Display welcome message
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print(F("Hello, ESP32!"));
  display.display();
  delay(2000);
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
