#include <htc.h>

#define _XTAL_FREQ 4000000 //oscylator na płytce eval ZL 4PIC 4Mh

__CONFIG(FOSC_HS & WDTE_OFF & LVP_OFF);

int i=0, a=0,b=0,c=0,d=0;

void main()
{
	ADCON1 = 0x06;

	TRISA = 0;
	
    for(;;){
        
        for(i=0; i<8; i++){
        
                     {if (a==0) {PORTA |= (1 << 0); a=1;} else { PORTA &= ~(1 << 0); a=0;} } //dioda podpieta do RA0
        if (!(i%2))  {if (b==0) {PORTA |= (1 << 1); b=1;} else { PORTA &= ~(1 << 1); b=0;}  }//dioda podpieta do RA1
        if (!(i%4))  {if (c==0) {PORTA |= (1 << 2); c=1;} else { PORTA &= ~(1 << 2); c=0;}  }//dioda podpieta do RA2
        if (!(i%8))  {if (d==0) {PORTA |= (1 << 3); d=1;} else { PORTA &= ~(1 << 3); d=0;}  }//dioda podpieta do RA3
        
        __delay_ms(1);
        }
    }
	

}