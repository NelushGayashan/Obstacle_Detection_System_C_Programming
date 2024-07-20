#ifndef WATER_SENSOR_H
#define WATER_SENSOR_H

#include <reg51.h>

// Water Sensor Class
typedef struct
{
    unsigned char pin;
} WaterSensor;

// Function prototypes
void WaterSensor_init(WaterSensor *sensor, unsigned char pin);
unsigned int WaterSensor_getValue(WaterSensor *sensor);

#endif // WATER_SENSOR_H
