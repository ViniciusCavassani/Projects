# ESP32 Gas Monitoring System (MQ-2 + LCD + Buzzer)

This project is a gas monitoring system using an ESP32 and an MQ-2 gas sensor. It measures air quality and displays the result on an LCD screen, while also triggering an alert using a buzzer when gas levels become dangerous.

## Features
- Real-time gas level monitoring
- LCD display (I2C) for air quality status
- Buzzer alert for dangerous gas levels
- Serial output for debugging

## Technologies Used
- ESP32
- MQ-2 Gas Sensor
- LCD 16x2 with I2C interface
- Arduino (C/C++)
- Analog signal reading

## How It Works
The MQ-2 sensor reads gas concentration and sends an analog signal to the ESP32.

Based on the sensor value, the system classifies air quality:

- Very Good → Safe environment
- Good → Low gas presence
- Bad → Moderate gas presence
- Danger → High gas concentration (buzzer activated)

The result is shown on the LCD and also printed in the Serial Monitor.

## Alert System
When gas levels exceed the safe threshold:
- The LCD displays "DANGER!"
- The buzzer is activated

## Pin Configuration
- MQ-2 Sensor → GPIO 34 (Analog input)
- Buzzer → GPIO 5
- LCD → I2C (0x27)

## Code
The full code is available in this repository.

## Future Improvements
- Add Wi-Fi for remote monitoring
- Send alerts to mobile devices
- Store data for analysis
