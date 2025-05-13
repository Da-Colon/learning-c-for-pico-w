#include "pico/stdlib.h"

void foo() {}
void runButtonModes(int w_led_pin, int y_led_pin, int button_pin)
{
  stdio_init_all();

  // init the color pins
  gpio_init(w_led_pin);
  gpio_set_dir(w_led_pin, GPIO_OUT);

  gpio_init(y_led_pin);
  gpio_set_dir(y_led_pin, GPIO_OUT);

  // init the button pin
  gpio_init(button_pin);
  gpio_set_dir(button_pin, GPIO_IN);
  gpio_pull_up(button_pin);

  int buttonState = 0;
  gpio_set_irq_enabled_with_callback(button_pin, GPIO_IRQ_EDGE_FALL, true, foo);

  while (1)
  {
    // Check the button state
    buttonState = gpio_get(button_pin);

    // If the button is pressed, turn on the white LED
    if (buttonState == 0)
    {
      gpio_put(w_led_pin, 1);
      gpio_put(y_led_pin, 0);
    }
    else
    {
      gpio_put(w_led_pin, 0);
      gpio_put(y_led_pin, 1);
    }
  }
}