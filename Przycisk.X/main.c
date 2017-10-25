#include <htc.h>

#define _XTAL_FREQ 4000000 //oscylator na płytce eval ZL 4PIC 4Mh

__CONFIG(FOSC_HS & WDTE_OFF & LVP_OFF);



void main()
{
	ADCON1 = 0x06;

	TRISAbits.TRISA0 = 0;   // linia A0 wyjsciowa
    TRISBbits.TRISB0 = 1;   // linia B0 wejsciowa
    
    OPTION_REGbits.nRBPU = 0;    // wlaczenie rezystorow podciagajacych portu B
	
    
    
	for(;;){
        
        if (PORTBbits.RB0 == 1) PORTAbits.RA0 = 0;
        else PORTAbits.RA0 = 1;
        
    }

}
