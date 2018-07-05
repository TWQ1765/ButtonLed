#ifndef _BUTTON_H
#define _BUTTON_H

typedef enum{	

	BUTTON_RELEASE,
	BUTTON_PRESSED, 
	
} ButtonState;

/**
 * Return non-zero if button is prassed, zero otherwise.
 */
ButtonState getButtonState(void);

#endif // _BUTTON_H
