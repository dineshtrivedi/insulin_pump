#include "MotorPassoFactory.h"
#include "MotorProteus/MotorProteus.h"

#ifdef __cplusplus
extern "C"
#endif
IMotorPasso* getMotorPasso( TIPO_MOTOR_PASSO tipoMotor )
{
    IMotorPasso* retorno;

    switch( tipoMotor )
    {
    case MOTOR_PASSO_PROTEUS: retorno = &motorProteus; break;
    case MOTOR_PASSO_GOIAS: retorno = 0; break;
    default: retorno = 0;
    }

    return retorno;
}