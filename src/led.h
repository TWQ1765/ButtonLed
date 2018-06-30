#ifndef _LED_H
#define _LED_H

typedef enum{			// this commond doing...auto defining for next item
	LED_OFF, 			//0
	LED_ON,  			//1
						
} LedState;


void turnLed(LedState state);

#endif // _LED_H
