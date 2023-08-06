#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "KEYPAD_interface.h"
#include "LCD_interface.h"

extern RCC_Config_t RCC_obj;
extern ST_Keypad_t keypad_1;
extern chr_lcd_4bit_t lcd_1;

int main(void)
{
	MRCC_voidClockInit(&RCC_obj);
	MRCC_voidPeripheralClockEnable(RCC_APB2_BUS , RCC_GPIOA_CLOCK);
	MRCC_voidPeripheralClockEnable(RCC_APB2_BUS , RCC_GPIOB_CLOCK);

	keypad_initialize(&keypad_1);
	lcd_4bit_intialize(&lcd_1);
	uint8 keypadVal = NOTPRESSED;

	lcd_4bit_send_string(&lcd_1, "system init");
	for(uint32 i=0 ; i<100000 ; i++);
	LCD_Clear(&lcd_1);
	for(uint32 i=0 ; i<100000 ; i++);

	while(1)
	{
		keypadVal = NOTPRESSED;
		keypadVal = read_keypad(&keypad_1);
		if(keypadVal != NOTPRESSED)
		{
			LCD_WriteNumber(keypadVal-'0');
			for(uint32 i=0 ; i<1000 ; i++);
		}
	}
}
