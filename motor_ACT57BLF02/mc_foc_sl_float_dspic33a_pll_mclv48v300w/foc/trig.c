#include "sineTable.h"
#include "park.h"

tSincosParm	SincosParm;
uint16_t theta_d=0,i_theta_d=0;
float sin_d=0,cos_d=0;
void SinCos(void)

{ 
    uint16_t temp3=0;
    float temp4 = 0;
    temp4 =(0.5)*40.96*SincosParm.wmr/314.159265;  //50us*16384*50	//1/(2*pi*50)
			theta_d = (int)((float)theta_d + (temp4));
			theta_d = theta_d&0x3FFF;
			i_theta_d = theta_d>>6;
			sin_d = sineTable[i_theta_d];
			temp3 = theta_d + 4096;
			temp3 = temp3&0x3FFF;
			temp3 = temp3>>6;
			cos_d = sineTable[temp3];
            SincosParm.Sin = sin_d;
            SincosParm.Cos = cos_d;

    
}