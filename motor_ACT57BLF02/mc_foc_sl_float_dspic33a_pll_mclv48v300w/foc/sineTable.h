#ifndef _SINE_TABLE_HEADER
#define _SINE_TABLE_HEADER

#include <stdint.h>
#include <math.h>

//typedef unsigned int uint32_t;

#define TOTAL_SINE_TABLE_ANGLE      (2*M_PI)
#define TABLE_SIZE      256
#define ANGLE_STEP      (float)((float)TOTAL_SINE_TABLE_ANGLE/(float)TABLE_SIZE)

extern const float sineTable[TABLE_SIZE];
extern const float cosineTable[TABLE_SIZE];

void SinCos(void);


#endif