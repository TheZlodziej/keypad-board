#ifndef __CONFIGURATION_H
#define __CONFIGURATION_H

#include <Arduino.h>

// #define DEBUG

const uint8_t BUZZER_PIN{17};

const uint8_t SLIDER_PIN{12};
const uint32_t SLIDER_DEBOUNCE_TIME{600}; // ms
const float SLIDER_CHANGE_VALUE_THRESHHOLD{0.01f};

const uint8_t ENCODER_LEFT_PIN_A{8};
const uint8_t ENCODER_LEFT_PIN_B{18};
const uint8_t ENCODER_RIGHT_PIN_A{10};
const uint8_t ENCODER_RIGHT_PIN_B{9};
const uint8_t ENCODER_RESOLUTION{30};

const uint8_t KEYPAD_LED_DATA_PIN{20};
const uint8_t KEYPAD_LED_COUNT{12};
const uint8_t KEYPAD_ROW_PINS[] = {35, 36, 38};
const uint8_t KEYPAD_COL_PINS[] = {14, 21, 13, 47};
const uint8_t KEYPAD_ROW_COUNT = sizeof(KEYPAD_ROW_PINS) / sizeof(KEYPAD_ROW_PINS[0]);
const uint8_t KEYPAD_COL_COUNT = sizeof(KEYPAD_COL_PINS) / sizeof(KEYPAD_COL_PINS[0]);

const uint8_t ADC_RESOLUTION{12}; // bits
const uint16_t MAX_ADC_VALUE{(1 << 12) - 1};

#endif
