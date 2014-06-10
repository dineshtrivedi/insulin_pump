#ifndef LCDFACTORY_H
#define LCDFACTORY_H

#include "lcd.h"

#ifdef __cplusplus
extern "C"
#endif
ILcd* getLcd( LCD_TYPE tipo );

#endif // LCDFACTORY_H