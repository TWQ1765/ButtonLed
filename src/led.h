#ifndef _LED_H
#define _LED_H

typedef enum{			// this commond doing...auto defining for next item
	LED_OFF = 10, 		//10
	LED_UNKOWN,			//11
	LED_ON	= 20,  		//20 ...
						//21 ... for next item
} LedState;


void turnOnLed(LedState state);

#endif // _LED_H
