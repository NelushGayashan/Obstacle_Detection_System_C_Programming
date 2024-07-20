#include "WaterSensor.h"
#include <reg51.h> // Include the header file for the 8051 microcontroller

// Function to initialize the ADC
void ADC_init()
{
    // Set ADC control registers or pins as needed
    P2 = 0x00; // configure port 2 for ADC control
}

// Function to read an ADC value from a specific channel
unsigned int ADC_read(unsigned char channel)
{
    unsigned int adc_value = 0;

    // Select the ADC channel
    P2 = (P2 & 0xF0) | (channel & 0x0F); // set ADC channel in lower nibble
    P2 |= 0x08;                          // Start ADC conversion (bit set example)

    // Wait for ADC conversion to complete
    while (!(P2 & 0x80))
        ; // poll a flag bit indicating conversion completion

    // Read the ADC value
    adc_value = P0; // ADC result is read from port 0

    return adc_value;
}

// Function to initialize the water sensor
void WaterSensor_init(WaterSensor *sensor, unsigned char pin)
{
    sensor->pin = pin;
    ADC_init(); // Initialize ADC
}

// Function to get the water sensor value
unsigned int WaterSensor_getValue(WaterSensor *sensor)
{
    unsigned int value;

    // Read ADC value from the specified channel corresponding to the sensor pin
    value = ADC_read(sensor->pin);

    return value;
}
