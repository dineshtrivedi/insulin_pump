#ifndef GLOBAL_CONFIG_H
#define GLOBAL_CONFIG_H

#include "../lcd/lcd.h"

#define TRUE 1
#define FALSE 0
typedef char boolean;

void iniciliazar();
LCD_TYPE getTipoLcd();
char getQtdeHoras(char hora);
char incrementaQtdeHoras(char hora);
char decrementaQtdeHoras(char hora);
void setQtdeHoras(char hora, char valor);
float getQuantidadeInsulinaMinima();
float getQuantidadeInsulinaHora(char hora);
void delayTrocaMenu();
int getQuantidadeTotalInsulinaReservatorio();
void resetQuantidadeTotalInsulinaReservatorio();
char executarLoopPrincipal();
void sairLoopPrincipal();
#endif