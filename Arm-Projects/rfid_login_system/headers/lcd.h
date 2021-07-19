#ifndef _LCD_H
#define _LCD_H

//----------------------------------------//Function Prototypes
void lcd_init(void);
void enable(void);
void display_lcd(unsigned int signal, char ch);
void lcd_string(char *ch);

#endif
