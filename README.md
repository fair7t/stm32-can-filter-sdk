# STM32 CAN Filter SDK

Public SDK (headers, docs, examples) for a closed-source STM32 CAN filter.
Core logic remains private and ships as a prebuilt static library (`libcanfilter_core.a`).

## Contents
- `include/canfilter.h` — public API
- `examples/nucleo_f411re/` — CubeIDE-style example
- `docs/` — quick start & config format
- `lib/` — prebuilt library (added by CI from private repo)

## Basic usage
```c
cf_init(cfg, len);
if (cf_process(&in, &out, &dir)) { /* send out */ }

## ⚙️ Hardware setup (STM32F105 CAN Filter)

This project runs on the STM32F105 microcontroller and can be used
with most Chinese CAN-filter boards sold as "STM32 CAN Filter" or "CAN Gateway".

### 📡 Pinout and wiring

| STM32F105 Pin | Function | Connection | Description |
|----------------|-----------|-------------|--------------|
| PB8            | CAN1_RX  | TJA1050 RXD | CAN Bus 1 receive |
| PB9            | CAN1_TX  | TJA1050 TXD | CAN Bus 1 transmit |
| PB5            | CAN2_RX  | TJA1050 RXD | CAN Bus 2 receive |
| PB6            | CAN2_TX  | TJA1050 TXD | CAN Bus 2 transmit |
| GND            | Ground   | Common ground | Shared with CAN transceivers |
| 5V / 3.3V      | VCC      | Power input | Depends on board version |
| NRST           | Reset    | Button / programmer | Optional |
| BOOT0          | Boot     | Jumper to GND | Normal boot mode |

🟢 **TJA1050** or **SN65HVD230** transceivers are usually mounted directly on the board.  
Connect both CAN1 and CAN2 sides to your vehicle CAN lines via twisted pair cables (CAN_H / CAN_L).

> ⚠️ Always share ground between both CAN networks and the STM32 board.

---

### 🔌 Power and connection

- Power: 12V → DC-DC → 5V → AMS1117-3.3V (on-board regulator)
- Debug/program via **ST-LINK V2** or USB-TTL (PA9/PA10 USART1)
- CAN termination: add 120 Ω resistors if not present on the line

---

### 📷 Example connection diagram

![STM32F105 CAN Filter Wiring](https://github.com/user-attachments/assets/bf8325ea-4aa1-4bc7-ba7b-1fb3587cd790)






