#include "pico/stdlib.h"

#define LED_PIN 15

int main() {
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    int interval = 1000; // 1 second interval
    while (true) {
        gpio_put(LED_PIN, 1);  // Turn LED on
        sleep_ms(interval);        // Wait 500ms
        gpio_put(LED_PIN, 0);  // Turn LED off
        sleep_ms(interval);        // Wait 500ms

        if (interval > 100) {
            interval -= 100; // Decrease interval by 100ms
        } else {
            interval = 1000; // Reset to 1 second
        }
    }
}
