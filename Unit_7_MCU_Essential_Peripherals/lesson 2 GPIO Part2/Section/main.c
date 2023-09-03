#include "Lcd/lcd.h"
#include "Keypad/keypad.h"

int main()
{
	LCD_INIT();
	Keypad_init();
	_delay_ms(50);
	unsigned char key_pressed;
	int charCount = 0; // To track the number of characters displayed on the first line

	while (1) {
		key_pressed = Keypad_getkey();

		switch (key_pressed) {
			case 'A':
			break;
			case '?':
			LCD_clear_screen();
			charCount = 0; // Reset character count when clearing the screen
			break;
			default:
			if (charCount >= 16) {
				// First line is full, switch to the second line
				LCD_GOTO_XY(2, 0);
			}
			LCD_WRITE_CHAR(key_pressed);
			charCount++;
			break;
		}
	}
}
