#ifndef _OTHER_HEADERS
#define _OTHER_HEADERS

void InvPark(void);
void CalcRefVec(void);
void Clarke(void);
void Park(void);

typedef struct 
{
    float   Angle;
    float   Sin;
    float   Cos;
    float   Ia;
    float   Ib;
    float   Ialpha;
    float   Ibeta;
    float   Id;
    float   Iq;
    float   Vd;
    float   FW_Vd;
    float   Vq;
    float   FW_Vq;
    float   Valpha;
    float   Vbeta;
    float   V1;
    float   V2;
    float   V3;
} tParkParm;

typedef struct 
{
    float   Angle;
    float   Sin;
    float   Cos;
    float   wmr;
    int  openLoop;
} tSincosParm;
    
extern tParkParm		ParkParm;
extern tSincosParm	SincosParm;


#endif

