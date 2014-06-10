#include "MenuConfigurar.h"
#include "../lcd/lcd.h"
#include "../lcd/lcdFactory.h"
#include "../config/GlobalConfig.h"
#include "MenuInicial.h"
#include "../config/GlobalConfig.h"

void mostrarMenuConfiguracao();
IMenu* analisarBotoesMenuConfiguracao();

IMenu MenuConfigurar = {
    &mostrarMenuConfiguracao,
    &analisarBotoesMenuConfiguracao
};

void mostrarMenuConfiguracao(){
   ILcd* lcd = getLcd( getTipoLcd() );
   char convercao[7];
   float quantidade;

   sprintf(convercao, "Hora: %d", indiceSelecionado+1);
   lcd->write(1,1, convercao);
   quantidade = ((float) getQtdeHoras(indiceSelecionado)) *
                      getQuantidadeInsulinaMinima();
   sprintf(convercao, "%.2f un", quantidade);
   lcd->write(2,1, convercao);
}

IMenu* analisarBotoesMenuConfiguracao(){
   ILcd* lcd = getLcd( getTipoLcd() );
       // pra cima
    if(button(&PORTB,0,1,0)){
       bloquearBotaoCima = 1;
    }
    else if(bloquearBotaoCima && button(&PORTB,0,1,1)){
       incrementaQtdeHoras(indiceSelecionado);
       bloquearBotaoCima = 0;
    }
   // Baixo
    if(button(&PORTB,1,1,0)){
       bloquearBotaoBaixo = 1;
    }
    else if(bloquearBotaoBaixo && button(&PORTB,1,1,1)){
       decrementaQtdeHoras(indiceSelecionado);
       bloquearBotaoBaixo = 0;
    }

    // confirmar
    if(button(&PORTB,2,1,0)){
       bloquearBotaoConfirmar = 1;
    }
    else if(bloquearBotaoConfirmar && button(&PORTB,2,1,1)){
       bloquearBotaoConfirmar = 0;
       if(indiceSelecionado >= 23) {
          indiceSelecionado = 0;
          lcd->clear();
          delayTrocaMenu();
          return &MenuInicial;
       }
       else{
          ++indiceSelecionado;
       }
    }
    
    // voltar-bloquear
    if(button(&PORTB,3,1,0)){
       bloquearBotaoVoltarBloquear = 1;
    }
    else if(bloquearBotaoVoltarBloquear && button(&PORTB,3,1,1)){
       bloquearBotaoVoltarBloquear = 0;
       if(indiceSelecionado > 0) {
          --indiceSelecionado;
       }
       else{
          lcd->clear();
          indiceSelecionado = 0;
          delayTrocaMenu();
          return &MenuInicial;
       }
    }

    return &MenuConfigurar;
}