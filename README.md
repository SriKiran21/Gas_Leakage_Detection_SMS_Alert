# Gas Leakage Detection System with SMS Alert

## Overview
This project is a gas leakage detection system using the **MQ-5 gas sensor** and an **Arduino-compatible board**. When a gas leak is detected, the system triggers an **alarm** and sends an **SMS alert** to predefined phone numbers using a **GSM module**.

## Features
- **Real-time gas monitoring** with the MQ-5 sensor
- **LCD Display** to show system status
- **Buzzer Alarm** for local alerts
- **SMS Notification** to emergency contacts
- **Automatic reset** after the gas leak is cleared

## Components Required
- Arduino Uno/Nano
- MQ-5 Gas Sensor
- GSM Module (SIM800L/SIM900A)
- LCD Display (16x2) with I2C
- Buzzer
- Connecting Wires

## Circuit Diagram
(You can add a circuit diagram image here)

## Installation & Setup
1. **Clone the Repository:**
   ```bash
   git clone https://github.com/SriKiran21/Gas_Leakage_Detection_SMS_Alert.git
   cd Gas_Leakage_Detection_SMS_Alert
   ```
2. **Upload the Code:**
   - Open `gas_leak_detection.ino` in **Arduino IDE**
   - Select the correct board and COM port
   - Click **Upload**
3. **Connect the Components:**
   - MQ-5 sensor to Arduino **(Pin 7 for digital output)**
   - GSM module to **SoftwareSerial (Pin 9, 10)**
   - LCD display to appropriate pins
   - Buzzer to **Pin 8**
4. **Power On the System**

## How It Works
1. The system continuously monitors the air for gas leaks.
2. When gas concentration exceeds a safe limit, the buzzer activates.
3. The system sends SMS alerts to predefined contacts.
4. The system resets automatically once gas levels return to normal.

## Modifications
- Change phone numbers in `SendTextMessage()` function before uploading.
- Adjust sensitivity by modifying the **threshold** in the code.
- Add **Wi-Fi or IoT** integration for cloud alerts.

## License
This project is open-source and licensed under the **MIT License**. Feel free to modify and use it for personal or educational purposes.

---

Let me know if you need additional details or modifications!


