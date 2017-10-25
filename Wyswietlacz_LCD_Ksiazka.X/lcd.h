/* 
 * File:   lcd.h
 * Author: placek
 *
 * Created on 23 września 2017, 19:05
 */

#ifndef LCD_H
#define	LCD_H

//////////////////////////////////////////////
void Wyslij_do_LCD(unsigned char bajt)
{
	//ustawienie EN
	EN_LCD = 1;
	//wysłanie 4 najstarszych bitów danych
	if(bajt & 0x80)	DB7_LCD	= 1; else DB7_LCD = 0;
	if(bajt & 0x40)	DB6_LCD	= 1; else DB6_LCD = 0;
	if(bajt & 0x20)	DB5_LCD	= 1; else DB5_LCD = 0;
	if(bajt & 0x10)	DB4_LCD	= 1; else DB4_LCD = 0;
	//zaczekaj 1 us
	__delay_us(1);
	//potwierdzenie wysłania danych (opadającym zboczem EN)
	EN_LCD = 0;

	//zaczekaj 1 us
	__delay_us(1);
	
	//ustawienie EN
	EN_LCD = 1;
	//wysłanie 4 najmłodszych bitów danych	
	if(bajt & 0x08)	DB7_LCD	= 1; else DB7_LCD = 0;
	if(bajt & 0x04)	DB6_LCD	= 1; else DB6_LCD = 0;
	if(bajt & 0x02)	DB5_LCD	= 1; else DB5_LCD = 0;
	if(bajt & 0x01)	DB4_LCD	= 1; else DB4_LCD = 0;
	//zaczekaj 1 us
	__delay_us(1);
	//potwierdzenie wysłania danych (opadającym zboczem EN)
	EN_LCD = 0;

	//zaczekaj 37 us
	__delay_us(37);
}	

void CzyscLCD()
{
	RS_LCD = 0;
	Wyslij_do_LCD(1);
	RS_LCD = 1; 

	//czekaj 1.64 ms
	__delay_us(1640);
} 

void WlaczLCD()
{
	//ustawienie kierunku wyjściowego linii podłączonych do LCD
	TRIS_RS_LCD = 0;
	TRIS_EN_LCD = 0;
	TRIS_DB7_LCD = 0;
	TRIS_DB6_LCD = 0;
	TRIS_DB5_LCD = 0;
	TRIS_DB4_LCD = 0;

	//stan niski na liniach
	RS_LCD = 0;
	EN_LCD = 0;
	DB7_LCD = 0;
	DB6_LCD = 0;
	DB5_LCD = 0;
	DB4_LCD = 0;

	//zaczekaj co najmniej 45 ms na ustabilizowanie się napięcia
	__delay_us(45000);

	//1
	//ustaw linię EN
	EN_LCD = 1;
	//załaduj sekwencję 0011
	DB7_LCD = 0;
	DB6_LCD = 0;
	DB5_LCD = 1;
	DB4_LCD = 1;
	//zaczekaj 1 us
	__delay_us(1);
	//potwierdź opadającym zboczem EN
	EN_LCD = 0;

	//zaczekaj co najmniej 4.1 ms
	__delay_us(4100);

	//2
	//ustaw linię EN
	EN_LCD = 1;
	//zaczekaj 1 us
	__delay_us(1);
	//potwierdź opadającym zboczem EN sekwencję 0011
	EN_LCD = 0;
	
	//zaczekaj co najmniej 100 us
	__delay_us(100);
	
	//3
	//ustaw linię EN
	EN_LCD = 1;
	//zaczekaj 1 us
	__delay_us(1);
	//potwierdź opadającym zboczem EN sekwencję 0011
	EN_LCD = 0;
	
	//zaczekaj co najmniej 100 us
	__delay_us(100);
 
	//4
	//ustaw linię EN
	EN_LCD = 1;
	//ustawienie interfejsu 4-bitowego
	DB4_LCD = 0;
	//zaczekaj 1 us
	__delay_us(1);
	//potwierdź opadającym zboczem EN
	EN_LCD = 0;

	//ustaw parametry wyświetlacza
	//bit 4 = 0 (słowo danych ma 4 bity)
	//bit 3 = 1 (2 wiersze znaków)
	//bit 2 = 0 (matryca 5x8 pikseli)
	RS_LCD = 0;
	Wyslij_do_LCD(0b00101000);
	RS_LCD = 1;

	//włącz wyświetlacz
	//bit 2 = 1 (włączenie wyświetlania)
	//bit 1 = 0 (kursor nieaktywny)
	//bit 0 = 0 (kursor nie miga)
	RS_LCD = 0;
	Wyslij_do_LCD(0b00001100);
	RS_LCD = 1;

	//ustaw tryb pracy wyświetlacza
	//bit 2 = 1 (inkrementowanie adresu zapisu danych)
	//bit 1 = 1 (wyłączenie przesuwania w prawo)
	RS_LCD = 0;
	Wyslij_do_LCD(0b00000110);
	RS_LCD = 1;

	CzyscLCD();
}

void WyswietlLCD(char *napis, unsigned char ile)
{
	unsigned char k = 0;
	while(k<ile)
	{
		Wyslij_do_LCD(napis[k]);
		k++;
	}
}

void UstawKursorLCD(unsigned char y, unsigned char x)
{
	//ustal nowy adres pamięci DD RAM
	unsigned char n;
	if (y==1) n = x - 1;
	else n = 0x40 + x - 1;
	//ustaw kod
	n |= 0b10000000;
	
	//wyślij rozkaz ustawienia nowego adresu DD RAM
	RS_LCD = 0;
	Wyslij_do_LCD(n);
	RS_LCD = 1;	
	
	//zaczekaj 40 us
	//__delay_us(40);	
}



#endif	/* LCD_H */

