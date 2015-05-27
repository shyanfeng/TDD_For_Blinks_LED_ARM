#include <stdio.h>
#include <unity.h>
#include "SD5.h"
#include "initState.h"
#include "timeDelay.h"

void SD5(ledSM *state){
	StatusOfLED *statusLED;
  uint32_t previousTime = 0;
	static int i = 0;

	switch(state->state){
	case INITIAL:
    state->ledStatus = LED_OFF;
    if(pushButton1() == 1){
			state->state = STATE_A;
			previousTime = getCurrentTime();
			i = 0;
		}
		break;
    
	case STATE_A:
		state->ledStatus = LED_ON;
		if(delay(200, previousTime)){
			state->state = STATE_B;
			previousTime = getCurrentTime();
			i++;
		}
		break;
    
	case STATE_B:
		state->ledStatus = LED_OFF;
		if(i >= 5){
      if(delay(200, previousTime)){
        state->state = PRESS_CHECK;
        previousTime = getCurrentTime();
      }
		}else if(delay(200, previousTime)){
			state->state = STATE_A;
			previousTime = getCurrentTime();
		}
		break;
    
  case PRESS_CHECK:
    if(pushButton1() == 1){
      state->state = PRESS_CHECK;
    }else 
      state->state = INITIAL;
  
	}
}