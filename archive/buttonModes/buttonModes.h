
#ifndef BUTTON_MODES_H
#define BUTTON_MODES_H

#include "pico/types.h"

void updateColorMode(uint gpio, uint32_t events);
void runButtonModes(int w_led_pin, int y_led_pin, int button_pin);

#endif // BUTTON_MODES_H
