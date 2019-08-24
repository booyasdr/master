/* BY FIFO Synchronous mode  */
#include "cyfxslfifosyncmulti.h"
#include "gpifmin.h"

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;

CyU3PThread slFifoAppThread;	        /* Slave FIFO application thread structure */
CyU3PDmaMultiChannel DMAChannelHandle;   /* DMA Channel handle for P2U transfer. */

#define ResetDevice() do { *(volatile uint32_t *)0xe0050000 &= ~(1<<31); } while(1)

uint32_t glDMARxCount = 0;               /* Counter to track the number of buffers received from USB. */
uint32_t glDMATxCount = 0;               /* Counter to track the number of buffers sent to USB. */
CyBool_t glIsApplnActive = CyFalse;      /* Whether the loopback application is active or not. */
uint8_t burstLength =0;
CyBool_t commit_buffer_failure = CyFalse;


void CyFxSlFifoPtoUDmaCallback ( // MANUAL only
        CyU3PDmaMultiChannel *chHandle, /* Handle to the DMA channel. */
        CyU3PDmaCbType_t      type,     /* Callback type.             */
        CyU3PDmaCBInput_t    *input)    /* Callback status.           */
{
    uint8_t index = 0;
    CyU3PDmaBuffer_t buf_p;
    CyU3PReturnStatus_t status = CY_U3P_SUCCESS;
    uint32_t *b;

//    if(commit_buffer_failure) return;
    if (type == CY_U3P_DMA_CB_PROD_EVENT) {
        for (index = 0; index < 2; index++) {
            status = CyU3PDmaMultiChannelGetBuffer (chHandle, &buf_p, CYU3P_NO_WAIT);
            if (status != CY_U3P_SUCCESS) {  break;  }
//            b = (uint32_t *) buf_p.buffer;
//            *(b+1) = glDMARxCount;
//            *b = (uint32_t) b;
            status = CyU3PDmaMultiChannelCommitBuffer (chHandle, buf_p.count, 0);
            if (status != CY_U3P_SUCCESS) {
                CyU3PDebugPrint (4, "CyU3PDmaChannelCommitBuffer failed, Error code = %d\n", status);
            	commit_buffer_failure = CyTrue;
            }
        }
        glDMARxCount++;        /* Increment the counter. */
    }
}

/* SET_CONF event from USB host starts this. Configures endpoints and DMA pipe. */
void CyFxSlFifoApplnStart (void) {
    uint16_t size = 0;
    CyU3PEpConfig_t epCfg;
    CyU3PDmaMultiChannelConfig_t dmaMultiConfig;
    CyU3PReturnStatus_t apiRetStatus = CY_U3P_SUCCESS;
    CyU3PUSBSpeed_t usbSpeed = CyU3PUsbGetSpeed();
    CyU3PDebugPrint (4, "Application Start\n");

    switch (usbSpeed) {
        case CY_U3P_FULL_SPEED:   size = 64;  break;
        case CY_U3P_HIGH_SPEED:   size = 512;  burstLength=1;  break;
        case  CY_U3P_SUPER_SPEED: size = 1024; burstLength=16; break;
        default:
            CyU3PDebugPrint (4, "Error! Invalid USB speed.\n");
            CyFxAppErrorHandler (CY_U3P_ERROR_FAILURE);
            break;
    }
    CyU3PMemSet ((uint8_t *)&epCfg, 0, sizeof (epCfg));
    epCfg.enable = CyTrue;
    epCfg.epType = CY_U3P_USB_EP_BULK;
    epCfg.burstLen = burstLength;
    epCfg.streams = 0;
    epCfg.pcktSize = size;
    apiRetStatus = CyU3PSetEpConfig(CY_FX_EP_CONSUMER, &epCfg);
    if (apiRetStatus != CY_U3P_SUCCESS) {
        CyU3PDebugPrint (4, "CyU3PSetEpConfig failed, Error code = %d\n", apiRetStatus);
        CyFxAppErrorHandler (apiRetStatus);
    }

	 dmaMultiConfig.size           = (0x400) * burstLength;
	 dmaMultiConfig.count          = 4;		// BY must be 4
	 dmaMultiConfig.validSckCount  = 2;
	 dmaMultiConfig.prodSckId [0]  = (CyU3PDmaSocketId_t)CY_U3P_PIB_SOCKET_0;
	 dmaMultiConfig.prodSckId [1]  = (CyU3PDmaSocketId_t)CY_U3P_PIB_SOCKET_1;
	 dmaMultiConfig.consSckId [0]  = (CyU3PDmaSocketId_t)CY_FX_CONSUMER_USB_SOCKET;
	 dmaMultiConfig.prodAvailCount = 0;
	 //     dmaMultiConfig.prodHeader     = 12;                 /* 12 byte UVC header to be added. */
	 //     dmaMultiConfig.prodFooter     = 4;                  /* 4 byte footer to compensate for the 12 byte header. */
	 dmaMultiConfig.prodHeader     = 0;                 /* 12 byte UVC header to be added. */
	 dmaMultiConfig.prodFooter     = 0;                  /* 4 byte footer to compensate for the 12 byte header. */
	 dmaMultiConfig.consHeader     = 0;
	 dmaMultiConfig.dmaMode        = CY_U3P_DMA_MODE_BYTE;

#ifdef MANUAL
	 dmaMultiConfig.notification   = CY_U3P_DMA_CB_PROD_EVENT;
	 dmaMultiConfig.cb             = CyFxSlFifoPtoUDmaCallback;
	  apiRetStatus = CyU3PDmaMultiChannelCreate (&DMAChannelHandle,
			  CY_U3P_DMA_TYPE_MANUAL_MANY_TO_ONE, &dmaMultiConfig);
     if (apiRetStatus != CY_U3P_SUCCESS) {
         /* Error handling */
         CyU3PDebugPrint (4, "DMA Channel Creation Failed, Error Code = %d\n", apiRetStatus);
         CyFxAppErrorHandler (apiRetStatus);
     }
#else // AUTO
     dmaMultiConfig.notification   = CY_U3P_DMA_CB_PROD_EVENT;
     dmaMultiConfig.cb = NULL;
       apiRetStatus = CyU3PDmaMultiChannelCreate (&DMAChannelHandle,
    		   CY_U3P_DMA_TYPE_AUTO_MANY_TO_ONE, &dmaMultiConfig);
    if (apiRetStatus != CY_U3P_SUCCESS) {
        CyU3PDebugPrint (4, "CyU3PDmaMultiChannelCreate failed, Error code = %d\n", apiRetStatus);
        CyFxAppErrorHandler(apiRetStatus);
    }
#endif
    CyU3PUsbFlushEp(CY_FX_EP_CONSUMER);
 	CyU3PGpifControlSWInput ( CyFalse   ); // do not start gpif here
    apiRetStatus = CyU3PGpifSMStart (RESET,ALPHA_RESET);
    CyU3PDebugPrint (4, "RESET = %d ALPHA_RESET = %d\n",RESET,ALPHA_RESET);
    if (apiRetStatus != CY_U3P_SUCCESS) {
        CyU3PDebugPrint (4, "CyU3PGpifSMStart failed, Error Code = %d\n",apiRetStatus);
        CyFxAppErrorHandler(apiRetStatus);
    }
 	CyU3PGpifControlSWInput ( CyFalse   ); // do not start gpif here
    apiRetStatus = CyU3PDmaMultiChannelSetXfer (&DMAChannelHandle, CY_FX_SLFIFO_DMA_RX_SIZE,0);
    if (apiRetStatus != CY_U3P_SUCCESS) {
        CyU3PDebugPrint (4, "CyU3PDmaMultiChannelSetXfer Failed, Error code = %d\n", apiRetStatus);
        CyFxAppErrorHandler(apiRetStatus);
    }
    glIsApplnActive = CyTrue;    /* Update the status flag. */
//    CyU3PGpioSetValue (59, CyFalse);
}

/* Called when a RESET or DISCONNECT event is received from the USB host.
 * Endpoints are disabled and the DMA pipe is destroyed. */
void CyFxSlFifoApplnStop (void) {
    CyU3PEpConfig_t epCfg;
    CyU3PReturnStatus_t apiRetStatus = CY_U3P_SUCCESS;
    CyU3PDebugPrint (4, "Application Stop\n");
 	CyU3PGpifControlSWInput ( CyFalse   ); // Stop GPIF
    /* Update the flag. */
    glIsApplnActive = CyFalse;
    CyU3PUsbFlushEp(CY_FX_EP_CONSUMER);
    CyU3PDmaMultiChannelDestroy (&DMAChannelHandle);
    /* Disable endpoints. */
    CyU3PMemSet ((uint8_t *)&epCfg, 0, sizeof (epCfg));
    epCfg.enable = CyFalse;
    apiRetStatus = CyU3PSetEpConfig(CY_FX_EP_CONSUMER, &epCfg);
    if (apiRetStatus != CY_U3P_SUCCESS) {
        CyU3PDebugPrint (4, "CyU3PSetEpConfig failed, Error code = %d\n", apiRetStatus);
        CyFxAppErrorHandler (apiRetStatus);
    }
}

CyBool_t CyFxSlFifoApplnUSBSetupCB ( /* Callback to handle the USB setup requests. */
        uint32_t setupdat0,
        uint32_t setupdat1
    ) {
	CyU3PDebugPrint (4, "USBSetupCB\n");
    /* Fast enumeration is used. Only requests addressed to the interface, class,
     * vendor and unknown control requests are received by this function.
     * This application does not support any class or vendor requests. */
    uint8_t  bRequest, bReqType;
    uint8_t  bType, bTarget;
    uint16_t wValue, wIndex;
    CyBool_t isHandled = CyFalse;

    /* Decode the fields from the setup request. */
    bReqType = (setupdat0 & CY_U3P_USB_REQUEST_TYPE_MASK);
    bType    = (bReqType & CY_U3P_USB_TYPE_MASK);
    bTarget  = (bReqType & CY_U3P_USB_TARGET_MASK);
    bRequest = ((setupdat0 & CY_U3P_USB_REQUEST_MASK) >> CY_U3P_USB_REQUEST_POS);
    wValue   = ((setupdat0 & CY_U3P_USB_VALUE_MASK)   >> CY_U3P_USB_VALUE_POS);
    wIndex   = ((setupdat1 & CY_U3P_USB_INDEX_MASK)   >> CY_U3P_USB_INDEX_POS);

    if (bType == CY_U3P_USB_STANDARD_RQT) {
        /* Handle SET_FEATURE(FUNCTION_SUSPEND) and CLEAR_FEATURE(FUNCTION_SUSPEND)
         * requests here. It should be allowed to pass if the device is in configured
         * state and failed otherwise. */
        if ((bTarget == CY_U3P_USB_TARGET_INTF) && ((bRequest == CY_U3P_USB_SC_SET_FEATURE)
                    || (bRequest == CY_U3P_USB_SC_CLEAR_FEATURE)) && (wValue == 0)) {
            if (glIsApplnActive)
                CyU3PUsbAckSetup ();
            else
                CyU3PUsbStall (0, CyTrue, CyFalse);
            isHandled = CyTrue;
        }
        /* CLEAR_FEATURE request for endpoint is always passed to the setup callback
         * regardless of the enumeration model used. When a clear feature is received,
         * the previous transfer has to be flushed and cleaned up. This is done at the
         * protocol level. So flush the EP memory and reset the DMA channel associated
         * with it. If there are more than one EP associated with the channel reset both
         * the EPs. The endpoint stall and toggle / sequence number is also expected to be
         * reset. Return CyFalse to make the library clear the stall and reset the endpoint
         * toggle. Or invoke the CyU3PUsbStall (ep, CyFalse, CyTrue) and return CyTrue.
         * Here we are clearing the stall. */
        if ((bTarget == CY_U3P_USB_TARGET_ENDPT) && (bRequest == CY_U3P_USB_SC_CLEAR_FEATURE)
                && (wValue == CY_U3P_USBX_FS_EP_HALT))
        {
            if (glIsApplnActive) {
                if (wIndex == CY_FX_EP_CONSUMER) {
                    CyU3PDmaMultiChannelReset (&DMAChannelHandle);
                    CyU3PUsbFlushEp(CY_FX_EP_CONSUMER);
                    CyU3PUsbResetEp (CY_FX_EP_CONSUMER);
                    CyU3PDmaMultiChannelSetXfer (&DMAChannelHandle, CY_FX_SLFIFO_DMA_RX_SIZE,0);
                }
                CyU3PUsbStall (wIndex, CyFalse, CyTrue);
                isHandled = CyTrue;
            }
        }
    } else if (bType == CY_U3P_USB_VENDOR_RQT) {
    	uint16_t u16 = (uint16_t) bRequest;
    	CyU3PDebugPrint (4, "VENDOR, REQUEST %x\n",u16);
    	CyU3PThreadSleep(10);
    	if (bRequest == 0xAA) {
            CyU3PDebugPrint (4, "START GPIF AND DMA\n");
            CyU3PDmaMultiChannelSetXfer (&DMAChannelHandle, CY_FX_SLFIFO_DMA_RX_SIZE,0);
            CyU3PGpifControlSWInput ( CyTrue   ); // Start GPIF
    	}
    	if (bRequest == 0xBB) {
            CyU3PDebugPrint (4, "STOP GPIF AND DMA\n");
         	CyU3PGpifControlSWInput ( CyFalse   ); // Stop GPIF
            CyU3PDmaMultiChannelReset (&DMAChannelHandle);
    	}
    	if (bRequest == 0xCC) {
    		glIsApplnActive = CyFalse;
        	CyU3PDebugPrint (4, "RESET DEVICE\n");
         	CyU3PGpifControlSWInput ( CyFalse   ); // Stop GPIF
            CyU3PDmaMultiChannelReset (&DMAChannelHandle);
            CyU3PUsbFlushEp(CY_FX_EP_CONSUMER);
            CyU3PUsbResetEp (CY_FX_EP_CONSUMER);
        	CyU3PConnectState (CyFalse,CyTrue); // disconnect from usb
        	ResetDevice();
    	}
    	if (bRequest == 0xDD) {
        	CyU3PDebugPrint (4, "DO NOTHING\n");
        	CyFxSlFifoApplnStop();
    	}
    	if (bRequest == 0x00) {
        	CyU3PDebugPrint (4, "Vendor Application Stop\n");
        	CyFxSlFifoApplnStop();
    	}
    }
    return isHandled;
}

void CyFxSlFifoApplnUSBEventCB (
    CyU3PUsbEventType_t evtype,
    uint16_t            evdata
    ) {
	CyU3PDebugPrint (4, "USB EVENT CB %x\n",evtype);
    switch (evtype) {
        case CY_U3P_USB_EVENT_SETCONF:
            /* Stop the application before re-starting. */
            if (glIsApplnActive) CyFxSlFifoApplnStop ();
            CyU3PUsbLPMDisable();
            CyFxSlFifoApplnStart ();
            break;
        case CY_U3P_USB_EVENT_RESET:
        case CY_U3P_USB_EVENT_DISCONNECT:
        	CyU3PDebugPrint (4, "USB EVENT CB DISCONNECT %x\n",evtype);
            if (glIsApplnActive) CyFxSlFifoApplnStop ();
            break;
        default:
            break;
    }
}

unsigned int count = 0;
int inreset = 0;
void gpif_error_cb(CyU3PPibIntrType cbType, uint16_t cbArg) {
	count++;
	if( count%2048 != 0) return;
//	if( count%256 != 0) return;

	if(cbType==CYU3P_PIB_INTR_ERROR) {
		switch (CYU3P_GET_PIB_ERROR_TYPE(cbArg)) {
			case CYU3P_PIB_ERR_THR0_WR_OVERRUN:
				CyU3PDebugPrint (4, "CYU3P_PIB_ERR_THR0_WR_OVERRUN %d\n",count);
			break;
			case CYU3P_PIB_ERR_THR1_WR_OVERRUN:
				CyU3PDebugPrint (4, "CYU3P_PIB_ERR_THR1_WR_OVERRUN %d\n",count);
			break;
			default:
			CyU3PDebugPrint (4, "PIB No Error :%d\n  %d\n",CYU3P_GET_PIB_ERROR_TYPE(cbArg),count);
				break;
		}
	}
}

// called by SlFifoAppThread_Entry
void CyFxSlFifoApplnInit (void) {	/* Initializes the GPIF interface and USB interface. */
    CyU3PPibClock_t pibClock;
    CyU3PReturnStatus_t apiRetStatus = CY_U3P_SUCCESS;
	CyU3PDebugPrint (4, "ApplicationInit\n");

    /* Initialize the p-port block. */
    pibClock.clkDiv = 2;
    pibClock.clkSrc = CY_U3P_SYS_CLK;
    pibClock.isHalfDiv = CyFalse;
    /* Disable DLL for sync GPIF */
    pibClock.isDllEnable = CyFalse;
    apiRetStatus = CyU3PPibInit(CyTrue, &pibClock);
    if (apiRetStatus != CY_U3P_SUCCESS)
    {
        CyU3PDebugPrint (4, "P-port Initialization failed, Error Code = %d\n",apiRetStatus);
        CyFxAppErrorHandler(apiRetStatus);
    }

    /* Load the GPIF configuration for Slave FIFO sync mode. */
    apiRetStatus = CyU3PGpifLoad (&CyFxGpifConfig);
    if (apiRetStatus != CY_U3P_SUCCESS) {
        CyU3PDebugPrint (4, "CyU3PGpifLoad failed, Error Code = %d\n",apiRetStatus);
        CyFxAppErrorHandler(apiRetStatus);
    }
    CyU3PGpifSocketConfigure (0,CY_U3P_PIB_SOCKET_0,6,CyFalse,1);
	CyU3PGpifSocketConfigure (1,CY_U3P_PIB_SOCKET_1,6,CyFalse,1);

    /* Start the USB functionality. */
    apiRetStatus = CyU3PUsbStart();
    if (apiRetStatus != CY_U3P_SUCCESS) {
        CyU3PDebugPrint (4, "CyU3PUsbStart failed to Start, Error code = %d\n", apiRetStatus);
        CyFxAppErrorHandler(apiRetStatus);
    }
// Register callbacks
    CyU3PPibRegisterCallback(gpif_error_cb,0xffff);
    CyU3PUsbRegisterSetupCallback(CyFxSlFifoApplnUSBSetupCB, CyTrue);
    CyU3PUsbRegisterEventCallback(CyFxSlFifoApplnUSBEventCB);
    CyU3PUsbRegisterLPMRequestCallback(CyFxApplnLPMRqtCB);    

    setDescriptors();

    /* Connect the USB Pins with super speed operation enabled. */
    apiRetStatus = CyU3PConnectState(CyTrue, CyTrue);
    if (apiRetStatus != CY_U3P_SUCCESS) {
        CyU3PDebugPrint (6, "USB Connect failed, Error code = %d\n", apiRetStatus);
        CyFxAppErrorHandler(apiRetStatus);
    }
}

// Started by CyFxApplicationDefine
void SlFifoAppThread_Entry ( uint32_t input) {
    CyFxSlFifoApplnInit();    /* Initialize the slave FIFO application */

    CyU3PReturnStatus_t apiRetStatus = CY_U3P_SUCCESS;
    CyU3PDmaSocket_t sock0,sock1,sockc;
//    CyFxSlFifoApplnDebugInit();   /* Initialize the debug module */
    uint32_t cpi = (uint32_t) DMAChannelHandle.currentProdIndex;
    uint32_t b0, b1, c0;

    for (;;) {
        CyU3PThreadSleep (1000);
        if (glIsApplnActive) {
            cpi = (uint32_t) DMAChannelHandle.currentProdIndex;
            /* Print the number of buffers received so far from the USB host. */
//            CyU3PDebugPrint (6, "ABC %d %d %u %x\n",glDMARxCount, glDMATxCount,cpi,DMAChannelHandle.currentProdIndex);
//extern CyU3PDmaSocket_t         *glDmaSocket[];       /* Array of all sockets on the device */
//*glDmaSocket[];       /* Array of all sockets on the device */
//#define CyU3PDmaGetSckNum(sckId) ((sckId) & CY_U3P_DMA_SCK_MASK)
//#define CyU3PDmaGetIpNum(sckId) \
//    (((sckId) >> CY_U3P_IP_BLOCK_POS) & CY_U3P_IP_BLOCK_MASK)
            sock0 = glDmaSocket[CyU3PDmaGetIpNum(CY_U3P_PIB_SOCKET_0)][CyU3PDmaGetSckNum(CY_U3P_PIB_SOCKET_0)];       /* Array of all sockets on the device */
            sock1 = glDmaSocket[CyU3PDmaGetIpNum(CY_U3P_PIB_SOCKET_1)][CyU3PDmaGetSckNum(CY_U3P_PIB_SOCKET_1)];       /* Array of all sockets on the device */
            sockc = glDmaSocket[CyU3PDmaGetIpNum(CY_FX_CONSUMER_USB_SOCKET)][CyU3PDmaGetSckNum(CY_FX_CONSUMER_USB_SOCKET)];       /* Array of all sockets on the device */

            b0 = sock0.activeDscr.buffer;
            b1 = sock1.activeDscr.buffer;
            c0 = sockc.activeDscr.buffer;

            CyU3PDebugPrint (6, "%x %x %x %x DMA Count %d\n",cpi, b0 >> 12, b1 >> 12 , c0 >> 12 ,glDMARxCount);
            if (CyFalse)	{
//                if (commit_buffer_failure == 1)	{

                CyU3PDebugPrint (6, "Commit buffer failure Reset 1.\n");
//            	commit_buffer_failure = 0;
//            	continue;
            	/* Stop the GPIF state machine to stop data transfers through FX3 */
//            	CyU3PGpifDisable (CyFalse);
                CyU3PGpifControlSWInput ( CyFalse   ); // Stop GPIF
            	/* Place the Endpoint in NAK mode before cleaning up the pipe. */
/*            	apiRetStatus = CyU3PUsbSetEpNak (CY_FX_EP_CONSUMER, CyTrue);
            	if (apiRetStatus != CY_U3P_SUCCESS) {
            				CyU3PDebugPrint (4, "\r EP_NAK=%d\n", apiRetStatus);
            	}
*/            	/* Reset the DMA channel and flush the endpoint pipe. */
            	apiRetStatus = CyU3PDmaMultiChannelReset (&DMAChannelHandle);
            	if (apiRetStatus != CY_U3P_SUCCESS) {
            		CyU3PDebugPrint (4, "\r DMA_RESET=%d\n", apiRetStatus);
            	 }
//            	apiRetStatus = CyU3PUsbFlushEp (CY_FX_EP_CONSUMER);
//            	if(apiRetStatus != CY_U3P_SUCCESS){
//            	   CyU3PDebugPrint (4, "\r EP_FLUSH=%d\n", apiRetStatus);
//           	  }
            	apiRetStatus = CyU3PDmaMultiChannelSetXfer (&DMAChannelHandle, 0, 0);
            	if (apiRetStatus != CY_U3P_SUCCESS) {
            				CyU3PDebugPrint (4, "\r DMA_XFER  = %d\n", apiRetStatus);
            	}
/*            	apiRetStatus = CyU3PUsbSetEpNak (CY_FX_EP_CONSUMER, CyFalse);
            	if(apiRetStatus != CY_U3P_SUCCESS) {
            		CyU3PDebugPrint (4, "\r EP_ACK=%d\n", apiRetStatus);
            	}
*///                apiRetStatus = CyU3PGpifSMStart (RESET,ALPHA_RESET);
//            	if (apiRetStatus != CY_U3P_SUCCESS)  {
//            		CyU3PDebugPrint (4, "CyU3PGpifSMStart  = %d\n", apiRetStatus);
//            	}
                CyU3PGpifControlSWInput ( CyTrue   ); // Start GPIF
//            	apiRetStatus = CyU3PGpifSMSwitch (257, 0, 257, 0, 2);
//            	if (apiRetStatus != CY_U3P_SUCCESS) {
//            		CyU3PDebugPrint (4, "CyU3PGpifSMSwitch  = %d\n", apiRetStatus);
//            	}
            	commit_buffer_failure = 0;
                CyU3PDebugPrint (6, "Commit buffer failure Reset 2.\n");
            }
        }
    }
}

// Started by Kernel, is a Kernel virtual function
void CyFxApplicationDefine (void) {	/* Application define function which creates the threads. */
    CyFxSlFifoApplnDebugInit();
	CyU3PDebugPrint (4, "ApplicationDefine\n");
    void *ptr = NULL;
    uint32_t retThrdCreate = CY_U3P_SUCCESS;
    ptr = CyU3PMemAlloc (CY_FX_SLFIFO_THREAD_STACK);    /* Allocate memory for thread */

    /* Create the thread for the application */
    retThrdCreate = CyU3PThreadCreate (&slFifoAppThread,           /* Slave FIFO app thread structure */
                          "21:Slave_FIFO_sync",                    /* Thread ID and thread name */
                          SlFifoAppThread_Entry,                   /* Slave FIFO app thread entry function */
                          0,                                       /* No input parameter to thread */
                          ptr,                                     /* Pointer to the allocated thread stack */
                          CY_FX_SLFIFO_THREAD_STACK,               /* App Thread stack size */
                          CY_FX_SLFIFO_THREAD_PRIORITY,            /* App Thread priority */
                          CY_FX_SLFIFO_THREAD_PRIORITY,            /* App Thread pre-emption threshold */
                          CYU3P_NO_TIME_SLICE,                     /* No time slice for the application thread */
                          CYU3P_AUTO_START                         /* Start the thread immediately */
                          );

    if (retThrdCreate != 0) {
    	CyU3PDebugPrint (4, "CyU3PThreadCreate failed\n");
        while(1);
    }
}

int main (void) {
    CyU3PIoMatrixConfig_t io_cfg;
    CyU3PReturnStatus_t status = CY_U3P_SUCCESS;
    CyU3PSysClockConfig_t clkCfg;
    CyU3PDebugPrint (4, "Main\n");

	/* setSysClk400 clock configurations */
	clkCfg.setSysClk400 = CyTrue;   /* FX3 device's master clock is set to a frequency > 400 MHz */
	clkCfg.cpuClkDiv = 2;           /* CPU clock divider */
	clkCfg.dmaClkDiv = 2;           /* DMA clock divider */
	clkCfg.mmioClkDiv = 2;          /* MMIO clock divider */
	clkCfg.useStandbyClk = CyFalse; /* device has no 32KHz clock supplied */
	clkCfg.clkSrc = CY_U3P_SYS_CLK; /* Clock source for a peripheral block  */
	status = CyU3PDeviceInit (&clkCfg);    /* Initialize the device */
    if (status != CY_U3P_SUCCESS)  goto handle_fatal_error;

    /* Initialize the caches. Enable instruction cache and keep data cache disabled. */
    status = CyU3PDeviceCacheControl (CyTrue, CyFalse, CyFalse);
    if (status != CY_U3P_SUCCESS)  goto handle_fatal_error;

    /* Configure the IO matrix for the device. On the FX3 DVK board, the COM port 
     * is connected to the IO(53:56). This means that either DQ32 mode should be
     * selected or lppMode should be set to UART_ONLY. Here we are choosing
     * UART_ONLY configuration for 16 bit slave FIFO configuration and setting
     * isDQ32Bit for 32-bit slave FIFO configuration. */
    io_cfg.useUart   = CyTrue;
    io_cfg.useI2C    = CyFalse;
    io_cfg.useI2S    = CyFalse;
    io_cfg.useSpi    = CyFalse;
#if (CY_FX_SLFIFO_GPIF_16_32BIT_CONF_SELECT == 0)
    io_cfg.isDQ32Bit = CyFalse;
    io_cfg.lppMode   = CY_U3P_IO_MATRIX_LPP_UART_ONLY;
#else
    io_cfg.isDQ32Bit = CyTrue;
    io_cfg.lppMode   = CY_U3P_IO_MATRIX_LPP_DEFAULT;
#endif
    /* No GPIOs are enabled. */
    io_cfg.gpioSimpleEn[0]  = 0;
//    io_cfg.gpioSimpleEn[1]  = 0x08000000; /* GPIO 59 */
    io_cfg.gpioSimpleEn[1]  = 0;
    io_cfg.gpioComplexEn[0] = 0;
    io_cfg.gpioComplexEn[1] = 0;
    status = CyU3PDeviceConfigureIOMatrix (&io_cfg);
    if (status != CY_U3P_SUCCESS) goto handle_fatal_error;

    CyU3PKernelEntry ();    /* This is a non returnable call initializing RTOS kernel */
    return 0;
handle_fatal_error: /* Cannot recover from this error. */
    while (1);
}
