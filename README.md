# B.L.I.N.D. Sight
**Blind-spot Location Identification and Notification Device**

## Overview

B.L.I.N.D. Sight is an embedded systems project developed to improve road safety by reducing blind-spot accidents in heavy vehicles. The system continuously monitors the front, rear, left, and right blind zones using ultrasonic sensors. When an obstacle is detected within a predefined distance, the corresponding LED alert is activated, helping drivers become aware of nearby pedestrians, cyclists, or vehicles.

The project also integrates Bluetooth communication, allowing real-time distance data to be transmitted to a mobile device for monitoring and debugging.

---

## Features

- 360° blind-spot monitoring
- Real-time obstacle detection
- Visual LED alerts for each direction
- Bluetooth-based wireless monitoring
- Low-cost and scalable embedded solution
- Continuous distance measurement using ultrasonic sensors

---

## Hardware Components

- Arduino Uno
- HC-SR04 Ultrasonic Sensors (4)
- HC-05 Bluetooth Module
- LEDs
- Breadboard
- Jumper Wires
- USB Power Supply

---

## Software

- Arduino IDE
- Embedded C / Arduino C++
- SoftwareSerial Library

---

## Working Principle

Four ultrasonic sensors continuously measure the distance to nearby objects from the front, rear, left, and right sides of the vehicle. The Arduino processes these sensor readings and compares them against a predefined safety threshold.

If an obstacle enters the blind spot, the LED corresponding to that direction turns ON, providing an immediate visual warning. Simultaneously, the measured distances are transmitted over Bluetooth to a connected mobile device for real-time monitoring.

---

## Applications

- Heavy vehicles
- Trucks
- Buses
- Commercial vehicles
- Driver assistance systems
- Automotive safety

---

## Future Improvements

- Replace ultrasonic sensors with radar or LiDAR for improved accuracy.
- Add buzzer or voice alerts.
- Integrate camera-based object detection using AI.
- Develop a dedicated mobile application.
- Implement IoT-based cloud monitoring and analytics.

---

## Repository Structure

```
├── Code
│   └── blind_sight.ino
├── Images
├── Circuit_Diagram
├── Documentation
└── README.md
```

---

## Authors

Developed as an academic embedded systems project demonstrating sensor integration, real-time obstacle detection, and hardware-software interfacing using Arduino.
