# IOT-Based Flame and Gas Safety Device with Smart Emergency Response

This project focuses on designing and developing an **IoT-based flame and gas detection system** using an **Arduino UNO** microcontroller to provide early warnings and improve safety in residential, industrial, and commercial environments. The system is a low-cost, simple-to-implement solution designed to automatically respond to fire and gas hazards.

## 🚀 Features
- **Dual-Sensor Monitoring:** Integrated flame and MQ-series gas sensors for continuous environmental scanning.
- **Smart Response System:** 
  - **Visual:** LCD displays real-time status and specific warning messages.
  - **Audio:** A buzzer produces unique sound patterns based on the type of hazard detected.
  - **Mechanical:** An automatic water pump activates via a relay to suppress fire immediately upon flame detection.
- **Real-time Logic:** Capable of handling simultaneous "Critical" conditions where both fire and gas are detected.

## 🛠 Hardware Components
The system is built using the following core components [0.1.4, 0.1.15-0.1.19]:
*   **Arduino UNO:** The central processing unit.
*   **Flame Sensor:** Detects IR radiation from fire.
*   **MQ Gas Sensor:** Detects combustible gases like LPG and methane.
*   **Relay Module:** Interfaces the low-power Arduino with the high-power water pump.
*   **Water Pump:** For immediate fire mitigation.
*   **Buzzer:** For audible alerts.
*   **16x2 LCD (I2C):** For visual status updates.
*   **Breadboard & Jumper Wires:** For circuit prototyping.

## 📋 How It Works
The system operates on a threshold-based logic programmed via the Arduino IDE:
1. **Safe Mode:** LCD displays `SAFE` and sensor values; all outputs remain off.
2. **Flame Detected:** LCD shows `FIRE`, the buzzer pulses, and the water pump turns **ON**.
3. **Gas Detected:** LCD shows `GAS` and the buzzer produces a distinct alert pattern.
4. **Critical Mode:** If both are detected, LCD shows `FIRE & GAS`, the buzzer sounds continuously, and the pump turns **ON**.

## 🔮 Future Enhancements
- **Remote Alerts:** Integrating Wi-Fi (ESP8266) or GSM modules for mobile notifications.
- **Cloud Integration:** Real-time data monitoring via IoT dashboards.
- **Advanced Control:** Automatic gas valve shut-off mechanisms.

## 👥 Contributors (Group Members)
- Pankaj Rai
- Palden Lama
- Eijkeyal Pakhrin
- Suhana Shrestha
- Priyanka Kumari Shah
- Lucky Lawaju

---
*Developed as part of the CS5053NI – Cloud Computing & IoT module, 2024 Spring.*
