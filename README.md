# Car-Parking-Sensor-System-using-ATmega32
This project implements a car parking sensor system designed with the ATmega32 microcontroller, an ultrasonic sensor, a 16x2 LCD display, LEDs, and a buzzer. The system helps drivers detect obstacles while parking by measuring the distance to nearby objects and providing real-time visual and auditory alerts.

Features
- Ultrasonic Distance Measurement: Measures the distance to nearby obstacles using an HC-SR04 ultrasonic sensor.
- LCD Display: Displays the measured distance in centimeters. Shows "Stop" if the distance is less than 5 cm.
- LED Indicators: Three LEDs (Red, Green, Blue) light up based on proximity, offering a visual cue.
- Buzzer Alert: Sounds when an obstacle is dangerously close (<= 5 cm).
- Dynamic LED Behavior: LEDs turn ON/OFF based on distance thresholds for intuitive guidance.

Project Components
- Microcontroller: ATmega32 operating at 16 MHz.
- Ultrasonic Sensor: HC-SR04 for obstacle distance measurement.
- LCD Display: 16x2 LCD for real-time distance feedback.
- LEDs and Buzzer: Visual and auditory proximity alerts.

Driver Architecture
The project follows a layered architecture for modularity:

- GPIO Driver: Used for general-purpose input/output.
- ICU Driver: Configured to detect rising edge signals with a frequency setting of F_CPU/8, managing the pulse timing for distance calculation.
- Buzzer Driver: Controls buzzer activation for close-range alerts.
- LCD Driver: Operates in 4-bit mode for displaying distance and status messages.
- Ultrasonic Driver: Manages ultrasonic sensor operation, triggering pulses, and calculating distances based on reflected signal timing.

System Overview
- The ultrasonic sensor emits a wave and detects reflections from obstacles.
- The ATmega32 microcontroller calculates the distance based on the time delay of the reflected wave.
- The LCD displays the distance and shows "Stop" if below 5 cm.
- LEDs and buzzer behavior dynamically change as the distance to an obstacle decreases, guiding the driver to stop in time.

Configuration
- LCD: Configured in 4-bit mode.
- Pin Connections: Detailed pin mappings for ATmega32 ports to peripherals.
