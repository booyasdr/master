// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

#include "record.h"

recordClass record;

pthread_t thread_record[N_RECORD];
void *recordThreadf(void *args){
    record.doRecord();
    pthread_exit(NULL);
}

