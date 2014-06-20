#ifndef IINSULIN_PUMP_H
#define IINSULIN_PUMP_H

#include "../config/GlobalConfig.h"

extern unsigned int m_quantidade_injetada_total;
extern unsigned int m_quantidade_injetada_hora;
extern int m_intervalo_segundos_inteiro_para_injecao;
extern boolean m_injetar_habilitada;
extern int m_contador_injetar;
extern boolean m_flag_injetar;
extern boolean m_flag_mudou_hora;

typedef struct{
    void (*initialize)();
    void (*inject)();
    void (*start)();
    void (*stop)();
    int (*getQuantidadeInjetadaHora) ();
} IInsulinPump;

#endif