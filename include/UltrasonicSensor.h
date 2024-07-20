#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H

#include <reg51.h>

// Ultrasonic Sensor Class
typedef struct
{
    unsigned char trigger_pin;
    unsigned char echo_pin;
} UltrasonicSensor;

// Function prototypes
void UltrasonicSensor_init(UltrasonicSensor *sensor, unsigned char trigger_pin, unsigned char echo_pin);
unsigned int UltrasonicSensor_getDistance(UltrasonicSensor *sensor);

#endif // ULTRASONIC_SENSOR_H
