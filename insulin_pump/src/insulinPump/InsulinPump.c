#include "InsulinPump.h"
#include "../config/GlobalConfig.h"
#include "../timerMotor/TimerMotorPasso.h"

#include "../lcd/lcd.h"
#include "../lcd/lcdFactory.h"

#define QUANTIDADE_SEGUNDOS_EM_HORA 3600

unsigned int m_quantidade_injetada;
int m_intervalo_segundos_inteiro_para_injecao;
boolean m_injetar_habilitada;
int m_contador_injetar;
boolean m_flag_injetar;

// publicas
void inicializePump();
void pumpInject();
void startInject();
void stopInject();
int getQuantidadeInjetadaHora();

void configuraHoraAtual();

IInsulinPump InsulinPump = {
    &inicializePump,
    &pumpInject,
    &startInject,
    &stopInject,
    &getQuantidadeInjetadaHora
};

void inicializePump(){
     m_quantidade_injetada = 0;
     m_intervalo_segundos_inteiro_para_injecao = 0;
     m_injetar_habilitada = FALSE;
     m_contador_injetar = 0;
     m_flag_injetar = FALSE;
     startInject();
}

void pumpInject(){
  ILcd* lcd = getLcd( getTipoLcd() );
  if( m_injetar_habilitada == TRUE ){
       if( m_flag_injetar == TRUE ){
           ++m_quantidade_injetada;
           m_flag_injetar = FALSE;
       }
     }
}

void startInject(){
     configuraHoraAtual();
     m_injetar_habilitada = TRUE;
}

void stopInject(){
     m_injetar_habilitada = FALSE;
}

int getQuantidadeInjetadaHora() {
    return m_quantidade_injetada;
}

void configuraHoraAtual(){
     // a cada quantos segundos intejar
     char qtdeHora = getQtdeHoras(horas);
     if( qtdeHora > 0 )
          m_intervalo_segundos_inteiro_para_injecao = QUANTIDADE_SEGUNDOS_EM_HORA/qtdeHora;
          
     m_contador_injetar = m_contador_injetar % m_intervalo_segundos_inteiro_para_injecao;

}