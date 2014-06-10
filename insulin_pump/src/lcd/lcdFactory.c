#include "lcdFactory.h"
#include "lcd4bits2x16/lcd4bits2x16.h"

#ifdef __cplusplus
extern "C"
#endif
ILcd* getLcd( LCD_TYPE tipo )
{
    ILcd* retorno;

    switch( tipo )
    {
    case LCD_4BITS_2X16: retorno = &lcd4bits2x16; break;
    default: retorno = 0;
    }

    return retorno;
}