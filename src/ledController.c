#include "ledController.h"
#include "led.h"
#include "Button.h"
#include <stdio.h>

void turnOnLedIfButtonIsPressed(void){ //not put while loop here
	
	if(getButtonState())
	{
		turnLed (LED_ON);
	}
	else {
		
		turnLed (LED_OFF);
	}
	
}
void dotapTurnOntapTurnOffLed(LedButtonInfo *state){ 
	/*
	int currentButton = getButtonState();
	
	if(state->currentLedState == LED_OFF){

		switch (currentButton){
		
			case BUTTON_RELEASE:
			if(currentButton == state->previousButtonState){
				state->previousButtonState = BUTTON_RELEASE;
				state->currentLedState = LED_OFF;
				//turnLed(LED_OFF);
			}
			else{
				state->previousButtonState = BUTTON_PRESSED;
				state->currentLedState = LED_ON;
				turnLed(LED_ON);
			}		
			break;
		
			case BUTTON_PRESSED:
			if (currentButton == state->previousButtonState){
				state->previousButtonState = BUTTON_PRESSED;
				state->currentLedState = LED_ON;
				//turnLed(state->currentLedState);
			}
			else{
				state->previousButtonState = BUTTON_RELEASE;
				state->currentLedState = LED_ON;
				//turnLed(state->currentLedState);
				//turnLed(LED_ON);
			}		
			break;
		
			default:
				state->currentLedState = LED_OFF;
				//turnLed(LED_OFF);
	}
	
}

	else {//if((state->currentLedState) == LED_ON){
		switch (currentButton){
		
			case BUTTON_RELEASE:
			if(currentButton == state->previousButtonState){
				state->previousButtonState = BUTTON_RELEASE;
				state->currentLedState = LED_OFF;
				turnLed(state->currentLedState);
			}
			else{
				state->previousButtonState = BUTTON_PRESSED;
				state->currentLedState = LED_ON;
				//turnLed(LED_ON);
			}		
			break;
		
			case BUTTON_PRESSED:
			if (currentButton == state->previousButtonState){
				state->previousButtonState = BUTTON_PRESSED;
				state->currentLedState = LED_ON;
				//turnLed(LED_ON);
			}
			else{
				state->previousButtonState = BUTTON_RELEASE;
				state->currentLedState = LED_OFF;
				//turnLed(LED_OFF);
			}		
			break;
		
			default:
			state->currentLedState = LED_ON;
			//turnLed(LED_ON);
	}
}	
	//turnLed(state->currentLedState);
	//*/
 int currentButton = getButtonState();
 
 switch (state->currentLedState){
	 
	 case LED_OFF :
	 if (state->previousButtonState == currentButton){
		 state->currentLedState = LED_OFF;
		 state->previousButtonState = currentButton;
	 }
	 else if(state->previousButtonState != currentButton){
		 state->currentLedState = LED_ON;
		 state->previousButtonState = currentButton;
		 turnLed(LED_ON);
	 }
	 else{state->currentLedState = LED_OFF;}
	 break;
	 case LED_ON :
	  if (state->previousButtonState != currentButton){
		 state->currentLedState = LED_ON;
		 state->previousButtonState = currentButton;
	 }
	 else if(state->previousButtonState == currentButton){
		 state->currentLedState = LED_OFF;
		 state->previousButtonState = currentButton;
		 turnLed(LED_OFF);
	 }
	 else{state->currentLedState = LED_OFF;}
	 
	 break;
	 default:{state->currentLedState = LED_OFF;}
	 
 }
	 
	 
}

	

void doTrunOnLedOnButtonPressesAndHoldController(){	//just make it simple 
	while(1) {
		turnOnLedIfButtonIsPressed();
	}
}
	
void doTapTapLedContoller(){
	LedState currentLedState;
	while(1){
		//tapTurnOntapTurnOffLed(&currentLedState);
	}
}	