#ifndef OPENFX2_H
#define OPENFX2_H 1

#include "fx2dev.h"

extern CypressFX2Device fx2dev;
void *main_loop_fx2(void *arg);
int openFX2(void);

#endif  /* OPENFX2_H */
