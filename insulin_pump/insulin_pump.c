#include "src/lcd/lcdFactory.h"
#include "src/config/GlobalConfig.h"
#include "src/insulinPump/InsulinPump.h"
#include "src/timerMotor/TimerMotorPasso.h"
#include "src/menu/MenuReservatorio.h"

//verifica se o contador de segundos chegou no intervalo que deve ocorrer a infusao
void verifica_infusao(){
  /*incrementa o contador que e utilizado pra infundir a insulina*/
  ++m_contador_injetar;
  /*caso tenha chegado no intervalo que deve ocorrer a infusao*/
  if(m_intervalo_segundos_inteiro_para_injecao > 0 && m_contador_injetar >= m_intervalo_segundos_inteiro_para_injecao){
    m_flag_injetar = TRUE;
    m_contador_injetar = m_contador_injetar % m_intervalo_segundos_inteiro_para_injecao;
  }
}

void interrupt() {
  tick++;
    if (tick >= 10){
       ++segundos;
       verifica_infusao();
        if(segundos > 59){
            segundos = 0;
            ++minutos;
            if (minutos > 59) {
               minutos = 0;
               m_contador_injetar = 0;
               m_quantidade_injetada_hora = 0;
               m_flag_mudou_hora = TRUE;
               ++horas;
               if (horas > 23) {
                  horas = 0;
                  }
            }
        }

        tick = 0;
   }
  TMR0L  =  192;                //   on time
  INTCON = 0x20;
}

void main() {

  unsigned char converter[15];
  ILcd* lcd = getLcd( getTipoLcd() );
  IMenu* menu = &MenuReservatorio;

  InsulinPump.initialize();
  timerMotorPasso.configurar();
  timerMotorPasso.iniciar();

  iniciliazar();

  lcd->configure();                       // Initialize LCD

  lcd->clear();
  lcd->cursorOff();

  while(executarLoopPrincipal()) {
      menu->mostrarMenu();
      menu = menu->analisarBotoes();
      InsulinPump.inject();
    }
    
}