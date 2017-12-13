
#include "stm32f4_discovery.h"

LED_TypeDef LEDS[] = {LED4, LED3, LED5, LED4, LED6};

int main(void) {
  int idx = 0;
  int nLEDs = sizeof(LEDS) / sizeof(LEDS[0]);
  
  STM_EVAL_LEDInit(LED4);
  STM_EVAL_LEDInit(LED3);
  STM_EVAL_LEDInit(LED5);
  STM_EVAL_LEDInit(LED6);
  while (1) {
    int i;
    for (i = 0; i < 20000; i++) {}
    STM_EVAL_LEDOff(LEDS[idx]);
    if (++idx == nLEDs) idx = 0;
    STM_EVAL_LEDOn(LED[idx]);
  }
  return 0;
}
