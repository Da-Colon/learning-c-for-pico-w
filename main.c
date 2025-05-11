#include "pico/stdlib.h"
#include "dynamicBlink.h"

#define LED_PIN 15 // Define LED_PIN here

int main() {
    run_dynamic_blink(LED_PIN); // Pass LED_PIN to the function
    return 0;
}
