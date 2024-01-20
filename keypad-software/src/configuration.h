#ifndef __CONFIGURATION_H
#define __CONFIGURATION_H

#include <Arduino.h>

// #define DEBUG

#ifdef DEBUG
#define DEBUG_ENCODER
#define DEBUG_BUTTON_MATRIX
#define DEBUG_ANALOG_INPUT
#endif

const uint8_t BUZZER_PIN{6};

const uint8_t SLIDER_PIN{7};
const uint32_t SLIDER_DEBOUNCE_TIME{600}; // ms
const float SLIDER_CHANGE_VALUE_THRESHHOLD{0.01f};

const uint8_t ENCODER_LEFT_PIN_A{18};
const uint8_t ENCODER_LEFT_PIN_B{17};
const uint8_t ENCODER_RIGHT_PIN_A{9};
const uint8_t ENCODER_RIGHT_PIN_B{3};
const uint8_t ENCODER_RESOLUTION{24};

const uint8_t KEYPAD_LED_DATA_PIN{48};
const uint8_t KEYPAD_LED_COUNT{12};
const uint8_t KEYPAD_ROW_PINS[] = {47, 21, 14};
const uint8_t KEYPAD_COL_PINS[] = {13, 12, 11, 10};
const uint8_t KEYPAD_ROW_COUNT = sizeof(KEYPAD_ROW_PINS) / sizeof(KEYPAD_ROW_PINS[0]);
const uint8_t KEYPAD_COL_COUNT = sizeof(KEYPAD_COL_PINS) / sizeof(KEYPAD_COL_PINS[0]);
const uint32_t KEYPAD_LED_COLOR_TABLE[] = {
    0xff0033, 0x4adede, 0x4adede, 0x4adede,
    0x4adede, 0x4adede, 0x4adede, 0x4adede,
    0x4adede, 0x4adede, 0x4adede, 0x4adede};

const uint8_t ADC_RESOLUTION{12}; // bits
const uint16_t MAX_ADC_VALUE{(1 << 12) - 1};

#endif
