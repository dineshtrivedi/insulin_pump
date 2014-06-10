#ifndef IMENU_H
#define IMENU_H

static char indiceSelecionado = 0;
static char bloquearBotaoCima = 0;
static char bloquearBotaoBaixo = 0;
static char bloquearBotaoConfirmar = 0;
static char bloquearBotaoVoltarBloquear = 0;

typedef struct stIMenu{
    void (*mostrarMenu)();
    struct stIMenu* (*analisarBotoes)();
} IMenu;

#endif