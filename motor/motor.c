#include "motor.h"

/*********************************************************************
* Function    : PWM_init(uint8_t);
*
* DESCRIPTION : Initializes the Motor output pins and the PWM in fast mode.
*
* PARAMETERS  : Nothing.
*
* Return Value: Nothing
***********************************************************************/
 void motor_init()
 {
 DDRB |= (1<<PB0);
 DDRB |= (1<<PB1);

 DDRA |= (1<<PA0);
 DDRA |= (1<<PA1);

PWM_init(TIMER_0);
PWM_init(TIMER_2);

 }

 /*********************************************************************
 * Function    : move_forward(void);
 *
 * DESCRIPTION : Sets the direction in clockwise direction.
 *
 * PARAMETERS  : Nothing.
 *
 * Return Value: Nothing
 ***********************************************************************/
 void move_forward()
 {

	 PORTA |= (1<<PA0);
	 PORTA &= (~(1<<PA1));

	 PORTB |= (1<<PB0);
	 PORTB &= (~(1<<PB1));

 }

 /*********************************************************************
 * Function    : move_backward();
 *
 * DESCRIPTION : Sets the direction in counter clockwise direction.
 *
 * PARAMETERS  : Nothing.
 *
 * Return Value: Nothing
 ***********************************************************************/
  void move_backward()
  {
	    PORTA |= (1<<PA1);
	    PORTA &= (~(1<<PA0));

	    PORTB |= (1<<PB1);
	    PORTB &= (~(1<<PB0));

  }

  /*********************************************************************
  * Function    : set_speed_left(uint8_t speed);
  *
  * DESCRIPTION : Changes the DutyCycle on TIMER_0 .
  *
  * PARAMETERS  : uint8_t speed sets A value to the DutyCycle
  *                between 0 (0 %) and 255 (100 %).
  *
  * Return Value: Nothing
  ***********************************************************************/
  void set_speed_left (uint8_t speed)
  {
	  PWM_SetDutyCycle( speed, TIMER_0);
  }

  /*********************************************************************
  * Function    : set_speed_right(uint8_t speed);
  *
  * DESCRIPTION : Changes the DutyCycle on TIMER_2 .
  *
  * PARAMETERS  : uint8_t speed sets A value to the DutyCycle
  *                between 0 (0 %) and 255 (100 %).
  *
  * Return Value: Nothing
  ***********************************************************************/
  void set_speed_right (uint8_t speed)
  {
	  PWM_SetDutyCycle( speed, TIMER_2);
  }

  /*********************************************************************
  * Function    : move_right(uint8_t speed);
  *
  * DESCRIPTION : Moves to the rigth by stoping the right motor and
  *               running the left motor to some speed
  *
  * PARAMETERS  : uint8_t speed_left sets A value to the DutyCycle
  *                between 0 (0 %) and 255 (100 %).
  *
  * Return Value: Nothing
  ***********************************************************************/
   void move_right(uint8_t speed_left)
   {
	    set_speed_right(0);
		  set_speed_left(speed_left);

   }

   /*********************************************************************
   * Function    : move_left(uint8_t speed);
   *
   * DESCRIPTION : Moves to the left by stoping the left motor(0) and
   *               running the right motor to some speed
   *
   * PARAMETERS  : uint8_t speed_right sets A value to the DutyCycle
   *                between 0 (0 %) and 255 (100 %).
   *
   * Return Value: Nothing
   ***********************************************************************/
    void move_left(uint8_t speed_right)
    {
      set_speed_right(speed_right);
	    set_speed_left(0);

    }

    /*********************************************************************
    * Function    : motor_stop();
    *
    * DESCRIPTION : stoping both the left and the right motors.
    *
    * PARAMETERS  : Nothing
    *
    * Return Value: Nothing
    ***********************************************************************/
	 void motor_stop()
	 {
     set_speed_left(0);
     set_speed_right(0);
	 }
