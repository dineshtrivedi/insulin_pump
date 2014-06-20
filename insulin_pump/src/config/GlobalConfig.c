#include "GlobalConfig.h"

#define QUANTIDADE_TOTAL_RESERVATORIO_INSULINA 100
int quantidadeTotalInsulinaReservatorio = QUANTIDADE_TOTAL_RESERVATORIO_INSULINA;
char vetorQtdeHoras[24];
char executarAplicacao = 1;

void iniciliazar(){
  vetorQtdeHoras[0] = 12;
  vetorQtdeHoras[1] = 24;
  vetorQtdeHoras[2] = 0;
  vetorQtdeHoras[3] = 0;
  vetorQtdeHoras[4] = 0;
  vetorQtdeHoras[5] = 0;
  vetorQtdeHoras[6] = 0;
  vetorQtdeHoras[7] = 0;
  vetorQtdeHoras[8] = 0;
  vetorQtdeHoras[9] = 0;
  vetorQtdeHoras[10] = 0;
  vetorQtdeHoras[11] = 0;
  vetorQtdeHoras[12] = 0;
  vetorQtdeHoras[13] = 0;
  vetorQtdeHoras[14] = 0;
  vetorQtdeHoras[15] = 0;
  vetorQtdeHoras[16] = 0;
  vetorQtdeHoras[17] = 0;
  vetorQtdeHoras[18] = 0;
  vetorQtdeHoras[19] = 0;
  vetorQtdeHoras[20] = 0;
  vetorQtdeHoras[21] = 0;
  vetorQtdeHoras[22] = 0;
  vetorQtdeHoras[23] = 0;
}

#ifdef __cplusplus
extern "C"
#endif
LCD_TYPE getTipoLcd(){
   return LCD_4BITS_2X16;
}

char getQtdeHoras(char hora){
  return vetorQtdeHoras[hora];
}

char incrementaQtdeHoras(char hora){
   ++vetorQtdeHoras[hora];
   return vetorQtdeHoras[hora];
}

char decrementaQtdeHoras(char hora){
   if(vetorQtdeHoras[hora] > 0){
      --vetorQtdeHoras[hora];
   }
   
   return vetorQtdeHoras[hora];
}

void setQtdeHoras(char hora, char valor){
  vetorQtdeHoras[hora] = valor;
}

float getQuantidadeInsulinaMinima(){
   return 0.1f;
}

float getQuantidadeInsulinaHora(char hora){
   return getQuantidadeInsulinaMinima() * ( (float)vetorQtdeHoras[hora]);
}

void delayTrocaMenu(){
   Delay_ms(50);
}

int getQuantidadeTotalInsulinaReservatorio(){
   return quantidadeTotalInsulinaReservatorio;
}

void resetQuantidadeTotalInsulinaReservatorio(){
     quantidadeTotalInsulinaReservatorio = QUANTIDADE_TOTAL_RESERVATORIO_INSULINA;
}

char executarLoopPrincipal(){
     return executarAplicacao;
}

void sairLoopPrincipal(){
     executarAplicacao = 0;
}