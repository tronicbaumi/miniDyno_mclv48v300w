#include "park.h"
#include "svgen.h"

#define ONE_BY_SQRT3     (float)0.5773502691

void Clarke(void)
{
    ParkParm.Ialpha = ParkParm.Ia;
    ParkParm.Ibeta = (ParkParm.Ia * ONE_BY_SQRT3) + (ParkParm.Ib * 2.0 * ONE_BY_SQRT3);
}


