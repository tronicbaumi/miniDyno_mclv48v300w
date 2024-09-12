#include "park.h"


void InvPark(void)
{
    ParkParm.Valpha =  (float)(ParkParm.Vd*ParkParm.Cos - ParkParm.Vq*ParkParm.Sin);
    ParkParm.Vbeta  =  (float)(ParkParm.Vd*ParkParm.Sin + ParkParm.Vq*ParkParm.Cos);       
}