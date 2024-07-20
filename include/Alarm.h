#ifndef ALARM_H
#define ALARM_H

#include <reg51.h>

// Alarm System Class
typedef struct
{
    unsigned char buzzer_pin;
    unsigned char vibrator_pin;
} Alarm;

// Function prototypes
void Alarm_init(Alarm *alarm, unsigned char buzzer_pin, unsigned char vibrator_pin);
void Alarm_activate(Alarm *alarm);

#endif // ALARM_H
