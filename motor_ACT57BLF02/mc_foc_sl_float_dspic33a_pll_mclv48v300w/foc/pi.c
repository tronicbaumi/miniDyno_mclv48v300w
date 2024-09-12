#include "pi.h"

void CalcPI( tPIParm *pParm)
{
    float Err;
    float U;
    float Exc;
    
    Err  = pParm->qInRef - pParm->qInMeas;
    //Err = Err/2.24;
    U  = pParm->qdSum + pParm->qKp * Err ;
    if( U > pParm->qOutMax )
        pParm->qOut = pParm->qOutMax;
    else if( U < pParm->qOutMin )
        pParm->qOut = pParm->qOutMin;
    else        
        pParm->qOut = U;
    
    Exc = U - pParm->qOut;
    pParm->qdSum = pParm->qdSum + pParm->qKi * Err - pParm->qKc * Exc;
}


void InitPI( tPIParm *pParm)
{
    pParm->qdSum = 0;
    pParm->qOut = 0;
}
