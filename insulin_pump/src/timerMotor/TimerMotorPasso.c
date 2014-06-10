#include "ITimerMotor.h"

volatile int tick;
volatile int segundos;
volatile int minutos;
volatile int horas;

void configruarTimerMotorPasso();
void iniciarTimerMotorPasso();
void pararTimerMotorPasso();

ITimerMotor timerMotorPasso = {
    &configruarTimerMotorPasso,
    &iniciarTimerMotorPasso,
    &pararTimerMotorPasso
};

void configruarTimerMotorPasso(){
     tick = 0;
     segundos = 0;
     minutos = 0;
     horas = 0;

    TMR0L =  192;
    INTCON = 0xA0;
}
void iniciarTimerMotorPasso(){
    T0CON = 0xC4;           // Enable watchdog timer
}
void pararTimerMotorPasso(){
    T0CON = 0x00;           // Disable watchdog timer
}