#define _XTAL_FREQ 4000000 //oscylator na płytce eval ZL 4PIC 4Mh


#include <htc.h>
#include <stdlib.h> //ultoa
#include <string.h> //strlen
#include "lcd.h"

__CONFIG(FOSC_HS & WDTE_OFF & LVP_OFF);

char napis0[] = "Wcisnij S1";
char napis1[] = "Trwa pomiar...";
char napis2[] = "Wynik:";
char napisw[11];

unsigned long int czas;
unsigned long int czas_wzorcowy;
unsigned int wypelniacz;


void main()
{
	ADCON1 = 0x06;
    
    TRISAbits.TRISA0 = 0; //linia wyjsciowa A0 dioda
    TRISBbits.TRISB0 = 1; //linia wejsciowa B0 przycisk S1
    TRISBbits.TRISB1 = 1; //linia wejsciowa B1 (linia pomiarowa)
    
    PORTAbits.RA0 = 0; //dioda zgaszona
    
    WlaczLCD();
    UstawKursorLCD(1,4);
    WyswietlLCD(napis0,10);
    
    for(;;){
        
        while(PORTBbits.RB0 == 1);
        
        CzyscLCD();
        UstawKursorLCD(1,2);
        WyswietlLCD(napis1,14);
        
        czas = 0;
        czas_wzorcowy = 59999;
        
        while(czas_wzorcowy){
            
            if (PORTBbits.RB1 == 0) {czas++; PORTAbits.RA0 = 0;} //gdy detektor rejestruje
            else {PORTAbits.RA0 = 1;} //gdy detektor nie rejestruje
            
            czas_wzorcowy--;
        }
        
        
        
        PORTAbits.RA0 = 0; //dioda zgaszona
        ultoa(napisw, czas, 10);
        CzyscLCD();
        WyswietlLCD(napis2, 6);
        UstawKursorLCD(1,7);
        WyswietlLCD(napisw, strlen(napisw));
        UstawKursorLCD(2,4);
        WyswietlLCD(napis0,10);
    
     }
    
}
