#define _XTAL_FREQ 4000000 //oscylator na płytce eval ZL 4PIC 4Mh


#include <htc.h>
#include <stdlib.h>
#include "lcd.h"

__CONFIG(FOSC_HS & WDTE_OFF & LVP_OFF);

char napis1[] = "Odliczanie:";
char napis2[] = "Detonacja!";
char bufor[4];


void main()
{
	ADCON1 = 0x06;
    
    __delay_ms(1000);
    
    WlaczLCD();
    UstawKursorLCD(1,2);
    WyswietlLCD(napis1,11);
    
    for(;;){
        
        WyswietlLCD("          ", 10);
        
        for(unsigned int i = 9999; i > 0 ; i--){
            utoa(bufor, i , 10);

            if (i < 10000 && i > 999){
                UstawKursorLCD(1,13);
                WyswietlLCD(bufor, 4);
            }
            else
            if (i < 1000 && i > 99){
                UstawKursorLCD(1,13);
                WyswietlLCD(" ", 1);
                UstawKursorLCD(1,14);
                WyswietlLCD(bufor, 3);
            }
            else
            if (i < 100 && i > 9){
                UstawKursorLCD(1,13);
                WyswietlLCD("  ", 2);
                UstawKursorLCD(1,15);
                WyswietlLCD(bufor, 2);
            }
            else
            if (i < 10){
                UstawKursorLCD(1,13);
                WyswietlLCD("   ", 3);
                UstawKursorLCD(1,16);
                WyswietlLCD(bufor, 1);
            }   

            __delay_ms(10);
        }

        UstawKursorLCD(2,4);
        WyswietlLCD(napis2, 10);
    
     }
    
}
