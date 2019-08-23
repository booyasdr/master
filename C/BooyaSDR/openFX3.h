// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

#ifndef FX3DEV_H
#define FX3DEV_H

#include "inc\CyAPI.h"

int openFX3(void);          // returns 1 on success

extern CCyFX3Device     *fx3dev;
extern CCyUSBEndPoint	*EndPt;

enum FX3Control { FX3Start = 0xaa, FX3Stop = 0xbb, FX3Reset = 0xcc };
void fx3FWControl(FX3Control command);


#endif
