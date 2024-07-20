#include "UltrasonicSensor.h"
#include <reg51.h> // Include the appropriate header file for the 8051 microcontroller

#define SOUND_SPEED 0.0343 // Speed of sound in cm/µs (approximate)

// Function to initialize the ultrasonic sensor
void UltrasonicSensor_init(UltrasonicSensor *sensor, unsigned char trigger_pin, unsigned char echo_pin)
{
    sensor->trigger_pin = trigger_pin;
    sensor->echo_pin = echo_pin;
    P1 &= ~(1 << sensor->trigger_pin); // Set trigger pin to low
}

// Function to get distance from the ultrasonic sensor
unsigned int UltrasonicSensor_getDistance(UltrasonicSensor *sensor)
{
    unsigned int distance = 0;
    unsigned long duration;

    // Send a 10µs pulse to the trigger pin
    P1 |= (1 << sensor->trigger_pin);  // Set trigger pin high
    delay_us(10);                      // Delay for 10µs
    P1 &= ~(1 << sensor->trigger_pin); // Set trigger pin low

    // Wait for the pulse to start
    while (!(P1 & (1 << sensor->echo_pin)))
        ;                                    // Wait for echo pin to go high
    unsigned long pulse_start = get_timer(); // Record the start time

    // Wait for the pulse to end
    while (P1 & (1 << sensor->echo_pin))
        ;                                  // Wait for echo pin to go low
    unsigned long pulse_end = get_timer(); // Record the end time

    // Calculate pulse duration
    duration = pulse_end - pulse_start;

    // Calculate distance based on pulse duration (in cm)
    distance = (duration * SOUND_SPEED) / 2;

    return distance;
}

// Delay function (approximate, adjust as needed)
void delay_us(unsigned int us)
{
    unsigned int i;
    for (i = 0; i < us; i++)
    {
        _nop_(); // No operation instruction for the delay
    }
}

// Timer initialization (assumes Timer 0)
void init_timer()
{
    TMOD |= 0x01; // Set Timer 0 in mode 1 (16-bit)
    TH0 = 0;      // Set high byte
    TL0 = 0;      // Set low byte
    TR0 = 1;      // Start Timer 0
}

// Get timer value
unsigned long get_timer()
{
    unsigned long timer_value;
    timer_value = (TH0 << 8) | TL0; // Combine high and low byte
    return timer_value;
}
