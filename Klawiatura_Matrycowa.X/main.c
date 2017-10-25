#include <htc.h>
#include <pic16f877a.h>

#define _XTAL_FREQ 4000000 //oscylator na płytce eval ZL 4PIC 4Mh

__CONFIG(FOSC_HS & WDTE_OFF & LVP_OFF);

enum klawisz {
    zero = 0,
    jeden = 1,
    dwa = 2,
    trzy = 3,
    cztery = 4,
    piec = 5,
    szesc = 6,
    siedem = 7,
    osiem = 8,
    dziewiec = 9,
    gwiazdka = 10,
    krzyzyk
};

enum klawisz wcisnieto = 0;

void main()
{
	ADCON1 = 0x06;

	TRISA = 0;
    TRISB = 1; //linie portu b wejściowe
    OPTION_REGbits.nRBPU = 0;    // wlaczenie rezystorow podciagajacych portu B
    
    TRISC = 0xF0;  //linie 0-3 portu c wyjsciowe 
    
    
	for(;;){
        
        PORTCbits.RC0 = 0;
        PORTCbits.RC1 = 1;
        PORTCbits.RC2 = 1;
        PORTCbits.RC3 = 1;
        asm("nop");
        if(PORTBbits.RB0 == 0) wcisnieto = jeden;
        if(PORTBbits.RB1 == 0) wcisnieto = dwa;
        if(PORTBbits.RB2 == 0) wcisnieto = trzy;
        
        PORTCbits.RC0 = 1;
        PORTCbits.RC1 = 0;
        PORTCbits.RC2 = 1;
        PORTCbits.RC3 = 1;
        asm("nop");
        if(PORTBbits.RB0 == 0) wcisnieto = cztery;
        if(PORTBbits.RB1 == 0) wcisnieto = piec;
        if(PORTBbits.RB2 == 0) wcisnieto = szesc;
        
        PORTCbits.RC0 = 1;
        PORTCbits.RC1 = 1;
        PORTCbits.RC2 = 0;
        PORTCbits.RC3 = 1;
        asm("nop");
        if(PORTBbits.RB0 == 0) wcisnieto = siedem;
        if(PORTBbits.RB1 == 0) wcisnieto = osiem;
        if(PORTBbits.RB2 == 0) wcisnieto = dziewiec;
        
        PORTCbits.RC0 = 1;
        PORTCbits.RC1 = 1;
        PORTCbits.RC2 = 1;
        PORTCbits.RC3 = 0;
        asm("nop");
        if(PORTBbits.RB0 == 0) wcisnieto = gwiazdka;
        if(PORTBbits.RB1 == 0) wcisnieto = zero;
        if(PORTBbits.RB2 == 0) wcisnieto = krzyzyk;
        
        
        
        if (wcisnieto == jeden) PORTAbits.RA0 = 1; else PORTAbits.RA0 = 0;
        if (wcisnieto == piec) PORTAbits.RA1 = 1; else PORTAbits.RA1 = 0;
        if (wcisnieto == dziewiec) PORTAbits.RA2 = 1; else PORTAbits.RA2 = 0;
        if (wcisnieto == gwiazdka) PORTAbits.RA3 = 1; else PORTAbits.RA3 = 0;
        
    }

}

