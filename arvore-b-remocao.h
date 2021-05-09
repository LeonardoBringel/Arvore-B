#ifndef _ARVOREBREMOCAO_H
#define _ARVOREBREMOCAO_H

#include "arvore-b.h"

#define DEBUG 1

STACK* remove_chave(STACK* stack, int valor);
int is_underflow(STACK* stack);
STACK* underflow(STACK* stack);

#endif