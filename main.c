#include "pico/stdlib.h"
#include "buttonModes.h"
const int WHITE_LED_PIN = 15;
const int YELLOW_LED_PIN = 14;
const int BUTTON_PIN = 16;
int main() {
    runButtonModes(WHITE_LED_PIN, YELLOW_LED_PIN, BUTTON_PIN);
    return 0;
}
