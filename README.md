# Arduino_codes
TThis GitHub repository contains a collection of Arduino sketches and libraries that can be used to control various electronic devices and sensors. The code is well-commented and easy to understand, making it a great resource for anyone looking to get started with Arduino programming. The sketches include examples for controlling LEDs, servos, and LCD displays, as well as code for reading data from sensors like temperature and humidity sensors. The libraries include functions for working with common protocols like I2C and SPI. All the code is open-source and free to use for any purpose.


## Sonar Distance Measurement with Arduino and LCD Display

This project measures the distance using an ultrasonic sensor and displays the result on an I2C LCD screen. If an object is within 15 cm, it prompts a message to "Come closer"; otherwise, it displays "Hi babe."

#### Features:
- Measures distance using an **HC-SR04 Ultrasonic Sensor**.
- Displays results on a **16x2 I2C LCD**.
- Fun interactive messages based on distance thresholds.
- Real-time distance output on the **Serial Monitor**.

---

#### Components:
1. Arduino Uno or similar board.
2. HC-SR04 Ultrasonic Sensor.
3. I2C 16x2 LCD.
4. Jumper wires and breadboard.


#### Circuit Diagram:
Connect as follows:
- **Trig Pin**: Arduino Pin 9
- **Echo Pin**: Arduino Pin 10
- **I2C SDA/SCL**: Arduino A4/A5 (Uno)

#### Demo Video:
[![Sonar Distance Measurement Demo](dhakarpola.mp4)
