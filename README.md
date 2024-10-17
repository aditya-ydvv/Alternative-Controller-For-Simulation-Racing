# Alternative Racing Game Controller

## Overview

This project presents an innovative alternative for controlling racing video games using a microcontroller and various sensors. The aim is to enhance the driving experience by creating a more immersive and realistic controller setup.

## Components

1. **Steering Wheel**: 
   - **Description**: A 3D-printed steering wheel calibrated with a rotary encoder for precise steering control.
   
2. **Gear Shifter**:
   - **Description**: An arcade joystick designed to mimic an H-shifter, offering a more life-like gear-changing experience.
   
3. **Acceleration Pedal**:
   - **Description**: A 3D-printed pedal integrated with a button and spring to simulate the car’s acceleration.
   
4. **Braking Mechanism**:
   - **Description**: A sound sensor that activates the brakes when it detects a loud noise (shouting or blowing).
   
5. **Housing**:
   - **Description**: A custom gear box made from incised wooden pieces that accommodates the gear shifter, electrical connections, and an Arduino Nano.

## Setup

### Hardware Requirements

- Arduino Nano
- Rotary Encoder
- Arcade Joystick
- Sound Sensor
- 3D-printed steering wheel and pedal components
- Wooden pieces for housing
- Jumper wires and other electronic components

### Wiring

1. Connect the rotary encoder, sound sensor, joystick, and buttons to the appropriate pins on the Arduino Nano.
2. Ensure proper power connections for all components.

## Code

The provided code utilizes the `Gamepad` library to manage inputs from the various controllers and send the appropriate signals to the racing game. Below is the main structure of the code:

```cpp
#include <Gamepad.h>

Gamepad gp;

// Pin definitions
#define SENSOR_PIN A0  // Arduino pin connected to sound sensor's pin
#define CLK 3
#define DT 4
#define SW 2
#define B1 A2

// Other pin definitions
int dirDown = 6;
int dirUp = 7;
int dirRight = 9;
int dirLeft = 8;

// Variables
int counter = 0;
unsigned long lastButtonPress = 0;
int sensorValue; 
int gear = 0;

// Setup function
void setup() {
  // Pin modes and interrupt setup
}

// Main loop
void loop() {
  // Reading sensor values and controlling the gamepad
}
```

### Functionality

- The steering wheel is controlled through the rotary encoder, which adjusts the left X-axis input.
- The gear shifter uses an arcade joystick to determine gear positions based on directional inputs.
- The acceleration pedal simulates acceleration through a button press.
- The sound sensor triggers the brake function when it detects loud sounds.

## Usage

1. Power on the Arduino and ensure all components are functioning.
2. Connect the Arduino to a PC or gaming console running the racing game.
3. Use the steering wheel, gear shifter, and pedal to control the vehicle in the game.
4. Activate the brakes by shouting or blowing into the sound sensor.

## Conclusion

This alternative racing controller project combines creativity and engineering to enhance the gaming experience. By integrating 3D-printed components and sensors, it offers a unique and engaging way to play racing games.

## Future Improvements

- Implement additional sensors for better feedback (e.g., force feedback).
- Design more ergonomic and visually appealing components.
- Expand compatibility with more racing games.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
