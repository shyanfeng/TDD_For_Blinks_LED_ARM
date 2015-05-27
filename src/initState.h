#ifndef INIT_STATE_INFO_H
#define INIT_STATE_INFO_H

typedef enum{
	INITIAL,
	STATE_A,
	STATE_B
}STATE;

typedef struct {
	uint32_t state;
}TaskBlock;

#endif //INIT_STATE_INFO_H