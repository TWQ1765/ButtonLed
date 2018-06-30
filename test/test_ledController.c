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

void test_ledController_given_button_is_presses_expect_led_is_turned_on(void)
{
  int button;
  
  getButtonState_ExpectAndReturn(23);	//call form mock_Button.h line no.26
  
  button =  getButtonState(); 
  
  TEST_ASSERT_EQUAL(30,button);
}

void xtest_ledController_given_button_is_non_presses_expect_led_is_turned_off(void)
{
    
}