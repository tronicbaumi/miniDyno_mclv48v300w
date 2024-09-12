#include "svgen.h"


tSVGenParm SVGenParm;  

float T1, T2, Ta, Tb, Tc;
float dPWM1, dPWM2, dPWM3;

void CalcTimes(void)
{
    T1 = SVGenParm.PWMPeriod * T1;
    T2 = SVGenParm.PWMPeriod * T2;
    Tc = (SVGenParm.PWMPeriod-T1-T2)/2;
    Tb = Tc + T1;
    Ta = Tb + T2;    
} 

void CalcSVGen( void )
{
    if(SVGenParm.a < 0) // jCalcRef20
    {
        if(SVGenParm.b < 0)
        {
            // jCalcRef30       
            // Must be Sector 4 since Sector 0 not allowed
            // Sector 4: (1,0,0)  180-240 degrees            
            T2 = -SVGenParm.a;
            T1 = -SVGenParm.b;
            
            CalcTimes();
            
            dPWM1 = Tc;
            dPWM2 = Tb;
            dPWM3 = Ta;           
        }
        else 
        {
            if(SVGenParm.c < 0)
            {
                // jCalcRef25
                // Sector 2: (0,1,0)  300-360 degrees
                T2 = -SVGenParm.c;
                T1 = -SVGenParm.a;

                CalcTimes();

                dPWM1 = Ta;
                dPWM2 = Tc;
                dPWM3 = Tb;            
            }
            else
            {
                // jCalcRef20
                // Sector 6: (1,1,0)  240-300 degrees
                T2 = SVGenParm.c;
                T1 = SVGenParm.b;

                CalcTimes();

                dPWM1 = Tb;
                dPWM2 = Tc;
                dPWM3 = Ta;                
            }
        }
    }
    else
    {
        if(SVGenParm.b < 0)
        {
            if(SVGenParm.c < 0)
            {
                // jCalcRef15
                // Sector 1: (0,0,1)  60-120 degrees
                T2 = -SVGenParm.b;
                T1 = -SVGenParm.c;

                CalcTimes();

                dPWM1 = Tb;
                dPWM2 = Ta;
                dPWM3 = Tc;                
            }
            else
            {
                // jCalcRef10    
                // Sector 5: (1,0,1)  120-180 degrees
                T2 = SVGenParm.a;
                T1 = SVGenParm.c;

                CalcTimes();

                dPWM1 = Tc;
                dPWM2 = Ta;
                dPWM3 = Tb;                  
            }
        }
        else
        {
            // Sector 3: (0,1,1)  0-60 degrees
            T2 = SVGenParm.b;
            T1 = SVGenParm.a;

            CalcTimes();

            dPWM1 = Ta;
            dPWM2 = Tb;
            dPWM3 = Tc;            
        }
    }
}

/*
void CalcTimes(void)
{
    T1 = SVGenParm.PWMPeriod * T1;
    T2 = SVGenParm.PWMPeriod * T2;
    Tc = (SVGenParm.PWMPeriod-T1-T2)/2;
    Tb = Tc + T2;
    Ta = Tb + T1;    
}  


void CalcSVGen( void )
{
    if( SVGenParm.Vr1 >= 0 )
        {       
        // (xx1)
        if( SVGenParm.Vr2 >= 0 )
            {
            // (x11)
            // Must be Sector 3 since Sector 7 not allowed
            // Sector 3: (0,1,1)  0-60 degrees
            T1 = SVGenParm.Vr2;
            T2 = SVGenParm.Vr1;
            CalcTimes();
            dPWM1 = Ta;
            dPWM2 = Tb;
            dPWM3 = Tc;
            }
        else
            {            
            // (x01)
            if( SVGenParm.Vr3 >= 0 )
                {
                // Sector 5: (1,0,1)  120-180 degrees
                T1 = SVGenParm.Vr1;
                T2 = SVGenParm.Vr3;
                CalcTimes();
                dPWM1 = Tc;
                dPWM2 = Ta;
                dPWM3 = Tb;

                }
            else
                {
                // Sector 1: (0,0,1)  60-120 degrees
                T1 = -SVGenParm.Vr2;
                T2 = -SVGenParm.Vr3;
                CalcTimes();
                dPWM1 = Tb;
                dPWM2 = Ta;
                dPWM3 = Tc;
                }
            }
        }
    else
        {
        // (xx0)
        if( SVGenParm.Vr2 >= 0 )
            {
            // (x10)
            if( SVGenParm.Vr3 >= 0 )
                {
                // Sector 6: (1,1,0)  240-300 degrees
                T1 = SVGenParm.Vr3;
                T2 = SVGenParm.Vr2;
                CalcTimes();
                dPWM1 = Tb;
                dPWM2 = Tc;
                dPWM3 = Ta;
                }
            else
                {
                // Sector 2: (0,1,0)  300-0 degrees
                T1 = -SVGenParm.Vr3;
                T2 = -SVGenParm.Vr1;
                CalcTimes();
                dPWM1 = Ta;
                dPWM2 = Tc;
                dPWM3 = Tb;
                }
            }
        else
            {            
            // (x00)
            // Must be Sector 4 since Sector 0 not allowed
            // Sector 4: (1,0,0)  180-240 degrees
            T1 = -SVGenParm.Vr1;
            T2 = -SVGenParm.Vr2;
            CalcTimes();
            dPWM1 = Tc;
            dPWM2 = Tb;
            dPWM3 = Ta;

            }
        }
}
*/

/*
void CalcTimes(void)
{
    T1 = SVGenParm.PWMPeriod * T1;
    T2 = SVGenParm.PWMPeriod * T2;
    Tc = (SVGenParm.PWMPeriod-T1-T2)/2;
    Tb = Tc + T1;
    Ta = Tb + T2;
}   

void CalcSVGen( void )
{
    if( SVGenParm.Vr1 < 0 )
        {       
        if( SVGenParm.Vr2 < 0 )
            {
                T2 = -SVGenParm.Vr1;
                T1 = -SVGenParm.Vr2;
                CalcTimes();
                dPWM1 = Tc;
                dPWM2 = Tb;
                dPWM3 = Ta;
            }
        else
            {            
            if( SVGenParm.Vr3 < 0 )
                {
                    T2 = -SVGenParm.Vr3;
                    T1 = -SVGenParm.Vr1;
                    CalcTimes();
                    dPWM1 = Ta;
                    dPWM2 = Tc;
                    dPWM3 = Tb;
                }
            else
                {
                    T1 = SVGenParm.Vr2;
                    T2 = SVGenParm.Vr3;
                    CalcTimes();
                    dPWM1 = Tb;
                    dPWM2 = Tc;
                    dPWM3 = Ta;
                }
            }
        }
    else
        {
        if( SVGenParm.Vr2 < 0 )
            {
            if( SVGenParm.Vr3 < 0 )
                {
                    T1 = -SVGenParm.Vr3;
                    T2 = -SVGenParm.Vr2;
                    CalcTimes();
                    dPWM1 = Tb;
                    dPWM2 = Ta;
                    dPWM3 = Tc;
                }
            else
                {
                    T1 = SVGenParm.Vr3;
                    T2 = SVGenParm.Vr1;
                    CalcTimes();
                    dPWM1 = Tc;
                    dPWM2 = Ta;
                    dPWM3 = Tb;
                }
            }
        else
            {            
                T1 = SVGenParm.Vr1;
                T2 = SVGenParm.Vr2;
                CalcTimes();
                dPWM1 = Ta;
                dPWM2 = Tb;
                dPWM3 = Tc;
            }
        }
}
*/