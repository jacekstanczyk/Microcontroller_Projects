
#include <htc.h>

#define _XTAL_FREQ 4000000 //oscylator na płytce eval ZL 4PIC 4Mh

__CONFIG(FOSC_HS & WDTE_OFF & LVP_OFF);

void main()
{
	ADCON1 = 0x06;

	TRISA = 0;
    TRISB = 0;
	

	for(;;){
        
        PORTA = 0b00000001; //wlacza katode podpieta do RA0
        PORTB = 0b00000110; // kod czyfry 1
        __delay_ms(5);
        
        PORTA = 0b00000010; //wlacza katode podpieta do RA1
        PORTB = 0b01011011; // kod czyfry 2
        __delay_ms(5);
        
        PORTA = 0b00000100; //wlacza katode podpieta do RA2
        PORTB = 0b01001111; // kod czyfry 3
        __delay_ms(5);
        
        PORTA = 0b00001000; //wlacza katode podpieta do RA3
        PORTB = 0b01100110; // kod czyfry 4
        __delay_ms(5);
        
        
        
    }

}