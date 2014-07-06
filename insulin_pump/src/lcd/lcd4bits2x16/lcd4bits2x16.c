#include "Lcd4Bits2x16.h"

// LCD module connections
sbit LCD_RS at RE2_bit;
sbit LCD_EN at RE1_bit;

sbit LCD_D4 at RD4_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D7 at RD7_bit;

sbit LCD_RS_Direction at TRISE2_bit;
sbit LCD_EN_Direction at TRISE1_bit;
sbit LCD_D4_Direction at TRISD4_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D7_Direction at TRISD7_bit;

char configureLcd4Bits2x16();
char writeLcd4Bits2x16( char, char, char* );
char writeCurrentCursorLcd4Bits2x16( char* );
char clearLcd4Bits2x16();
char shitfRigthLcd4Bits2x16();
char shitfLeftLcd4Bits2x16();
char cursorOffLcd4Bits2x16();

ILcd Lcd4Bits2x16 = {
    &configureLcd4Bits2x16,
    &writeLcd4Bits2x16,
    &writeCurrentCursorLcd4Bits2x16,
    &clearLcd4Bits2x16,
    &shitfRigthLcd4Bits2x16,
    &shitfLeftLcd4Bits2x16,
    &cursorOffLcd4Bits2x16
};

/*
obs: a emissao do registrador ADCON1 nos programas, acarreta o nao acionamento adequado do PORTA e consequentemente provoca o mal funcionamento do programa.
O pino RA4 do PIC eh dreno aberto, isto implica que devemos conectar resitor de pull-up quando formos trabalhar este pino como I/O de uso geral.
O PORTE tambem possui a funcao de conversores analogicos ou  digitais tambem. Devemos configurar o ADCON1 para trabalharmos o PORTE como IO de uso geral.
*/
char configureLcd4Bits2x16(){
  trise = 0; // pinos D como saida
  ADCON1 = 0x06; // Todos os pinos A/D como I/O uso geral
    Lcd_Init();
    //Lcd8_Config(&PORTE,&PORTD,2,1,0,7,6,5,4,3,2,1,0);
    return 0;
}

char writeLcd4Bits2x16( char linha, char coluna, char* texto ){
     trisd = 0; // pinos D como saida
     Lcd_Out( linha, coluna, texto );
     trisd = 255; // pinos D como entrada
     return 0;
}

char writeCurrentCursorLcd4Bits2x16( char* texto ){
    trisd = 0; // pinos D como saida
    Lcd_Out_CP( texto );
    trisd = 255; // pinos D como entrada
    return 0;
}

char clearLcd4Bits2x16(){
    trisd = 0; // pinos D como saida
    Lcd_Cmd( _LCD_CLEAR );
    trisd = 255; // pinos D como entrada
    return 0;
}

char shitfRigthLcd4Bits2x16(){
    trisd = 0; // pinos D como saida
     Lcd_Cmd(_LCD_SHIFT_RIGHT);
    trisd = 255; // pinos D como entrada
     return 0;
}

char shitfLeftLcd4Bits2x16(){
    trisd = 0; // pinos D como saida
     Lcd_Cmd(_LCD_SHIFT_RIGHT);
    trisd = 255; // pinos D como entrada
     return 0;
}

char cursorOffLcd4Bits2x16(){
    trisd = 0; // pinos D como saida
     Lcd_Cmd(_LCD_CURSOR_OFF);
    trisd = 255; // pinos D como entrada
     return 0;
}