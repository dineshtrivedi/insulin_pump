#ifndef IMOTORPASSO_H
#define IMOTORPASSO_H

typedef struct{

    char (*configure)();
    char (*write)( int );
    char (*setTempoEsperaPassoMs)( int );

} IMotorPasso;

typedef enum  { MOTOR_PASSO_PROTEUS = 0, MOTOR_PASSO_GOIAS = 1 } TIPO_MOTOR_PASSO;

#endif // IMOTORPASSO_H