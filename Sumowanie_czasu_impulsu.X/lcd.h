/* 
 * File:   lcd.h
 * Author: placek
 *
 * Created on 21 września 2017, 20:44
 */

#ifndef LCD_H
#define	LCD_H

#define _XTAL_FREQ 4000000 //oscylator na płytce eval ZL 4PIC 4Mh
#include <htc.h>

#define TRIS_RS_LCD TRISBbits.TRISB2
#define TRIS_EN_LCD TRISBbits.TRISB3
#define TRIS_DB4_LCD TRISBbits.TRISB4
#define TRIS_DB5_LCD TRISBbits.TRISB5
#define TRIS_DB6_LCD TRISBbits.TRISB6
#define TRIS_DB7_LCD TRISBbits.TRISB7

#define RS_LCD PORTBbits.RB2
#define EN_LCD PORTBbits.RB3
#define DB4_LCD PORTBbits.RB4
#define DB5_LCD PORTBbits.RB5
#define DB6_LCD PORTBbits.RB6
#define DB7_LCD PORTBbits.RB7

void Wyslij_do_LCD(unsigned char bajt);
void CzyscLCD();
void WlaczLCD();
void WyswietlLCD(char * napis, unsigned char ile);
void UstawKursorLCD(unsigned char y, unsigned char x);


#endif	/* LCD_H */

