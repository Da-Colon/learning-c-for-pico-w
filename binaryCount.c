#include "pico/stdlib.h"

// 0 0 0 0 = 0
// 0 0 0 1 = 1
// 0 0 1 0 = 2
// 0 0 1 1 = 3
// 0 1 0 0 = 4
// 0 1 0 1 = 5
// 0 1 1 0 = 6
// 0 1 1 1 = 7
// 1 0 0 0 = 8

// right to left
// 1  = GP12
// 2s = GP13
// 4s = GP14
// 8s = GP15

const int COUNT_WAIT = 500; // 500ms

void countUpToFifteen(int ledPinOne, int ledPinTwo, int ledPinThree, int ledPinFour) {
  stdio_init_all();

  // init all the pints
  gpio_init(ledPinOne);
  gpio_set_dir(ledPinOne, GPIO_OUT);

  gpio_init(ledPinTwo);
  gpio_set_dir(ledPinTwo, GPIO_OUT);

  gpio_init(ledPinThree);
  gpio_set_dir(ledPinThree, GPIO_OUT);

  gpio_init(ledPinFour);
  gpio_set_dir(ledPinFour, GPIO_OUT);

  while (true) {
    gpio_put_all(0); // Turn off all LEDs
    sleep_ms(COUNT_WAIT * 2);

    for (int i = 0; i < 16; i++) {
      gpio_put(ledPinOne, (i & 1) ? 1 : 0); // Set LED 1
      gpio_put(ledPinTwo, (i & 2) ? 1 : 0); // Set LED 2
      gpio_put(ledPinThree, (i & 4) ? 1 : 0); // Set LED 3
      gpio_put(ledPinFour, (i & 8) ? 1 : 0); // Set LED 4
      sleep_ms(COUNT_WAIT);
    }

  }
}