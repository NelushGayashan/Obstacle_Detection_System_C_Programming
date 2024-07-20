#include "UltrasonicSensor.h"
#include "WaterSensor.h"
#include "Alarm.h"

// Define pins
#define TRIGGER_PIN 0
#define ECHO_PIN 1
#define WATER_SENSOR_PIN 2
#define BUZZER_PIN 3
#define VIBRATOR_PIN 4

// Define thresholds
#define DISTANCE_THRESHOLD 30
#define WATER_THRESHOLD 500

// Delay function
void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for (i = 0; i < ms; i++)
    {
        for (j = 0; j < 123; j++)
        {
            // Do nothing, just delay
        }
    }
}

UltrasonicSensor ultrasonicSensor;
WaterSensor waterSensor;
Alarm alarm;

void main()
{
    unsigned int distance;
    unsigned int water_value;

    UltrasonicSensor_init(&ultrasonicSensor, TRIGGER_PIN, ECHO_PIN);
    WaterSensor_init(&waterSensor, WATER_SENSOR_PIN);
    Alarm_init(&alarm, BUZZER_PIN, VIBRATOR_PIN);

    while (1)
    {
        distance = UltrasonicSensor_getDistance(&ultrasonicSensor);
        water_value = WaterSensor_getValue(&waterSensor);

        if (distance < DISTANCE_THRESHOLD || water_value > WATER_THRESHOLD)
        {
            Alarm_activate(&alarm);
        }

        delay_ms(100); // Delay for stability
    }
}
