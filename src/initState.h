#ifndef INIT_STATE_INFO_H
#define INIT_STATE_INFO_H

typedef enum{
	INITIAL,
	STATE_A,
	STATE_B,
  PRESS_CHECK,
}STATE;

typedef enum{
	LED_ON,
	LED_OFF
}StatusOfLED;

typedef struct{
	STATE state;
  StatusOfLED ledStatus; //what the variable name?
}ledSM;
//shld not be getStatus, wrong name

#endif //INIT_STATE_INFO_H