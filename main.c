#include "pico/stdlib.h"
#include "binaryCount.h" // Include binaryCount.h instead of moorseCode.h

#define LED_PIN_1 12 // Define LED_PIN_1 for GP12
#define LED_PIN_2 13 // Define LED_PIN_2 for GP13
#define LED_PIN_3 14 // Define LED_PIN_3 for GP14
#define LED_PIN_4 15 // Define LED_PIN_4 for GP15

int main() {
    countUpToFifteen(LED_PIN_1, LED_PIN_2, LED_PIN_3, LED_PIN_4); // Call countUpToFifteen with the defined pins
    return 0;
}
