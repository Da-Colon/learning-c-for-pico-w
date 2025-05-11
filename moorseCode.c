#include <ctype.h>
#include "pico/stdlib.h"
#include "dynamicBlink.h"

const int ONE_UNIT = 200;
const int THRE_UNIT = ONE_UNIT * 3;
const int SEVEN_UNIT = ONE_UNIT * 7;
const char *morseCodeTable[26] = {
    ".-", "-...", "-.-.", "-..", ".",            // a-e
    "..-.", "--.", "....", "..", ".---",         // f-j
    "-.-", ".-..", "--", "-.", "---",            // k-o
    ".--.", "--.-", ".-.", "...", "-",           // p-t
    "..-", "...-", ".--", "-..-", "-.--", "--.." // u-z
};

static char* getLetterCode(char letter)
{
  char key = tolower(letter);
  if (key < 'a' || key > 'z')
  {
    return NULL; // Return NULL for invalid character
  }
  int index = key - 'a';
  char* code = morseCodeTable[index];
  return code;
}

static void getWordCode(char *word, int led_pin) 
{
  for (int i = 0; word[i] != '\0'; i++)
  {
    char* letterCode = getLetterCode(word[i]);
    if (letterCode == NULL) {
        continue; 
    }
    
    for (int j = 0; letterCode[j] != '\0'; j++) {
      if (letterCode[j] == '.')
      {
        gpio_put(led_pin, 1); // Turn LED on
        sleep_ms(ONE_UNIT);   // Wait for 1 unit
      }
      else if (letterCode[j] == '-')
      {
        gpio_put(led_pin, 1); // Turn LED on
        sleep_ms(THRE_UNIT);  // Wait for 3 units
      }
      if(letterCode[j + 1] == '\0')
      {
        gpio_put(led_pin, 0); // Turn LED off
        sleep_ms(ONE_UNIT); // Wait for 1 unit between letters
      }
    }
  }
}

void runMoorseCode(int led_pin) // Ensured function name matches header
{
  stdio_init_all();
  gpio_init(led_pin);
  gpio_set_dir(led_pin, GPIO_OUT);
  
  while (true)
  {
    gpio_put(led_pin, 0);
    sleep_ms(THRE_UNIT); // Wait for 3 units

    char *word = "hello";
    getWordCode(word, led_pin);
    gpio_put(led_pin, 0); // Turn LED off
    sleep_ms(SEVEN_UNIT); // wait for 7 units after word
  }
}
