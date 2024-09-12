#include "park.h"
#include "svgen.h"

#define SQRT3_BY2     (float)0.866025403788

void CalcRefVec(void)
{
    SVGenParm.a = ParkParm.Vbeta;
    SVGenParm.b = (-ParkParm.Vbeta/2 + SQRT3_BY2 * ParkParm.Valpha);
    SVGenParm.c = (-ParkParm.Vbeta/2 - SQRT3_BY2 * ParkParm.Valpha);    
}


