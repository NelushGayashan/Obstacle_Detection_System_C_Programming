# Obstacle Detection System with C Programming

This project implements an obstacle detection system using an ultrasonic sensor and a water sensor, programmed in C for the 8051 microcontroller.

## Project Overview

This project demonstrates how to interface and use two types of sensors:

1. **Ultrasonic Sensor**: Measures the distance to an obstacle using sound waves.
2. **Water Sensor**: Measures the water level or presence using an ADC.

## Files

- `UltrasonicSensor.h` / `UltrasonicSensor.c`: Contains code for interfacing with the ultrasonic sensor.
- `WaterSensor.h` / `WaterSensor.c`: Contains code for interfacing with the water sensor.
- `README.md`: This file, providing an overview and instructions for the project.

## Prerequisites

- **8051 Microcontroller**: Ensure you have a development board with an 8051 microcontroller.
- **ADC Module**: Required for interfacing with the water sensor.
- **Ultrasonic Sensor**: For measuring distances.
- **Water Sensor**: For detecting water levels.

## Hardware Connections

1. **Ultrasonic Sensor**:
   - Trigger Pin: Connect to a digital output pin.
   - Echo Pin: Connect to a digital input pin.
   
2. **Water Sensor**:
   - Output Pin: Connect to an ADC channel input.

## Software Setup

1. **Initialize the ADC**:
   - Ensure that the `ADC_init()` function in `WaterSensor.c` is properly configured according to your ADC hardware specifications.

2. **Include the Header Files**:
   - Include `UltrasonicSensor.h` and `WaterSensor.h` in your main program file to use the sensor functions.

3. **Compile and Upload**:
   - Compile the code using an appropriate C compiler for the 8051 microcontroller.
   - Upload the compiled code to your microcontroller using a programmer.

## Usage

### Ultrasonic Sensor

**Initialization**:
```c
UltrasonicSensor mySensor;
UltrasonicSensor_init(&mySensor, trigger_pin, echo_pin);
```

**Get Distance**:
```c
unsigned int distance = UltrasonicSensor_getDistance(&mySensor);
```

### Water Sensor

**Initialization**:
```c
WaterSensor myWaterSensor;
WaterSensor_init(&myWaterSensor, adc_channel);
```

**Get Water Level**:
```c
unsigned int waterLevel = WaterSensor_getValue(&myWaterSensor);
```

## Notes

- Ensure that the sensor pin numbers and ADC channels are correctly assigned based on your hardware setup.
- Adjust the ADC initialization and reading functions as per your ADC module specifications.

## Contributing

If you have suggestions or improvements, feel free to contribute by opening an issue or submitting a pull request.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.
