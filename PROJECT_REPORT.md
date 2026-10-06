# Project Report — IoT-Based Home Automation System

## 1. Introduction
The project demonstrates an IoT-based home automation prototype using ESP8266. A browser dashboard communicates with the ESP8266 over Wi-Fi to control relay outputs and display sensor readings.

## 2. Problem Statement
Traditional appliance control can require physical interaction. The proposed system provides a simple network-based interface for remote control and environmental monitoring within a local Wi-Fi network.

## 3. Objectives
- Control home appliances using ESP8266.
- Monitor temperature and humidity.
- Monitor ambient light level.
- Provide a simple browser interface.
- Demonstrate IoT communication and automation concepts.

## 4. Methodology
The ESP8266 connects to the local Wi-Fi network and hosts a small web server. The browser sends control requests to the ESP8266. Relay outputs are switched according to the user's command. Sensor readings are periodically returned to the dashboard.

## 5. Hardware
ESP8266 NodeMCU, DHT11, LDR, relay module, breadboard, jumper wires and suitable low-voltage test loads.

## 6. Software
Arduino IDE, ESP8266 Wi-Fi/WebServer libraries and DHT sensor library.

## 7. Result
The prototype provides browser-based ON/OFF control and displays temperature, humidity and LDR readings.

## 8. Safety
Do not connect mains electricity directly to a breadboard or development board. Use professionally rated isolated relay hardware, suitable enclosures and qualified supervision for mains applications.
