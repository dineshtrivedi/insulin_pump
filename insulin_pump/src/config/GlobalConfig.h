#ifndef GLOBAL_CONFIG_H
#define GLOBAL_CONFIG_H

#include "../lcd/lcd.h"
void iniciliazar();
LCD_TYPE getTipoLcd();
char getQtdeHoras(char hora);
char incrementaQtdeHoras(char hora);
char decrementaQtdeHoras(char hora);
void setQtdeHoras(char hora, char valor);
float getQuantidadeInsulinaMinima();
float getQuantidadeInsulinaHora(char hora);
void delayTrocaMenu();
float getQuantidadeTotalInsulinaReservatorio();
void resetQuantidadeTotalInsulinaReservatorio();
char executarLoopPrincipal();
void sairLoopPrincipal();
#endif