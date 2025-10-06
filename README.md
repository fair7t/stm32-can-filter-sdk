## ⚙️ Hardware Pinout — STM32F105 CAN Filter Board

This CAN-Filter board is based on **STM32F105RBT6** and uses two **TJA1024 / TJA1050** transceivers.  
Below is the annotated pinout of the commonly used Chinese dual-CAN filter board.

### 📷 Board pinout

![STM32F105 CAN Filter Wiring](https://github.com/user-attachments/assets/b6faee2b-14d8-4aa8-9805-4c579bddd6f9)

---

### 🔌 Power and programming

| Pin | Voltage | Description |
|-----|----------|-------------|
| **12V** | Input | Main power input (goes to AMS1117 regulators) |
| **5V**  | Output | 5 V rail after AMS1117-5.0 |
| **3.3V** | Output | MCU power rail |
| **GND** | Ground | Common ground |
| **BOOT0** | Boot mode | Keep low for normal operation |
| **SWDIO (PA13)** | Debug | Connect to ST-LINK V2 |
| **SWCLK (PA14)** | Debug | Connect to ST-LINK V2 |

---

### 🧩 CAN Interfaces

| Channel | STM32 Pins | Transceiver | Description |
|----------|-------------|-------------|--------------|
| **CAN1** | PB8 (RX), PB9 (TX) | TJA1042 | Connects to vehicle CAN 1 |
| **CAN2** | PB5 (RX), PB6 (TX) | TJA1042 | Connects to vehicle CAN 2 |

> 💡 *Each CAN transceiver should have a 120 Ω termination resistor if not already present.*

---

### 🧠 MCU Details

- MCU: **STM32F105RBT6 (Cortex-M3, Dual CAN, 64 KB RAM, 128 KB Flash)**  
- Crystal: **25 MHz**
- Voltage regulators: **AMS1117-5.0** → **AMS1117-3.3**
- Compatible programmers: **ST-LINK V2** or **USB-TTL (PA9 / PA10 USART1)**

---

### 🔧 Recommended wiring

- Power: 12 V input to VIN → on-board regulators provide 5 V and 3.3 V  
- Ground must be shared between both CAN buses  
- CAN lines: twisted-pair wires for CANH/CANL on both channels  

---

📘 *This photo and table are provided for educational use to document real-world STM32 hardware integration.*







