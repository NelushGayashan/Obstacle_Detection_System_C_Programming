#include "Alarm.h"

// Function to initialize the alarm system
void Alarm_init(Alarm *alarm, unsigned char buzzer_pin, unsigned char vibrator_pin)
{
    alarm->buzzer_pin = buzzer_pin;
    alarm->vibrator_pin = vibrator_pin;
    P1 = ~(1 << alarm->buzzer_pin); // Set pins to low
    P1 = ~(1 << alarm->vibrator_pin);
}

// Function to activate the alarm system
void Alarm_activate(Alarm *alarm)
{
    P1 = (1 << alarm->buzzer_pin);    // Turn on buzzer
    P1 = (1 << alarm->vibrator_pin);  // Turn on vibrator
    delay_ms(1000);                   // Keep alarm active for 1 second
    P1 = ~(1 << alarm->buzzer_pin);   // Turn off buzzer
    P1 = ~(1 << alarm->vibrator_pin); // Turn off vibrator
}
