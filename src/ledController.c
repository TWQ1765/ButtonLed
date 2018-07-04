#include "ledController.h"
#include "led.h"
#include "Button.h"
#include <stdio.h>

#define SITUATION_LED_OFF 0;
#define SITUATION_LED_ON 1;

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
	
 int currentButton = getButtonState();
 int situation;

 switch (state->currentLedState){
	 
	 case LED_OFF:
	 if ((state->previousButtonState == currentButton) && (currentButton == BUTTON_RELEASE)){
		 state->currentLedState = LED_OFF;
		 state->previousButtonState = currentButton;
	 }
	 else if(state->previousButtonState != currentButton){
		 state->currentLedState = LED_ON;
		 state->previousButtonState = currentButton;
		 situation = SITUATION_LED_OFF;
		 turnLed(LED_ON);
	 }
	 else{state->currentLedState = LED_OFF;}
	 break;
	 
	 case LED_ON:
	  
	  if ((state->previousButtonState != currentButton) && (currentButton == BUTTON_PRESSED)){
		 state->currentLedState = LED_ON;
		 state->previousButtonState = currentButton;
		 situation = SITUATION_LED_ON;		 
	  }
	  else if((state->previousButtonState == currentButton) && (currentButton == BUTTON_RELEASE)){
		 state->currentLedState = LED_ON;
		 state->previousButtonState = currentButton;
	  }
	  else if((state->previousButtonState == currentButton) && (currentButton == BUTTON_PRESSED)){
		 state->currentLedState = LED_ON;
		 state->previousButtonState = currentButton;
	  }
	  else if ((state->previousButtonState != currentButton) && (currentButton == BUTTON_RELEASE)){
		 switch (situation){
			 case 0:
					state->currentLedState = LED_ON;
					state->previousButtonState = currentButton;
					situation = SITUATION_LED_ON;
			 break;
			 case 1:
					state->currentLedState = LED_OFF;
					state->previousButtonState = currentButton;
					turnLed(LED_OFF);
			 break;
			 default:{state->currentLedState = LED_OFF;}
		 }
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