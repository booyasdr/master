// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

#ifndef MAIN_LOOP_H
#define MAIN_LOOP_H

#include <pthread.h>
#include <windows.h>

extern int              idx;
extern unsigned long    IDX;
extern PUCHAR	        *buffers;
extern pthread_mutex_t  mutexShowStats;     // export to main_loop_fx2
extern unsigned long    BytesXferred ;
extern LARGE_INTEGER    StartingTime;

#define	QUEUE_SIZE 16

int init_main_loop(void);
int start_main_loop(void);
int start_main_loop(void *main_loop(void *arg));

void *main_loop(void *arg);
void *fake_main_loop(void *arg);

#endif

