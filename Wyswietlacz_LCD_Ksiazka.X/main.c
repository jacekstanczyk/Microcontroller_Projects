/**************************************************************
   Schemat podłączeń programowanego układu

                 +----v----+
           MCLR [| 1     40|] 
                [| 2     39|] 
                [| 3     38|] RB5 -> RS_LCD
                [| 4     37|] RB4 -> EN_LCD
                [| 5     36|] 
                [| 6     35|] 
                [| 7     34|] 
                [| 8     33|] 
                [| 9     32|] VDD
                [|10     31|] VSS
            VDD [|11     30|] 
            VSS [|12     29|] 
(20 MHz) / OSC1 [|13     28|]
         \ OSC2 [|14     27|]
                [|15     26|] 
                [|16     25|] 
                [|17     24|] RC5 -> DB4_LCD
                [|18     23|] RC4 -> DB5_LCD
                [|19     22|] RD3 -> DB6_LCD
                [|20     21|] RD2 -> DB7_LCD
                 +---------+
                 PIC16F877A
***************************************************************/

//definiujemy szybkość oscylatora dla funkcji __delay_
#define _XTAL_FREQ 20000000
#include <htc.h>
#include <stdlib.h>

#define TRIS_RS_LCD   TRISBbits.TRISB2
#define TRIS_EN_LCD   TRISBbits.TRISB3
#define TRIS_DB4_LCD  TRISBbits.TRISB4
#define TRIS_DB5_LCD  TRISBbits.TRISB5
#define TRIS_DB6_LCD  TRISBbits.TRISB6
#define TRIS_DB7_LCD  TRISBbits.TRISB7

#define RS_LCD   PORTBbits.RB2
#define EN_LCD   PORTBbits.RB3
#define DB4_LCD  PORTBbits.RB4
#define DB5_LCD  PORTBbits.RB5
#define DB6_LCD  PORTBbits.RB6
#define DB7_LCD  PORTBbits.RB7

#include "lcd.h"

//oscylator szybszy od 10 MHz (FOSC_HS)
//watchdog wyłączony (WDTE_OFF)
//wyłączone LVP (Low-Voltage ICSP Programming) (LVP_OFF)
__CONFIG(FOSC_HS & WDTE_OFF & LVP_OFF);

char napis1[] = "Odliczanie:";
char napis2[] = "Detonacja!";
char bufor[2];

void main()
{
	unsigned char i;
	ADCON1 = 0x06;				//wyłączenie linii analogowych 
                    			//(wszystkie linie cyfrowe)
	WlaczLCD();					//inicjalizacja wyświetlacza LCD
	UstawKursorLCD(1, 2);		//wiersz 1 kolumna 2
	WyswietlLCD(napis1, 11);	//wyświetl napis

	for(i=9; i>0; i--)
	{
		utoa(bufor, i, 10);		//konwersja liczby na napis
		UstawKursorLCD(1,15);	//wiersz 1 kolumna 15
		WyswietlLCD(bufor, 1);	//wyświetl napis
		__delay_ms(1000);		//zaczekaj 1 s
	}

	UstawKursorLCD(2, 4);		//wiersz 2 kolumna 4
	WyswietlLCD(napis2, 10);	//wyświetl napis

	for(;;)				//pętla nieskończona
	{

	}
}

