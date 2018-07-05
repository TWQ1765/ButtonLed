#include "unity.h"
#include "ledController.h"
#include "mock_Button.h" 	//mock added
#include "mock_led.h"		//mock added

int turnLedCallNumbers = 0;
int expectedgetButtonStateMaxCalls = 0;
int expectTurnledMaxCalls = 0;
ButtonState *expectedbuttonState = NULL;
LedState *expectedLedState = NULL;

void setUp(void)
{
}

void tearDown(void)
{
}
//fake no
void fake_turnLed(LedState state, int NumCalls){
	turnLedCallNumbers++;
	if(NumCalls < expectTurnledMaxCalls){
		if(state != expectedLedState[NumCalls]){
			TEST_FAIL_MESSAGE("turnLed() was called ???,but expect ???");
		}
		else{
		TEST_FAIL_MESSAGE("turnLed() was called ???,but expect ???"); //trow error
		}
	}
}

ButtonState fake_getButtonState(int NumCalls){
	
	if(NumCalls < expectedgetButtonStateMaxCalls){
		return expectedButtomStates[NumCalls];	
	}else
		TEST_FAIL_MESSAGE("Received extra getButtonState() calls");
}

void setupFake(LedState expLedStates[], int ledMaxCalls, ButtonState buttStates[], int buttonMaxCalls){
	turnLedCallNumbers = 0;
	turnLed_StubWithCallback(fake_turnLed);
	expectedLedState = expLedStates;
	expectTurnledMaxCalls = ledMaxCalls;
	getButtonState_StubWithCallback(fake_getButtonState);
	expectedButtomStates = buttStates;
	expectedgetButtonStateMaxCalls = buttonMaxCalls;
}

void verifyTurnOnLedCalls(int numCalls){
	if(turnLedCallNumbers != numCalls){
		TEST_FAIL_MESSAGE("turnLed() was not call at all. But 1 call is expected.");
	}
}


void test_dotapTurnOntapTurnOffLed_given_led_is_off_and_is_presses_and_relese_expect_led_to_turned_on(void)
{
	LedButtonInfo info = {LED_OFF, BUTTON_RELEASE}; //initial state
	LedState expectedLedState[] = {LED_ON};
	ButtonStates expectedButtomStates[]= {BUTTON_RELEASE,BUTTON_PRESSED,BUTTON_RELEASE};
	
	setupFake(expectedLedState, 1,buttonStates, 3);
	
	dotapTurnOntapTurnOffLed(&info);	
	dotapTurnOntapTurnOffLed(&info);
	dotapTurnOntapTurnOffLed(&info);
	
    verifyTurnOnLedCalls(1);
  
	TEST_ASSERT_EQUAL(LED_ON, info.currentLedState);
}

void test_dotapTurnOntapTurnOffLed_given_led_is_on_and_is_presses_and_relese_expect_led_to_turned_off(void)
{
	LedButtonInfo info = {LED_ON, BUTTON_RELEASE}; //initial state
	LedState expectedLedState[] = {LED_OFF};
	ButtonStates expectedButtomStates[]= {BUTTON_RELEASE,BUTTON_PRESSED,BUTTON_RELEASE};
	
	setupFake(expectedLedState, 1,buttonStates, 3);
	
	dotapTurnOntapTurnOffLed(&info);	
	dotapTurnOntapTurnOffLed(&info);
	dotapTurnOntapTurnOffLed(&info);
	
    verifyTurnOnLedCalls(1);
	TEST_ASSERT_EQUAL(LED_OFF,info.currentLedState);
}
/*
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

void test_dotapTurnOntapTurnOffLed_given_led_is_off_and_is_presses_and_relese_and_presses_and_relese_expect_led_to_turned_off(void)
{
	LedButtonInfo info = {LED_OFF, BUTTON_RELEASE}; //initial state
	
	//open led situaltion//
	getButtonState_ExpectAndReturn(BUTTON_RELEASE); 
	dotapTurnOntapTurnOffLed(&info);	
	getButtonState_ExpectAndReturn(BUTTON_PRESSED);
	turnLed_Expect(LED_ON);
	dotapTurnOntapTurnOffLed(&info);
	getButtonState_ExpectAndReturn(BUTTON_RELEASE);
	dotapTurnOntapTurnOffLed(&info);
	//situaltion END//
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

void test_dotapTurnOntapTurnOffLed_given_led_is_on_and_is_presses_and_relese_and_presses_and_relese_expect_led_to_turned_on(void)
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
    //open led situaltion//
	getButtonState_ExpectAndReturn(BUTTON_RELEASE); 
	dotapTurnOntapTurnOffLed(&info);	
	getButtonState_ExpectAndReturn(BUTTON_PRESSED);
	turnLed_Expect(LED_ON);
	dotapTurnOntapTurnOffLed(&info);
	getButtonState_ExpectAndReturn(BUTTON_RELEASE);
	dotapTurnOntapTurnOffLed(&info);
	//situaltion END//
  
	TEST_ASSERT_EQUAL(LED_ON, info.currentLedState);
}

void test_dotapTurnOntapTurnOffLed_given_led_is_off_and_is_relese_and_presses_and_presses_expect_led_to_turned_on(void)
{
	LedButtonInfo info = {LED_OFF, BUTTON_RELEASE}; //initial state
	
	
	getButtonState_ExpectAndReturn(BUTTON_PRESSED);
	turnLed_Expect(LED_ON);	
	dotapTurnOntapTurnOffLed(&info);	
	getButtonState_ExpectAndReturn(BUTTON_PRESSED);
	dotapTurnOntapTurnOffLed(&info);
	getButtonState_ExpectAndReturn(BUTTON_PRESSED);
	dotapTurnOntapTurnOffLed(&info);
	
	TEST_ASSERT_EQUAL(LED_ON, info.currentLedState);
}

void test_dotapTurnOntapTurnOffLed_given_led_is_on_and_is_relese__random_test_to_turned_off(void)
{
	LedButtonInfo info = {LED_ON, BUTTON_RELEASE}; //initial BUTTON_PRESSED & LED_ON cant do.
	
	
	getButtonState_ExpectAndReturn(BUTTON_RELEASE);
	dotapTurnOntapTurnOffLed(&info);	
	getButtonState_ExpectAndReturn(BUTTON_RELEASE);
	dotapTurnOntapTurnOffLed(&info);
	getButtonState_ExpectAndReturn(BUTTON_RELEASE);
	dotapTurnOntapTurnOffLed(&info);
	getButtonState_ExpectAndReturn(BUTTON_PRESSED);
	dotapTurnOntapTurnOffLed(&info);
	getButtonState_ExpectAndReturn(BUTTON_RELEASE);
	turnLed_Expect(LED_OFF);
	dotapTurnOntapTurnOffLed(&info);
	getButtonState_ExpectAndReturn(BUTTON_RELEASE);
	dotapTurnOntapTurnOffLed(&info);
	getButtonState_ExpectAndReturn(BUTTON_RELEASE);
	dotapTurnOntapTurnOffLed(&info);
	getButtonState_ExpectAndReturn(BUTTON_PRESSED);
	turnLed_Expect(LED_ON);
	dotapTurnOntapTurnOffLed(&info);
	getButtonState_ExpectAndReturn(BUTTON_RELEASE);
	dotapTurnOntapTurnOffLed(&info);
	getButtonState_ExpectAndReturn(BUTTON_RELEASE);
	dotapTurnOntapTurnOffLed(&info);
	getButtonState_ExpectAndReturn(BUTTON_PRESSED);
	dotapTurnOntapTurnOffLed(&info);
	getButtonState_ExpectAndReturn(BUTTON_PRESSED);
	dotapTurnOntapTurnOffLed(&info);
	getButtonState_ExpectAndReturn(BUTTON_PRESSED);
	dotapTurnOntapTurnOffLed(&info);
	getButtonState_ExpectAndReturn(BUTTON_PRESSED);
	dotapTurnOntapTurnOffLed(&info);
	getButtonState_ExpectAndReturn(BUTTON_RELEASE);
	turnLed_Expect(LED_OFF);
	dotapTurnOntapTurnOffLed(&info);
	
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
*/