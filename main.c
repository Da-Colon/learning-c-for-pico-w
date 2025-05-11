#include "pico/stdlib.h"

#define LED_PIN 15

int main() {
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        gpio_put(LED_PIN, 1);  // Turn LED on
        sleep_ms(500);        // Wait 500ms
        gpio_put(LED_PIN, 0);  // Turn LED off
        sleep_ms(500);        // Wait 500ms
    }
}
