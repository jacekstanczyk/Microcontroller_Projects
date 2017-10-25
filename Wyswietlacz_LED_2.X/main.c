#include <htc.h>

#define _XTAL_FREQ 4000000 //oscylator na płytce eval ZL 4PIC 4Mh

__CONFIG(FOSC_HS & WDTE_OFF & LVP_OFF);

char tablica[]={
    0b00111111, //0
    0b00000110, //1
    0b01011011, //2
    0b01001111, //3
    0b01100110, //4 
    0b01101101, //5
    0b01111101, //6
    0b00000111, //7
    0b01111111, //8
    0b01101111, //9
    0b10000000 //.
};

char a,b,c,d;
void czas(void){
    if (a==9) {a = 0;}  else {a +=1; return;}
    if (b==9) {b = 0;}  else {b +=1; return;}
    if (c==9) {c = 0;}  else {c +=1; return;}
    if (d==9) {d = 0;}  else {d +=1; return;}
}

void main()
{
	ADCON1 = 0x06;

	TRISA = 0;
    TRISB = 0;
	
    
    
	for(;;){
        
        PORTA = 0b00000001; //wlacza katode podpieta do RA0
        PORTB = tablica[d]; // kod czyfry 1
        __delay_ms(5);
        
        PORTA = 0b00000010; //wlacza katode podpieta do RA1
        PORTB = tablica[c]; // kod czyfry 2
        __delay_ms(5);
        
        PORTA = 0b00000100; //wlacza katode podpieta do RA2
        PORTB = tablica[b]; // kod czyfry 3
        __delay_ms(5);
        
        PORTA = 0b00001000; //wlacza katode podpieta do RA3
        PORTB = tablica[a]; // kod czyfry 4
        __delay_ms(5);
        
        czas();
        
    }

}