#include "MenuReservatorio.h"
#include "../lcd/lcd.h"
#include "../lcd/lcdFactory.h"
#include "../config/GlobalConfig.h"
#include "MenuInicial.h"
#include "../timerMotor/TimerMotorPasso.h"

char reservatoriCheioSim = 0;

void mostrarMenuReservatorio();
IMenu* analisarBotoesMenuReservatorio();

IMenu MenuReservatorio = {
    &mostrarMenuReservatorio,
    &analisarBotoesMenuReservatorio
};

void mostrarMenuReservatorio(){
  ILcd* lcd = getLcd( getTipoLcd() );
  unsigned char converter[15];
  memset(&converter, 0x00, sizeof(converter));

  sprintf(converter,"%02d:%02d:%02d F:%.0f%%", horas, minutos, segundos, 100);
  lcd->write(1,1, "Insulina cheia");
  if(reservatoriCheioSim == 0){
    lcd->write(2,1, "( ) sim, (-) nao");
  }
  else{
    lcd->write(2,1, "(-) sim, ( ) nao");
  }
}

IMenu* analisarBotoesMenuReservatorio(){
  ILcd* lcd = getLcd( getTipoLcd() );
       // pra cima
    if(button(&PORTB,0,1,0)){
       bloquearBotaoCima = 1;
    }
    if(bloquearBotaoCima && button(&PORTB,0,1,1)){
       bloquearBotaoCima = 0;
       if(reservatoriCheioSim == 0)
          reservatoriCheioSim = 1;
       else if(reservatoriCheioSim == 1)
          reservatoriCheioSim = 0;
    }
   // Baixo
    if(button(&PORTB,1,1,0)){
       bloquearBotaoBaixo = 1;
    }
    if(bloquearBotaoBaixo && button(&PORTB,1,1,1)){
       bloquearBotaoBaixo = 0;
       if(reservatoriCheioSim == 0)
          reservatoriCheioSim = 1;
       else if(reservatoriCheioSim == 1)
          reservatoriCheioSim = 0;
    }
    
  // confirmar
  if(button(&PORTB,2,1,0)){
     bloquearBotaoConfirmar = 1;
  }
  if(bloquearBotaoConfirmar && button(&PORTB,2,1,1)){
    if(reservatoriCheioSim == 1)
       resetQuantidadeTotalInsulinaReservatorio();
       
    lcd->clear();
    bloquearBotaoConfirmar = 0;
    delayTrocaMenu();
    return &MenuInicial;
  }

  delayTrocaMenu();
  return &MenuReservatorio;
}