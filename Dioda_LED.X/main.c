#include <htc.h>

#define _XTAL_FREQ 4000000 //oscylator na płytce eval ZL 4PIC 4Mh

__CONFIG(FOSC_HS & WDTE_OFF & LVP_OFF);

void main()
{
	ADCON1 = 0x06;

	TRISA = 0;
	

	for(;;){
        
        PORTA |= (1 << 0); //wlacza diode podpieta do RA0
        __delay_ms(500);
        PORTA &= ~(1 << 0); //wylacza diode podpieta do RA0
        __delay_ms(500);
        
    }

}