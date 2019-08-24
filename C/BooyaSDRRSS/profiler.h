// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

#ifndef PROFILER_H
#define PROFILER_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include "global.h"

#define MAXCLASS 20
#define MAXTHREAD 20

extern class profileClass profiler;

class profileThreadClass { // class in thread
	public:
	double rate = 0, totalThreadTime = 0, totalTime = 0;
	double startTime = 0, usedTime = 0, goTime = 0, waitTime = 0, nowTime = 0;
	private:
	bool first_time = true;

	LARGE_INTEGER Time;
	double a = 1;
	double T = 1; // filtering time constant seconds
	public:
	void init(){ // call on thread init
   	QueryPerformanceCounter(&Time);
   	startTime = (double) Time.QuadPart * count2usec;
	}

	void wait() {  // place before mutex
   	QueryPerformanceCounter(&Time);
   	nowTime = (double) Time.QuadPart * count2usec - startTime;
		if(first_time) {
			first_time = false;
	   	waitTime = nowTime;
			return;
		}
   	usedTime = nowTime - goTime;
   	waitTime = nowTime - waitTime;
   	totalThreadTime += usedTime;
   	a = exp(-waitTime/1e6/T);
   	rate = a*(usedTime/waitTime) + (1-a)*rate;
   	waitTime = nowTime;
	}
	void go(){ 	// place after mutex, initialize timer
	   QueryPerformanceCounter(&Time);
		goTime = (double) Time.QuadPart *count2usec - startTime;
	}
};

class profileClassClass { // member of class
	private:
	profileThreadClass *pthread[MAXTHREAD];
	char name[128];
	double rate, smrate;
	int Nthread = 0;

public:
// call registerThread in thread after profileThreadClass instantiated
	void registerThread( profileThreadClass *pt) {
		pthread[Nthread] = pt;
		Nthread++;
	}
// name the class on instantiation
	profileClassClass( char *cname ){ strcpy(name,cname); }
	char *report(){
		char str[1024];
		double smrate = 0, avgrate, classTime = 0, totalTime = 0;
		for(int n = 0; n < Nthread; n++) smrate += pthread[n]->rate;
		for(int n = 0; n < Nthread; n++) classTime += pthread[n]->totalThreadTime;
		double nowTime = pthread[0]->nowTime;
		for(int n = 1; n < Nthread; n++) nowTime // get maximum
			= (nowTime > pthread[n]->totalThreadTime ? nowTime : pthread[n]->totalThreadTime);
		double startTime = pthread[0]->startTime;
		for(int n = 1; n < Nthread; n++) startTime // get minimum
			= (startTime < pthread[n]->startTime ? startTime : pthread[n]->startTime);
		avgrate = classTime/(nowTime );
		sprintf(str,"%s avg %f sm %f;", name,avgrate,smrate);
		return(str);
	}	// call from
};

class profileClass {
	profileClassClass *pclass[MAXCLASS];
	int Nclass = 0;

//	void init(double st){startTime = st;};
	char s[1024] = {'\0'};
public:
	void registerClass( profileClassClass *inpclass) { //call in class init

		pclass[Nclass] = inpclass;
		Nclass++;
	}
	   void report(void ) {
	      return;
   	s[0] = '\0';
		for(int n = 0; n < Nclass; n ++) strcat(s,pclass[n]->report());
		strcat(s,"\n");
		printf(s);
	   }
};

#endif
