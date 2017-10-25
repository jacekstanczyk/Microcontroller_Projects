
#include <htc.h>

#define _XTAL_FREQ 4000000 //oscylator na p?ytce eval ZL 4PIC 4Mh

__CONFIG(FOSC_HS & WDTE_OFF & LVP_OFF);

char serwa[21]={
    
    0b00000111,
    0b00000111,
    0b00000111,
    0b00000111,
    0b00000111,
    0b00000111,
    0b00000111,
    0b00000111,
    0b00000111,
    0b00000111,
    0b00000111,
    0b00000111,
    0b00000111,
    0b00000111,
    0b00000111,
    0b00000111,
    0b00000111,
    0b00000111,
    0b00000111,
    0b00000110,
    0b00000110
};

char indeksy[3]={18, 20, 20};

Sterowanie_serwami(){
    char i;
    
    // pierwszy impuls
    PORTA = 0x07;
    __delay_us(620);
    
    //ustawienie pod w?a?ciwym katem
    for(i=0; i<=21; i++){
        PORTA = serwa[i];
        __delay_us(77);
    }
    
    //wy?acz impuls na wszystkich serwach
    PORTA = 0x00;
}

Zmiana_tablicy(char numer_serwa, char indeks){
    char i;
    
    //maska dla sumy bitowej
    char maska = (1<<numer_serwa);
    
    for (i=0; i<=indeks; i++) serwa[i] |= maska;
    
    maska = ~maska;
    
    for(i=indeks+1; i<=21; i++) serwa[i] &= maska;
}

void main()
{
	unsigned char i, j;
    ADCON1 = 0x06;

	TRISAbits.TRISA0 = 0;
	TRISAbits.TRISA1 = 0;
    TRISAbits.TRISA2 = 0;

	for(;;){
        
        //pozycja poczatkowa
        for(i=0; i<80; i++){
            
            Sterowanie_serwami();
            __delay_ms(15); 
        }
        
       
            
            for(j=0; j<3; j++){
               
                Zmiana_tablicy(j, 20);  
            }
        
        
        //ramie wyprostowane
        for(i=0; i<80; i++){
            
            Sterowanie_serwami();
            __delay_ms(15); 
        }
        
            
            for(j=0; j<3; j++){
               
                Zmiana_tablicy(j, 1);  
            }
        
    }

}

