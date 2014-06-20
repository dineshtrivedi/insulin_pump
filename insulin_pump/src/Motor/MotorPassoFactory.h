#ifndef MOTORPASSOFACTORY_H
#define MOTORPASSOFACTORY_H

#include "IMotorPasso.h"

#ifdef __cplusplus
extern "C"
#endif
IMotorPasso* getMotorPasso( TIPO_MOTOR_PASSO tipoMotor );

#endif // MOTORPASSOFACTORY_H