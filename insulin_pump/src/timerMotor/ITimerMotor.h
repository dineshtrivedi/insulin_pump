#ifndef ITIMERMOTOR_H
#define ITIMERMOTOR_H

extern volatile int tick;
extern volatile int segundos;
extern volatile int minutos;
extern volatile int horas;

typedef struct{
    void (*configurar)();
    void (*iniciar)();
    void (*parar)();
} ITimerMotor;

#endif