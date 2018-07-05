#ifndef _LEDCONTROLLER_H
#define _LEDCONTROLLER_H
#include "led.h"
#include "Button.h"

typedef struct LedButtonInfo LedButtonInfo;
	struct LedButtonInfo{
	LedState currentLedState;
	ButtonState previousButtonState;
	
};

void turnOnLedIfButtonIsPressed(void);

void dotapTurnOntapTurnOffLed(LedButtonInfo *state);

#endif // _LEDCONTROLLER_H
