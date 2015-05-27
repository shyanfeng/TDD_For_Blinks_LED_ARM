#include <stdio.h>
#include <unity.h>
#include "SD5.h"
#include "initState.h"
#include "mock_timeDelay.h"
#include "mock_pushButton1.h"

void setUp(void){}
void tearDown(void){}
/****************************************************************************
 *                                                                          *
 *                                                                          *
 *     Button Pressed then the state is at INITIAL and the ledStatus        *
 *     is still at OFF mode                                                 *
 *                                                                          *
 *                                                                          *
 ****************************************************************************/
void test_SD5_without_press_the_button_should_at_state_INITIAL_and_LED_OFF(void){
  ledSM led5 ={.state =INITIAL, .ledStatus = LED_ON}; 
  
  pushButton1_ExpectAndReturn(0);
  SD5(&led5);
  TEST_ASSERT_EQUAL(led5.state, INITIAL);
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF);

}
/****************************************************************************
 *                                                                          *
 *                                                                          *
 *     Button Pressing without let go then LED5 will blinking for 5 times   *
 *     and after that the LED will STOP blink and stay at case PRESS_CHECK  *
 *                                                                          *
 *                                                                          *
 ****************************************************************************/
void test_SD5_keep_press_the_button_should_blink_for_5_times_then_stop_blinking_at_PRESS_CHECK(void){
  ledSM led5 ={.state =INITIAL, .ledStatus = LED_ON}; 
  
  pushButton1_ExpectAndReturn(1);             // Button Pressed
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 at off mode
  TEST_ASSERT_EQUAL(led5.state, STATE_A);     // Button pressed will go to STATE_A
  
  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // First Blink ON
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_ON);  // LED5 will turn on
  TEST_ASSERT_EQUAL(led5.state, STATE_B);     // Button pressed will go to STATE_B
  
  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // First Blink OFF
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 will turn off
  TEST_ASSERT_EQUAL(led5.state, STATE_A);     // Button pressed will go to STATE_A
  
  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Second  Blink ON
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_ON);  // LED5 will turn on
  TEST_ASSERT_EQUAL(led5.state, STATE_B);     // Button pressed will go to STATE_B    
  
  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Second Blink OFF
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 will turn off
  TEST_ASSERT_EQUAL(led5.state, STATE_A);     // Button pressed will go to STATE_A
  
  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Third Blink ON
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_ON);  // LED5 will turn on
  TEST_ASSERT_EQUAL(led5.state, STATE_B);     // Button pressed will go to STATE_B

  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Third Blink OFF
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 will turn off
  TEST_ASSERT_EQUAL(led5.state, STATE_A);     // Button pressed will go to STATE_A  
  
  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Forth Blink ON
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_ON);  // LED5 will turn on
  TEST_ASSERT_EQUAL(led5.state, STATE_B);     // Button pressed will go to STATE_B

  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Forth Blink OFF
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 will turn off
  TEST_ASSERT_EQUAL(led5.state, STATE_A);     // Button pressed will go to STATE_A
 
  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Fifth Blink ON
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_ON);  // LED5 will turn on
  TEST_ASSERT_EQUAL(led5.state, STATE_B);     // Button pressed will go to STATE_B

  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Fifth Blink OFF
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 will turn off
  TEST_ASSERT_EQUAL(led5.state, PRESS_CHECK); // Button pressed will go to PRESS_CHECK
  
  pushButton1_ExpectAndReturn(1);             // Button Pressing
  SD5(&led5);                                 // Fifth Blink OFF
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 will remain off
  TEST_ASSERT_EQUAL(led5.state, PRESS_CHECK); // Button pressed will go to PRESS_CHECK
  
  pushButton1_ExpectAndReturn(1);             // Button Pressing
  SD5(&led5);                                 // Fifth Blink OFF
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 will remain off
  TEST_ASSERT_EQUAL(led5.state, PRESS_CHECK); // Button pressed will go to PRESS_CHECK

}

/****************************************************************************
 *                                                                          *
 *                                                                          *
 *     Button Pressing for 1 times then LED5 will blinking for 5 times      *
 *     and after that the LED will STOP blink and stay at case INITIAL      *
 *                                                                          *
 *                                                                          *
 ****************************************************************************/
void test_SD5_press_the_button_once_then_release_should_blink_for_5_times_then_stop_blinking_at_INITIAL(void){
  ledSM led5 ={.state =INITIAL, .ledStatus = LED_ON}; 
  
  pushButton1_ExpectAndReturn(1);             // Button Pressing
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 at off mode
  TEST_ASSERT_EQUAL(led5.state, STATE_A);     // Button pressed will go to STATE_A
  
  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // First Blink ON
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_ON);  // LED5 will turn on
  TEST_ASSERT_EQUAL(led5.state, STATE_B);     // Button pressed will go to STATE_B
  
  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // First Blink OFF
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 will turn off
  TEST_ASSERT_EQUAL(led5.state, STATE_A);     // Button pressed will go to STATE_A
  
  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Second  Blink ON
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_ON);  // LED5 will turn on
  TEST_ASSERT_EQUAL(led5.state, STATE_B);     // Button pressed will go to STATE_B    
  
  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Second Blink OFF
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 will turn off
  TEST_ASSERT_EQUAL(led5.state, STATE_A);     // Button pressed will go to STATE_A
  
  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Third Blink ON
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_ON);  // LED5 will turn on
  TEST_ASSERT_EQUAL(led5.state, STATE_B);     // Button pressed will go to STATE_B

  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Third Blink OFF
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 will turn off
  TEST_ASSERT_EQUAL(led5.state, STATE_A);     // Button pressed will go to STATE_A  
  
  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Forth Blink ON
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_ON);  // LED5 will turn on
  TEST_ASSERT_EQUAL(led5.state, STATE_B);     // Button pressed will go to STATE_B

  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Forth Blink OFF
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 will turn off
  TEST_ASSERT_EQUAL(led5.state, STATE_A);     // Button pressed will go to STATE_A
 
  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Fifth Blink ON
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_ON);  // LED5 will turn on
  TEST_ASSERT_EQUAL(led5.state, STATE_B);     // Button pressed will go to STATE_B

  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Fifth Blink OFF
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 will turn off
  TEST_ASSERT_EQUAL(led5.state, PRESS_CHECK); // Button pressed will go to PRESS_CHECK
  
  pushButton1_ExpectAndReturn(0);             // Button Not Press
  SD5(&led5); 
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 will turn off
  TEST_ASSERT_EQUAL(led5.state, INITIAL);     // Button pressed will go to INITIAL

}

/****************************************************************************
 *                                                                          *
 *                                                                          *
 *     Button Pressed for one times then LED5 will blinking for 5 times     *
 *     and after that release the LED will STOP blink and stay at case      *
 *     PRESS_CHECK  and without pressing and without pressing and then      *
 *     press the button then LED5 will blinking for 5 times and at state    *
 *     PRESS_CHECK                                                          *
 *                                                                          *
 *                                                                          *
 ****************************************************************************/
void test_SD5_keep_press_the_button_then_release_release_release_then_press(void){
  ledSM led5 ={.state =INITIAL, .ledStatus = LED_ON}; 
  
  pushButton1_ExpectAndReturn(1);             // Button Pressed
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 at off mode
  TEST_ASSERT_EQUAL(led5.state, STATE_A);     // Button pressed will go to STATE_A
  
  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // First Blink ON
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_ON);  // LED5 will turn on
  TEST_ASSERT_EQUAL(led5.state, STATE_B);     // Button pressed will go to STATE_B
  
  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // First Blink OFF
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 will turn off
  TEST_ASSERT_EQUAL(led5.state, STATE_A);     // Button pressed will go to STATE_A
  
  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Second  Blink ON
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_ON);  // LED5 will turn on
  TEST_ASSERT_EQUAL(led5.state, STATE_B);     // Button pressed will go to STATE_B    
  
  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Second Blink OFF
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 will turn off
  TEST_ASSERT_EQUAL(led5.state, STATE_A);     // Button pressed will go to STATE_A
  
  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Third Blink ON
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_ON);  // LED5 will turn on
  TEST_ASSERT_EQUAL(led5.state, STATE_B);     // Button pressed will go to STATE_B

  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Third Blink OFF
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 will turn off
  TEST_ASSERT_EQUAL(led5.state, STATE_A);     // Button pressed will go to STATE_A  
  
  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Forth Blink ON
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_ON);  // LED5 will turn on
  TEST_ASSERT_EQUAL(led5.state, STATE_B);     // Button pressed will go to STATE_B

  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Forth Blink OFF
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 will turn off
  TEST_ASSERT_EQUAL(led5.state, STATE_A);     // Button pressed will go to STATE_A
 
  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Fifth Blink ON
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_ON);  // LED5 will turn on
  TEST_ASSERT_EQUAL(led5.state, STATE_B);     // Button pressed will go to STATE_B

  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Fifth Blink OFF
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 will turn off
  TEST_ASSERT_EQUAL(led5.state, PRESS_CHECK); // Button pressed will go to PRESS_CHECK
  
  pushButton1_ExpectAndReturn(0);             // Button Not Press
  SD5(&led5); 
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 will turn off
  TEST_ASSERT_EQUAL(led5.state, INITIAL);     // Button pressed will go to INITIAL
  
  pushButton1_ExpectAndReturn(0);             // Button Not Press
  SD5(&led5); 
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 will turn off
  TEST_ASSERT_EQUAL(led5.state, INITIAL);     // Button pressed stay at INITIAL
  
  pushButton1_ExpectAndReturn(0);             // Button Not Press
  SD5(&led5); 
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 will turn off
  TEST_ASSERT_EQUAL(led5.state, INITIAL);     // Button pressed stay at INITIAL
  
  pushButton1_ExpectAndReturn(1);             // Button Pressed
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 at off mode
  TEST_ASSERT_EQUAL(led5.state, STATE_A);     // Button pressed will go to STATE_A
  
  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // First Blink ON
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_ON);  // LED5 will turn on
  TEST_ASSERT_EQUAL(led5.state, STATE_B);     // Button pressed will go to STATE_B
  
  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // First Blink OFF
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 will turn off
  TEST_ASSERT_EQUAL(led5.state, STATE_A);     // Button pressed will go to STATE_A
  
  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Second  Blink ON
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_ON);  // LED5 will turn on
  TEST_ASSERT_EQUAL(led5.state, STATE_B);     // Button pressed will go to STATE_B    
  
  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Second Blink OFF
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 will turn off
  TEST_ASSERT_EQUAL(led5.state, STATE_A);     // Button pressed will go to STATE_A
  
  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Third Blink ON
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_ON);  // LED5 will turn on
  TEST_ASSERT_EQUAL(led5.state, STATE_B);     // Button pressed will go to STATE_B

  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Third Blink OFF
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 will turn off
  TEST_ASSERT_EQUAL(led5.state, STATE_A);     // Button pressed will go to STATE_A  
  
  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Forth Blink ON
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_ON);  // LED5 will turn on
  TEST_ASSERT_EQUAL(led5.state, STATE_B);     // Button pressed will go to STATE_B

  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Forth Blink OFF
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 will turn off
  TEST_ASSERT_EQUAL(led5.state, STATE_A);     // Button pressed will go to STATE_A
 
  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Fifth Blink ON
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_ON);  // LED5 will turn on
  TEST_ASSERT_EQUAL(led5.state, STATE_B);     // Button pressed will go to STATE_B

  delay_ExpectAndReturn(200, 0, 1);
  getCurrentTime_ExpectAndReturn(150);
  SD5(&led5);                                 // Fifth Blink OFF
  TEST_ASSERT_EQUAL(led5.ledStatus, LED_OFF); // LED5 will turn off
  TEST_ASSERT_EQUAL(led5.state, PRESS_CHECK); // Button pressed will go to PRESS_CHECK

}
