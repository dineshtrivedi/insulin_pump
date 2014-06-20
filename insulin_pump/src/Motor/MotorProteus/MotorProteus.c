#include "MotorProteus.h"

const char TAMANHO_COMBINACAO_ACIONAMENTO = 8;
const char TEMPO_DEFAULT_PASSO_MS = 500;

char configureMotorProteus();
char writeMotorProteus( int qtdePasso );
char setTempoEsperaPassoMsMotorProteus( int tempoMs );

char sequence[TAMANHO_COMBINACAO_ACIONAMENTO] = {0x02,0x06,0x04,0x0c,0x08,0x09,0x01,0x03};
char passoAtual;
int tempoMsPasso;

IMotorPasso motorProteus = {
            &configureMotorProteus,
            &writeMotorProteus,
            &setTempoEsperaPassoMsMotorProteus
};

void delayEntrePassosDoMotor(){
     Delay_ms( 50 );
}

char configureMotorProteus(){
     TRISC = 0x00;
     passoAtual = 0;
     tempoMsPasso = TEMPO_DEFAULT_PASSO_MS;
}

char writeMotorProteus( int qtdePasso ){

//     const int teste = tempoMsPasso;
     for(;qtdePasso > 0; --qtdePasso )
     {
       PORTC = sequence[passoAtual];
       delayEntrePassosDoMotor();
       passoAtual = (passoAtual+1)%TAMANHO_COMBINACAO_ACIONAMENTO;
     }
}
char setTempoEsperaPassoMsMotorProteus( int tempoMs ){
     tempoMsPasso = tempoMs;
}