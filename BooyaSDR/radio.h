// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

#ifndef RADIO_H
#define RADIO_H

enum radioMode { Silent = 0, AM = 1, DSB = 2,LSB = 3,USB = 4, CW = 5};

class radioControlClass {
public:
    radioControlClass();
    bool radioOn;       // radio on flag
    PUCHAR *buffers;    // pointer to all input buffers
    int bufIdx;         // index to next buffer to be processed
    int cnt;            // count of input buffer to be processed
    long lastThread;    // last thread previous to the current to have been started
    float AMkHz;        // radio tune frequency in kHz
    float ffHz;         // fine radio tune frequency 100 Hz
    enum radioMode mode;// current radio mode
    bool newMode;       // new Mode flag
    int gain;           // gain scale factor
    void (*pradioThreadf(void *arg));
};

class agc {
public:
    agc();
    bool on = true;
    float AMmean;
    float scale,scaleDefault;

};

extern class agc AGC;
extern class radio Radio;
extern class radioControlClass radioCntrl;

void initRadio( void );
void initRadioThread(void );

void *radioThreadf(void *arg);

void radioTurnOn(void);
void radioTurnOff(void);
bool radioIsOn(void);
void radioDataArrived(void);

void scaleRadiof( int sf );

typedef struct{ float real; float imag; } COMPLEX;

#endif
