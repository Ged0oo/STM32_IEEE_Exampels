#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "LCD_interface.h"
#include "LED_interface.h"

extern RCC_Config_t RCC_obj;
extern ST_Keypad_t keypad_1;
extern chr_lcd_4bit_t lcd_1;

LED_ConfigType led_1 =
{
	.GPIO_pinX = GPIO_PIN_10,
	.GPIO_portX = GPIOA,
	.LED_state = LED_OFF
};

const uint8 customChar1[] = { 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F };
const uint8 customChar2[] = { 0x18, 0x07, 0x01, 0x01, 0x01, 0x01, 0x07, 0x18 };
const uint8 customChar3[] = { 0x1F, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1F };
const uint8 customChar4[] = { 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F };
const uint8 customChar5[] = { 0x18, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x18 };

int main(void)
{
	MRCC_voidClockInit(&RCC_obj);
	MRCC_voidPeripheralClockEnable(RCC_APB2_BUS , RCC_GPIOA_CLOCK);
	MRCC_voidPeripheralClockEnable(RCC_APB2_BUS , RCC_GPIOB_CLOCK);

	LED_vInit(&led_1);

	lcd_4bit_intialize(&lcd_1);

	lcd_4bit_send_string_pos(&lcd_1, 1, 2, "Itzz Happening");
	lcd_4bit_send_custom_char(&lcd_1, customChar3, 2, 1, 3);

	for(uint8 counter=2 ; counter<16 ; counter++)
		lcd_4bit_send_custom_char(&lcd_1, customChar1, 2, counter, 1);

	lcd_4bit_send_custom_char(&lcd_1, customChar2, 2, 16,2);

	while(1)
	{
		for(uint8 counter=1 ; counter<16 ; counter++)
		{
			LED_vToggle(&led_1);
			lcd_4bit_send_custom_char(&lcd_1, customChar4, 2, counter, 4);
			for(uint16 c=0;c<40000;c++) __asm volatile("NOP");
		}

		lcd_4bit_send_custom_char(&lcd_1, customChar5, 2, 16, 5);
		lcd_4bit_send_custom_char(&lcd_1, customChar3, 2, 1, 3);

		for(uint8 counter=2;counter<16;counter++)
		{
			LED_vToggle(&led_1);
			lcd_4bit_send_custom_char(&lcd_1, customChar1, 2, counter, 1);
			for(uint16 c=0;c<40000;c++) __asm volatile("NOP");
		}
		lcd_4bit_send_custom_char(&lcd_1, customChar2, 2, 16, 2);
	}
}
