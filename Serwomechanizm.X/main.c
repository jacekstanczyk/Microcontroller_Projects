#include <htc.h>

#define _XTAL_FREQ 4000000 //oscylator na płytce eval ZL 4PIC 4Mh

__CONFIG(FOSC_HS & WDTE_OFF & LVP_OFF);

int i;

void main()
{
	ADCON1 = 0x06;

	TRISAbits.TRISA0 = 0;
	

	for(;;){
        
        for(i=0; i<80; i++){
            
            PORTAbits.RA0 = 1; //inpuls RA1
            __delay_us(500);
            PORTAbits.RA0 = 0;
            __delay_ms(15); 
        }
        
        for(i=0; i<80; i++){
            
            PORTAbits.RA0 = 1; //inpuls RA1
            __delay_us(2500);
            PORTAbits.RA0 = 0;
            __delay_ms(15); 
        }
        
    }

}
