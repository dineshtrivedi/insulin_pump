#ifndef LCD_H
#define LCD_H

typedef struct{
    char (*configure)();
    char (*write)( char, char, char* );
    char (*writeCurrentCursor)( char* );
    char (*clear)();
    char (*shitfRigth)();
    char (*shitfLeft)();
    char (*cursorOff)();
} ILcd;

typedef enum  { LCD_4BITS_2X16 = 0 } LCD_TYPE;

#endif