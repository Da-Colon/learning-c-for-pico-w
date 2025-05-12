#include "pico/stdlib.h"
#include "dynamicBlink.h"

void run_dynamic_blink(int led_pin) {
    stdio_init_all();
    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);

    int interval = 1000;
    while (true) {
        gpio_put(led_pin, 1);
        sleep_ms(interval);
        gpio_put(led_pin, 0);
        sleep_ms(interval);

        if (interval > 100) {
            interval -= 100;
        } else {
            interval = 1000;
        }
    }
}
