# IoT Enabled Weather Monitoring System with Remote Plant Watering

This repository contains the files and resources for an IoT-enabled system that monitors weather conditions and includes a remotely operable plant watering system. It includes simulation, Arduino libraries, project documentation, and source code for hardware implementation.

---

## Project Overview

The **IoT Weather Monitoring and Plant Care System** utilizes Arduino and ESP32 to collect and analyze environmental data, including temperature and humidity. The system features real-time dashboards, simulations, and a working prototype. Additionally, it includes a remotely operable plant watering mechanism, allowing users to control irrigation via a mobile or web dashboard.

---

## Project Structure

- **Document/**: Project proposals, presentations, and reports.
  - `IoT Project Instrument.pdf`: Detailed project instructions.
  - `ETE416_project-report_Group3.pdf`: Final project report.
- **Final/**: Final implementation resources.
  - **Code/**: Source code for Arduino and ESP32.
  - **Library/**: Required Arduino libraries (e.g., DHT sensor, ESP8266).
- **Simulation/**: Simulations for hardware components and design.
  - **Code/**: Arduino sketches for weather monitoring and plant watering.
  - **Design/**: Proteus designs for the system.
  - **Proteus Library/**: Libraries for simulation tools.

---

## Features

- **Real-time Weather Data Monitoring**:
  - Temperature and humidity collection using the DHT11 sensor.
  - Visualization on a mobile/web dashboard.
- **Remotely Operable Plant Watering System**:
  - Allows users to control the irrigation system remotely via a dashboard.
  - Ensures flexibility and convenience in plant care.
- **Simulations**:
  - Proteus designs for circuit testing.
  - Arduino IDE code and compiled binaries.
- **Documentation**:
  - Detailed project instructions and implementation guides.

---

## Requirements

### Hardware:
- Arduino/ESP32
- DHT11 Sensor
- Water Pump Module

### Software:
- Arduino IDE
- Proteus Simulation Software

---

## Usage

1. **Setting Up the Hardware**:
   - Connect the DHT11 sensor and water pump to Arduino or ESP32.
   - Flash the provided code onto the microcontroller.
2. **Running the Simulation**:
   - Open the Proteus design files in Proteus.
   - Use the provided libraries to simulate the setup.
3. **Viewing Data**:
   - Use the mobile or web dashboard to monitor real-time weather data.
4. **Remotely Operable Plant Watering**:
   - Access the dashboard to remotely control the water pump and manage irrigation.

---

## File List

- **Code**:
  - `weather.ino`: Arduino sketch for weather monitoring.
  - `weather_esp32.ino`: ESP32 implementation with plant watering.
- **Libraries**:
  - `blynk-library-master.zip`: Library for Blynk mobile app integration.
  - `DHT-sensor-library-master.zip`: Library for DHT sensors.
- **Simulations**:
  - `dht11 with pump.pdsprj`: Proteus project for weather monitoring and plant watering.

---

## How to Contribute

Feel free to fork the repository and submit pull requests. Contributions to improve the code, simulations, or documentation are welcome!

---

## License

This project is licensed under the MIT License. See `LICENSE` for details.

## Acknowledgments
This project was completed as part of the **ETE-416: IoT and Industrial Automation Sessional** course at the **Chittagong University of Engineering and Technology**.
