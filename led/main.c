
#include "stm32f4_discovery.h"

/* LED3: Orange (E) 
 * LED4: Green  (N)
 * LED5: Red    (S)
 * LED6: Blue   (W)
 */
//Led_TypeDef LEDS[] = {LED3, LED4, LED3, LED4, LED5, LED4, LED6};
Led_TypeDef LEDS[] = {LED3, LED4, LED3, LED6, LED4};

void LEDInit(Led_TypeDef led);

int main(void) {
  int idx = 0;
  int nLEDs = sizeof(LEDS) / sizeof(LEDS[0]);
  
  LEDInit(LED4);
  LEDInit(LED3);
  LEDInit(LED5);
  LEDInit(LED6);
  while (1) {
    int i;
    for (i = 0; i < 5000000; i++) {}
    STM_EVAL_LEDOff(LEDS[idx]);
    if (++idx == nLEDs) idx = 0;
    STM_EVAL_LEDOn(LEDS[idx]);
  }
  return 0;
}

void LEDInit(Led_TypeDef led) {
  STM_EVAL_LEDInit(led);
  STM_EVAL_LEDOff(led);
}


void _exit(int a) {
  while (1) {}
}
