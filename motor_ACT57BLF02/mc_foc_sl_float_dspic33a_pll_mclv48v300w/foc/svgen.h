#ifndef SVGEN_H
#define SVGEN_H

#include "sineTable.h"

typedef struct {
    float   PWMPeriod;

    float   a;
    float   b;
    float   c;

    } tSVGenParm;

extern tSVGenParm SVGenParm;    
extern float dPWM1, dPWM2, dPWM3;
//------------------  C ASVGen for SVGen routines ---------------------

void CalcSVGen( void );


#endif



