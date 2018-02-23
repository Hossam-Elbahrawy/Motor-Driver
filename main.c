
#include <avr/io.h>
#include "motor/motor.h"

int main(void)
{
		motor_init();

  	set_speed_right(50);
		set_speed_left(75);
		move_forward();
		//motor_stop();
		//move_right(128);
		//move_left(128);

  return 0;
}
