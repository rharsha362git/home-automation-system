# 🏠 IoT-Based Home Automation System Using ESP8266

A beginner-friendly IoT project that uses an **ESP8266 NodeMCU** to control appliances through a browser-based dashboard while monitoring temperature, humidity, and light intensity.

> **Safety:** The example is designed for learning and low-voltage testing. Mains-voltage wiring should only be performed by a qualified person using appropriate isolation, enclosures, fusing, and protection.

## ✨ Features

- Wi-Fi based appliance control
- Browser dashboard hosted by ESP8266
- Light ON/OFF control
- Fan ON/OFF control
- DHT11 temperature monitoring
- DHT11 humidity monitoring
- LDR light-level monitoring
- Real-time status updates

## 🧩 Components

| Component | Quantity |
|---|---:|
| ESP8266 NodeMCU | 1 |
| DHT11 sensor | 1 |
| LDR sensor | 1 |
| 2/4-channel relay module | 1 |
| Breadboard | 1 |
| Jumper wires | As required |
| Low-voltage test loads/LEDs | As required |

## 🔧 Suggested Pin Connections

| Device | ESP8266 Pin |
|---|---|
| DHT11 DATA | D4 |
| Light relay input | D1 |
| Fan relay input | D2 |
| LDR analog output | A0 |

Use a suitable voltage supply and verify your exact module's pinout before connecting anything.

## 🚀 How to Run

1. Install the Arduino IDE.
2. Add ESP8266 board support.
3. Install the **DHT sensor library**.
4. Open `Arduino_Code/Home_Automation.ino`.
5. Replace `YOUR_WIFI_NAME` and `YOUR_WIFI_PASSWORD`.
6. Select your ESP8266 board and COM port.
7. Upload the code.
8. Open Serial Monitor at **115200 baud**.
9. Copy the IP address shown by the ESP8266 into a browser connected to the same Wi-Fi network.
10. Use the dashboard to control the demo outputs and view sensor readings.

## 🏗️ System Flow

`Browser → Wi-Fi Router → ESP8266 → Relay → Load`

`DHT11 → ESP8266 → Dashboard`

`LDR → ESP8266 → Dashboard`

## 📂 Repository Structure

```text
home-automation-system/
├── Arduino_Code/
│   └── Home_Automation.ino
├── Web_Dashboard/
│   └── index.html
├── Images/
│   └── project-poster.png
├── Documentation/
│   └── PROJECT_REPORT.md
└── README.md
```

## 🎯 Applications

- Smart room automation
- Energy-aware appliance control
- IoT learning and prototyping
- Environmental monitoring
- Educational embedded/IoT projects

## 🔮 Future Scope

- Mobile application
- MQTT/cloud connectivity
- Voice assistant integration
- Energy-consumption monitoring
- User authentication
- Automatic control based on sensor thresholds

## 👨‍💻 Author

**Harsha Reddy**
