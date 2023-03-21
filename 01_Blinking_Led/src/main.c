/*
 * File:   main.c
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on March 12, 2023, 8:41 PM
 */

#include "RCC_interface.h"
#include "GPIO_interface.h"


RCC_Config_t RCC_obj =
{
	.ClockSource = RCC_HSE,
	.Prescaler.ABP1_Prescaler = APB1_NOT_DEVIDED,
	.Prescaler.ABP2_Prescaler = APB2_NOT_DEVIDED,
	.Prescaler.AHB_Prescaler  = AHB_NOT_DEVIDED
};



void main(void)
{
	RCC_voidPeripheralClockEnable(RCC_APB2_BUS , RCC_GPIOA_CLOCK);
	RCC_voidClockInit(&RCC_obj);

	GPIO_voidInitPortPin(GPIOA , GPIO_PIN_1 , GPIO_PIN_OUTPUT_OPENDRAIN_MODE_2MHZ);
	GPIO_voidInitPortPin(GPIOA , GPIO_PIN_2 , GPIO_PIN_OUTPUT_OPENDRAIN_MODE_2MHZ);
	GPIO_voidInitPortPin(GPIOA , GPIO_PIN_3 , GPIO_PIN_OUTPUT_OPENDRAIN_MODE_2MHZ);

	while(1)
	{
		GPIO_voidWritePortPin(GPIOA , GPIO_PIN_1 , GPIO_HIGH);
		GPIO_voidWritePortPin(GPIOA , GPIO_PIN_2 , GPIO_LOW);
		GPIO_voidWritePortPin(GPIOA , GPIO_PIN_3 , GPIO_LOW);
		for(uint32 i=0 ; i<1000000 ; i++);

		GPIO_voidWritePortPin(GPIOA , GPIO_PIN_1 , GPIO_LOW);
		GPIO_voidWritePortPin(GPIOA , GPIO_PIN_2 , GPIO_HIGH);
		GPIO_voidWritePortPin(GPIOA , GPIO_PIN_3 , GPIO_LOW);
		for(uint32 i=0 ; i<1000000 ; i++);

		GPIO_voidWritePortPin(GPIOA , GPIO_PIN_1 , GPIO_LOW);
		GPIO_voidWritePortPin(GPIOA , GPIO_PIN_2 , GPIO_LOW);
		GPIO_voidWritePortPin(GPIOA , GPIO_PIN_3 , GPIO_HIGH);
		for(uint32 i=0 ; i<1000000 ; i++);
	}
}

