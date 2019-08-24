#include "cyu3externcstart.h"
//#include "cyu3types.h"
#include "cyu3usbconst.h"
#include "cyu3usb.h"

void CyFxAppErrorHandler (  CyU3PReturnStatus_t apiRetStatus );
CyBool_t CyFxApplnLPMRqtCB ( CyU3PUsbLinkPowerMode link_mode);
void CyFxSlFifoApplnDebugInit (void);
void setDescriptors(void);
