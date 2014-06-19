#include "MenuInicial.h"
#include "../lcd/lcd.h"
#include "../lcd/lcdFactory.h"
#include "../config/GlobalConfig.h"
#include "MenuConfigurar.h"
#include "MenuExecutando.h"
#include "../insulinPump/InsulinPump.h"

void mostrarMenuInicial();
IMenu* analisarBotoesMenuInicial();

IMenu MenuInicial = {
    &mostrarMenuInicial,
    &analisarBotoesMenuInicial
};

void mostrarMenuInicial(){
   ILcd* lcd = getLcd( getTipoLcd() );

   if( indiceSelecionado == 0 ){
      lcd->write(1,1, "- Iniciar");
   }
   else{
      lcd->write(1,1, "  Iniciar");
   }
   
   if( indiceSelecionado == 1 ){
      lcd->write(2,1, "- Config. basal");
   }
   else{
      lcd->write(2,1, "  Config. basal");
   }
}

IMenu* analisarBotoesMenuInicial(){
   ILcd* lcd = getLcd( getTipoLcd() );
       // pra cima
    if(button(&PORTB,0,1,0)){
       bloquearBotaoCima = 1;
    }
    if(bloquearBotaoCima && button(&PORTB,0,1,1)){
       bloquearBotaoCima = 0;
       if(indiceSelecionado == 0)
          indiceSelecionado = 1;
       else if(indiceSelecionado == 1)
          indiceSelecionado = 0;
    }
   // Baixo
    if(button(&PORTB,1,1,0)){
       bloquearBotaoBaixo = 1;
    }
    if(bloquearBotaoBaixo && button(&PORTB,1,1,1)){
       bloquearBotaoBaixo = 0;
       if(indiceSelecionado == 0)
          indiceSelecionado = 1;
       else if(indiceSelecionado == 1)
          indiceSelecionado = 0;
    }
    
    // confirmar
    if(button(&PORTB,2,1,0)){
       bloquearBotaoConfirmar = 1;
    }
    if(bloquearBotaoConfirmar && button(&PORTB,2,1,1)){
      bloquearBotaoConfirmar = 0;
      lcd->clear();
       if(indiceSelecionado == 0){
          delayTrocaMenu();
          InsulinPump.start();
          return &MenuExecutando;
       }
       else if(indiceSelecionado == 1) {
          indiceSelecionado = 0;
          delayTrocaMenu();
          return &MenuConfigurar;
       }
    }
    
    delayTrocaMenu();
    return &MenuInicial;
}