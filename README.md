# ESP32-C3 Lora Puck Device

A LoRa project built using an esp32-c3 supermini and an SX1262 for LoRa communication

## Features
- LoRa
    - Transmits +22 Dbm
    - 150-960 MHz
- Bluetooth Low Energy (BLE)
- WiFi (not implemented)
- 0.96" OLED display (optional)
    - I2C SSD1306

## Hardware
- esp32-c3 supermini
- SX1262
- Generic SSD1306 0.96" OLED display modules with 2.54mm pin headers

## Firmware
### GPIO Assignment
(put nice table here)

### Installation Instructions
(put instructions for precompiled binaries linked to releases and dev instructions)
The [Mescore flasher](https://meshcore.io/flasher) also has the ability to flash custom .bin files, so can do there
This is paired with a MeshCore Client, for instance through the web, the mobile app, or for PC

### MeshCore Compatability
idk

## PCB Renders

## References

Built using [this guide](https://blueprint.hackclub.com/starter-projects/lora)
While looking at supported MeshCore firmware I found [this one](https://github.com/ndoo/ikoka-stick-meshtastic-device) that looks really similar, and I got a lot of inspiration for this readme from that project!
[This youtube video](https://www.youtube.com/watch?v=TnRn3Kn_aXg) for learning about RF PCB design