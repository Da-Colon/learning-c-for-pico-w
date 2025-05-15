#include "pico/stdlib.h"
// color modes
// 0 = default both off
// 1 = both on
// 2 = blinking alternating (slow)
// 3 = blinking alternating (fast)
// ~ reset to 0
const int DEBOUNCE_TIME_MS = 400;
int colorMode = 0;
int lastInterruptMs = 0;

void updateColorMode(uint gpio, uint32_t events)
{
  if (to_ms_since_boot(get_absolute_time()) - lastInterruptMs < DEBOUNCE_TIME_MS)
  {
    return;
  }
  if (colorMode < 3)
  {
    colorMode++;
  }
  else
  {
    colorMode = 0;
  }
  lastInterruptMs = to_ms_since_boot(get_absolute_time());
};
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

  gpio_set_irq_enabled_with_callback(button_pin, GPIO_IRQ_EDGE_FALL, true, updateColorMode);
  int ledState = 0;
  absolute_time_t lastToggle = get_absolute_time();
  int interval = 500;
  while (1)
  {
    gpio_get(button_pin);

    switch (colorMode)
    {
    case 0:
      gpio_put(w_led_pin, 0);
      gpio_put(y_led_pin, 0);
      break;
    case 1:
      gpio_put(w_led_pin, 1);
      gpio_put(y_led_pin, 1);
      break;
    case 2:
      interval = 500;
      if (absolute_time_diff_us(lastToggle, get_absolute_time()) > interval * 1000)
      {
        ledState = !ledState;
        gpio_put(w_led_pin, ledState);
        gpio_put(y_led_pin, !ledState);
        lastToggle = get_absolute_time();
      }
      break;
    case 3:
      interval = 100;
      if (absolute_time_diff_us(lastToggle, get_absolute_time()) > interval * 1000)
      {
        ledState = !ledState;
        gpio_put(w_led_pin, ledState);
        gpio_put(y_led_pin, !ledState);
        lastToggle = get_absolute_time();
      }
      break;
    }
    tight_loop_contents();
  }
}