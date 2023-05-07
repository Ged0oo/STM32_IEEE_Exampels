#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "KEYPAD_interface.h"
#include "LCD_interface.h"
#include "LED_interface.h"

extern RCC_Config_t RCC_obj;
extern ST_Keypad_t keypad_1;
extern chr_lcd_4bit_t lcd_1;

LED_ConfigType led_1 =
{
		.GPIO_portX = GPIOB,
		.LED_state = GPIO_HIGH,
		.GPIO_pinX = GPIO_PIN_1
};

int main(void)
{
	char str[] = "HELLO_WORLD";

	MRCC_voidClockInit(&RCC_obj);
	MRCC_voidPeripheralClockEnable(RCC_APB2_BUS , RCC_GPIOA_CLOCK);
	MRCC_voidPeripheralClockEnable(RCC_APB2_BUS , RCC_GPIOB_CLOCK);

	lcd_4bit_intialize(&lcd_1);
	lcd_4bit_send_string(&lcd_1, (uint8 *)str);
	LCD_WriteNumber_Position(270, 2, 1);

	//uint8 counter = 0;
	while(1)
	{
		//for(uint32 i=0 ; i<100000 ; i++);
		//counter++;
	}
}
