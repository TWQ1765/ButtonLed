#include "unity.h"
#include "ledController.h"
#include "mock_Button.h" 	//mock added
#include "mock_led.h"		//mock added
void setUp(void)
{
}

void tearDown(void)
{
}

void test_dotapTurnOntapTurnOffLed_given_led_is_off_and_is_presses_and_relese_expect_led_to_turned_on(void)
{
	LedButtonInfo info = {LED_OFF, BUTTON_RELEASE}; //initial state
	
	//open led situaltion//
	getButtonState_ExpectAndReturn(BUTTON_RELEASE); //
	dotapTurnOntapTurnOffLed(&info);	// led off ,button rel
	getButtonState_ExpectAndReturn(BUTTON_PRESSED);
	turnLed_Expect(LED_ON);
	dotapTurnOntapTurnOffLed(&info);
	getButtonState_ExpectAndReturn(BUTTON_RELEASE);
	dotapTurnOntapTurnOffLed(&info);
	//situaltion END//
  
  
	TEST_ASSERT_EQUAL(LED_ON, info.currentLedState);
}

void test_dotapTurnOntapTurnOffLed_given_led_is_on_and_is_presses_and_relese_expect_led_to_turned_off(void)
{
	LedButtonInfo info = {LED_ON, BUTTON_RELEASE}; //initial state
	
	//off led situaltion//
	getButtonState_ExpectAndReturn(BUTTON_RELEASE);
	dotapTurnOntapTurnOffLed(&info);
	getButtonState_ExpectAndReturn(BUTTON_PRESSED);
	dotapTurnOntapTurnOffLed(&info);
	getButtonState_ExpectAndReturn(BUTTON_RELEASE);
	turnLed_Expect(LED_OFF);
	dotapTurnOntapTurnOffLed(&info);
	//situaltion END//
  
  
	TEST_ASSERT_EQUAL(LED_OFF, info.currentLedState);
}

void test_turnOnLedIfButtonIsPressed_given_button_is_presses_and_relese_expect_led_is_turned_on(void)
{
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);	
  turnLed_Expect(LED_ON);
  
  turnOnLedIfButtonIsPressed();
}

void test_turnOnLedIfButtonIsPressed_given_button_is_presses_and_relese_expect_led_is_turned_off(void)
{
  getButtonState_ExpectAndReturn(BUTTON_RELEASE);	
  turnLed_Expect(LED_OFF);
  
  turnOnLedIfButtonIsPressed();
}