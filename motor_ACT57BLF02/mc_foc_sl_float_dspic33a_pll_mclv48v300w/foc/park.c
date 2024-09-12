#include "park.h"

tParkParm		ParkParm;

void Park(void)
{
    ParkParm.Id =  (ParkParm.Ialpha*ParkParm.Cos) + (ParkParm.Ibeta*ParkParm.Sin);
    ParkParm.Iq = (-ParkParm.Ialpha*ParkParm.Sin) + (ParkParm.Ibeta*ParkParm.Cos);
}