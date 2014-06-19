#include "MenuExecutando.h"
#include "../lcd/lcd.h"
#include "../lcd/lcdFactory.h"
#include "../config/GlobalConfig.h"
#include "MenuInicial.h"
#include "../timerMotor/TimerMotorPasso.h"
#include "../insulinPump/InsulinPump.h"

void mostrarMenuExecutando();
IMenu* analisarBotoesExecutando();

IMenu MenuExecutando = {
    &mostrarMenuExecutando,
    &analisarBotoesExecutando
};

void mostrarMenuExecutando(){
  int porcentagem = 100*(getQuantidadeTotalInsulinaReservatorio() - m_quantidade_injetada)/getQuantidadeTotalInsulinaReservatorio();
  ILcd* lcd = getLcd( getTipoLcd() );
  unsigned char converter[15];
  memset(&converter, 0x00, sizeof(converter));
  
  sprintf(converter,"%02d:%02d:%02d F:%02d%%", horas, minutos, segundos, porcentagem);
  lcd->write(1,1, converter);

  sprintf(converter,"%.2f/%.2f un", (float)((float)InsulinPump.getQuantidadeInjetadaHora()*getQuantidadeInsulinaMinima()),
                                    getQuantidadeInsulinaHora(horas));
  lcd->write(2,1, converter);
}

IMenu* analisarBotoesExecutando(){
  ILcd* lcd = getLcd( getTipoLcd() );
  // confirmar
  if(button(&PORTB,2,1,0)){
     bloquearBotaoConfirmar = 1;
  }
  if(bloquearBotaoConfirmar && button(&PORTB,2,1,1)){
    lcd->clear();
    bloquearBotaoConfirmar = 0;
    delayTrocaMenu();
    InsulinPump.stop();
    return &MenuInicial;
  }
 
   // voltar-vloquear
  if(button(&PORTB,3,1,0)){
     bloquearBotaoVoltarBloquear = 1;
  }
  if(bloquearBotaoVoltarBloquear && button(&PORTB,3,1,1)){
    lcd->clear();
    bloquearBotaoVoltarBloquear = 0;
    delayTrocaMenu();
    InsulinPump.stop();
    return &MenuInicial;
  }
  
  delayTrocaMenu();
  return &MenuExecutando;
}