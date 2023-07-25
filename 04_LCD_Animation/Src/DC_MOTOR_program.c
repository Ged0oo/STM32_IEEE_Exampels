/* 
 * File:   DC_MOTOR_PROGRAM.c
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on April 25, 2023, 8:41 PM
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DC_MOTOR_interface.h"



void dc_motor_initialize(dc_motor_t *_dc_motor)
{
    if(NULL == _dc_motor)
	{
        return;
    }
    else
	{
    	_dc_motor->motor_pin[0].GPIO_PinMode = GPIO_PIN_GENERAL_PURPOSE_OUTPUT_PUSHPULL_MODE_10MHZ;
    	_dc_motor->motor_pin[1].GPIO_PinMode = GPIO_PIN_GENERAL_PURPOSE_OUTPUT_PUSHPULL_MODE_10MHZ;
    	_dc_motor->motor_pin[0].GPIO_Logic = GPIO_LOW;
    	_dc_motor->motor_pin[1].GPIO_Logic = GPIO_LOW;
    	GPIO_voidInitPortPin(&(_dc_motor->motor_pin[0]));
    	GPIO_voidInitPortPin(&(_dc_motor->motor_pin[1]));
    }
}


void dc_motor_move_right(dc_motor_t *_dc_motor)
{
    if(NULL == _dc_motor)
	{
        return;
    }
    else
	{
    	GPIO_voidWritePortPin(&(_dc_motor->motor_pin[0]), GPIO_HIGH);
    	GPIO_voidWritePortPin(&(_dc_motor->motor_pin[1]), GPIO_LOW);
	}
}


void dc_motor_move_left(dc_motor_t *_dc_motor)
{
    if(NULL == _dc_motor)
	{
        return;
    }
    else
	{
    	GPIO_voidWritePortPin(&(_dc_motor->motor_pin[0]), GPIO_LOW);
    	GPIO_voidWritePortPin(&(_dc_motor->motor_pin[1]), GPIO_HIGH);
	}
}


void dc_motor_stop(dc_motor_t *_dc_motor)
{
    if(NULL == _dc_motor)
	{
        return;
    }
    else
	{
    	GPIO_voidWritePortPin(&(_dc_motor->motor_pin[0]), GPIO_LOW);
    	GPIO_voidWritePortPin(&(_dc_motor->motor_pin[1]), GPIO_LOW);
	}
}


