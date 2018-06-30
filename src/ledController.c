#include "ledController.h"
#include "led.h"
#include "Button.h"
#include <stdio.h>

void turnOnLedIfButtonIsPressed(void){
	
	if(getButtonState())
	{
		turnLed (LED_ON);
	}
	else {
		
		turnLed (LED_OFF);
	}
	
	
	
	
}