#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "DC_MOTOR_interface.h"


RCC_Config_t RCC_obj =
{
	.ClockSource = RCC_HSE,
	.Prescaler.ABP1_Prescaler = APB1_NOT_DEVIDED,
	.Prescaler.ABP2_Prescaler = APB2_NOT_DEVIDED,
	.Prescaler.AHB_Prescaler  = AHB_NOT_DEVIDED
};


dc_motor_t motor_1 =
{
	.motor_pin[0].GPIOx = GPIOA,
	.motor_pin[0].GPIO_PinNumber = GPIO_PIN_10,
	.motor_pin[1].GPIOx = GPIOA,
	.motor_pin[1].GPIO_PinNumber = GPIO_PIN_11,
};

dc_motor_t motor_2 =
{
	.motor_pin[0].GPIOx = GPIOA,
	.motor_pin[0].GPIO_PinNumber = GPIO_PIN_12,
	.motor_pin[1].GPIOx = GPIOA,
	.motor_pin[1].GPIO_PinNumber = GPIO_PIN_13,
};


int main(void)
{
	MRCC_voidClockInit(&RCC_obj);
	MRCC_voidPeripheralClockEnable(RCC_APB2_BUS , RCC_GPIOA_CLOCK);
	dc_motor_initialize(&motor_1);
	dc_motor_initialize(&motor_2);
	while(1)
	{
		dc_motor_move_right(&motor_1);
		dc_motor_move_right(&motor_2);
		for(uint32 i=0 ; i<100000 ; i++);

		dc_motor_move_left(&motor_1);
		dc_motor_move_left(&motor_2);
		for(uint32 i=0 ; i<100000 ; i++);

		dc_motor_stop(&motor_1);
		dc_motor_stop(&motor_2);
		for(uint32 i=0 ; i<100000 ; i++);
	}
}
