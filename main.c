#include "pico/stdlib.h"
#include "moorseCode.h"

#define LED_PIN 15 // Define LED_PIN here

int main() {
    runMoorseCode(LED_PIN); // Pass LED_PIN to the function
    return 0;
}
