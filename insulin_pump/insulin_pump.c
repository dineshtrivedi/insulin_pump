#include "src/lcd/lcdFactory.h"
#include "src/config/GlobalConfig.h"
//#include "src/menu/MenuInicial.h"
#include "src/timerMotor/TimerMotorPasso.h"
#include "src/menu/MenuReservatorio.h"

void interrupt() {      //vetor de interrupção de alta prioridade padrão do mikroc
  tick++;
    if (tick >= 400){
       ++segundos;
        if(segundos > 59){
            segundos = 0;
            ++minutos;
            if (minutos > 59) {
               minutos = 0;
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
//  IMenu* menu = &MenuInicial;
  IMenu* menu = &MenuReservatorio;

  timerMotorPasso.configurar();
  timerMotorPasso.iniciar();

  iniciliazar();

  lcd->configure();                       // Initialize LCD

  lcd->clear();
  lcd->cursorOff();

  while(executarLoopPrincipal()) {
      menu->mostrarMenu();
      menu = menu->analisarBotoes();
    }
    
}