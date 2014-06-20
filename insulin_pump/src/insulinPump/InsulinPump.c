#include "InsulinPump.h"
#include "../config/GlobalConfig.h"
#include "../timerMotor/TimerMotorPasso.h"
#include "../Motor/MotorPassoFactory.h"
#include "../lcd/lcd.h"
#include "../lcd/lcdFactory.h"

#define QUANTIDADE_SEGUNDOS_EM_HORA 3600
#define QUANTIDADE_PASSOS_INFUSAO_MINIMA 8

unsigned int m_quantidade_injetada_total;
unsigned int m_quantidade_injetada_hora;
int m_intervalo_segundos_inteiro_para_injecao;
boolean m_injetar_habilitada;
int m_contador_injetar;
boolean m_flag_injetar;
boolean m_flag_mudou_hora;

// publicas
void inicializePump();
void pumpInject();
void startInject();
void stopInject();
int getQuantidadeInjetadaHora();

void configuraHoraAtual();

IMotorPasso* m_motorPasso;
  
IInsulinPump InsulinPump = {
    &inicializePump,
    &pumpInject,
    &startInject,
    &stopInject,
    &getQuantidadeInjetadaHora
};

void inicializePump(){
     m_quantidade_injetada_total = 0;
     m_quantidade_injetada_hora = 0;
     m_intervalo_segundos_inteiro_para_injecao = 0;
     m_injetar_habilitada = FALSE;
     m_contador_injetar = 0;
     m_flag_injetar = FALSE;
     m_motorPasso = getMotorPasso( MOTOR_PASSO_PROTEUS );
     m_motorPasso->configure();
     m_flag_mudou_hora = FALSE;
     startInject();
}

void pumpInject(){
  if( m_flag_mudou_hora == TRUE ){
    configuraHoraAtual();
  }
  
  if( m_injetar_habilitada == TRUE ){
       if( m_flag_injetar == TRUE ){
           ++m_quantidade_injetada_total;
           ++m_quantidade_injetada_hora;
           m_flag_injetar = FALSE;
           m_motorPasso->write(QUANTIDADE_PASSOS_INFUSAO_MINIMA);
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
    return m_quantidade_injetada_hora;
}

void configuraHoraAtual(){
     // a cada quantos segundos intejar
     char qtdeHora = getQtdeHoras(horas);
     if( qtdeHora > 0 )
          m_intervalo_segundos_inteiro_para_injecao = QUANTIDADE_SEGUNDOS_EM_HORA/qtdeHora;
     else
         m_intervalo_segundos_inteiro_para_injecao = 0;
          
     m_contador_injetar = m_contador_injetar % m_intervalo_segundos_inteiro_para_injecao;

}