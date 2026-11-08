# ESP32-C3 Lora Puck Device
https://github.com/antelliJ/LoRaPuck

A LoRa project built using an esp32-c3 supermini and an SX1262 for LoRa communication
<img width="477" height="378" alt="Screenshot 2026-11-08 184657" src="https://github.com/user-attachments/assets/a8284359-269b-4401-9a9a-7cc2ffa513d8" />

## Features
- LoRa
    - Transmits +22 Dbm
    - 150-960 MHz
    - IPEX SMD connector
- Bluetooth Low Energy (BLE)
- WiFi (not implemented)
- 0.96" OLED display (optional)
    - I2C SSD1306

## Usage and info
there isn't a battery configuration setup, so everything is powered by wire. Check out the installation instructions below on further details on flashing builds.

### Purpose
LoRa and MeshCore are cool projects that use radio in an interesting way, and have a decently low barrier to entry with all the tools available. This project is the product of that.

## Hardware
- esp32-c3 supermini
- SX1262
- Generic SSD1306 0.96" OLED display modules with 2.54mm pin headers

## Firmware
### Schematic
<img width="3508" height="2480" alt="schematic - nov 8" src="https://github.com/user-attachments/assets/fac6aa4d-63c3-4479-9893-f552273012ae" />

### GPIO Assignment

| Signal   |   | ESP32-C3 GPIO |
|----------|---|---------------|
| SX NRST  |   | GPIO 5        |
| SX MISO  |   | GPIO 6        |
| SX MOSI  |   | GPIO 7        |
| SX NSS   |   | GPIO 10       |
| SX SCLK  |   | GPIO 1        |
| SX DIO1  |   | GPIO 0        |
| SX BUSY  |   | GPIO 4        |
|          |   |               |
| OLED SCL |   | GPIO 8        |
| OLED SDA |   | GPIO 3        |



### Installation Instructions

### For most people (recommended)
Get the latest stable firmware from the [Releases Page](https://github.com/antelliJ/LoRaPuck/releases)

The [Mescore flasher](https://meshcore.io/flasher) also has the ability to flash custom `.bin` files, so you can flash the bin files to your device there

This is paired with a MeshCore Client, for instance through the web, the mobile app, or for PC

Using the companion BLE build, you can flash firmware that you can connect to with your phone.
From here it should be able to be the same as any other campanion MeshCore device.

### For Devs
- Install [PlatformIO](https://docs.platformio.org/) in VS Code
- Clone the repository, and build and run one of the configurations through PlatformIO

- or to build a merged bin, run: (replace `AntelliPuck_companion_radio_ble` with the environment you want to build)
`pio pkg exec -p tool-esptoolpy -- esptool.py --chip esp32 merge_bin -o merged.bin --flash_mode dio --flash_size 4MB 0x0 .pio/build/AntelliPuck_companion_radio_ble/bootloader.bin 0x8000 .pio/build/AntelliPuck_companion_radio_ble/partitions.bin 0x10000 .pio/build/AntelliPuck_companion_radio_ble/firmware.bin`

### MeshCore Compatability
Theoretically it should work like any other MeshCore project, I'd personally go with the companion app for ease of communication.

## PCB
`\PCB\` includes files relevant for the schematic, PCB design, and manufacturing. 
`\PCB\production\` are the files used for PCB manufacturing

### PCB Renders
<img width="477" height="378" alt="Screenshot 2026-11-08 184657" src="https://github.com/user-attachments/assets/a8284359-269b-4401-9a9a-7cc2ffa513d8" />
<img width="475" height="321" alt="Screenshot 2026-11-08 184707" src="https://github.com/user-attachments/assets/23d595b0-9dd4-4519-8aaa-3788680b50a8" />


## CAD Model
<img width="277" height="230" alt="Screenshot 2026-11-08 184621" src="https://github.com/user-attachments/assets/c97eb4f1-d8bf-4dd9-9813-c920f1bb24b2" />

Files for a model for the enclosure for this project can be found in `\3dModel\`.
`\3dModel\` is intended for all 3d printed related files.
`\3dModel\editable\` contains the editable files made in freecad for the enclosure
`\3dModel\printable\` contains the print ready files as a `.3mf` file

## Bill of Materials
A nicely formatted excel sheet is provided at `\PCB\production\ereader-bom.xlsx` with a few more comments. 
The below is just a static version of that...

| Designator  | Footprint                           | Quantity | Value             | LCSC Part # | Other Notes                                                                                                    |
|-------------|-------------------------------------|----------|-------------------|-------------|----------------------------------------------------------------------------------------------------------------|
| AE1         | U.FL_Hirose_U.FL-R-SMT-1_Vertical   | 1        | Antenna           | C88374      | Regular UFL / IPEX connector                                                                                   |
| C1, C2      | 402                                 | 2        | 100nF             |             |                                                                                                                |
| C10, C11    | 402                                 | 2        | 4.7pF             |             |                                                                                                                |
| C12, C13    | 402                                 | 2        | 1.5pF             |             |                                                                                                                |
| C14         | 402                                 | 1        | 2.7pF             |             |                                                                                                                |
| C15         | 402                                 | 1        | 100pF             |             |                                                                                                                |
| C16, C8, C9 | 402                                 | 3        | 3.3pF             |             |                                                                                                                |
| C3          | 603                                 | 1        | 470nF             |             |                                                                                                                |
| C4          | 603                                 | 1        | 47nF              |             |                                                                                                                |
| C5          | 402                                 | 1        | 47pF              |             |                                                                                                                |
| C6          | 402                                 | 1        | 1nF               |             |                                                                                                                |
| C7          | 402                                 | 1        | 33pF              |             |                                                                                                                |
| L1, L2      | 402                                 | 2        | 47nH              |             |                                                                                                                |
| L3          | 402                                 | 1        | 15nH              |             |                                                                                                                |
| L4          | 402                                 | 1        | 7.5nH             |             |                                                                                                                |
| L5          | 402                                 | 1        | 12nH              |             |                                                                                                                |
| R1          | 603                                 | 1        | 100               |             |                                                                                                                |
| U1          | QFN-24-1EP_4x4mm_P0.5mm_EP2.6x2.6mm | 1        | SX1262IMLTRT      |             |                                                                                                                |
| U2          | COMM-SMD_16P-L22.5-W18.0-P2.54-TL   | 1        | ESP32C3-SUPERMINI |             | [https://www.aliexpress.com/item/1005005757810089.html](https://www.aliexpress.com/item/1005005757810089.html) |
| U5          | PinHeader_1x04_P2.54mm_Vertical     | 1        | OLED_0.96_128x64  |             | [https://www.aliexpress.com/item/1005006141235306.html](https://www.aliexpress.com/item/1005006141235306.html) |
| U6          | SOT-363_SC-70-6                     | 1        | PE4259            |             |                                                                                                                |
| Y1          | Crystal_SMD_3225-4Pin_3.2x2.5mm     | 1        | 32 MHz            |             |                                                                                                                |


## References

Built using [this guide](https://blueprint.hackclub.com/starter-projects/lora)
While looking at supported MeshCore firmware I found [this one](https://github.com/ndoo/ikoka-stick-meshtastic-device) that looks really similar to what I wanted to achieve for this project, and I got a lot of inspiration for this readme from that project!
[This youtube video](https://www.youtube.com/watch?v=TnRn3Kn_aXg) for learning about RF PCB design

Firmware a copy from [MeshCore's repository](https://github.com/meshcore-dev/meshcore)

used [Table to Markdown](https://tabletomarkdown.com/convert-spreadsheet-to-markdown/) to make the above BOM in the readme

alongside [Markdown Table Formatter](http://markdowntable.com/) to make the markdown look better while editing source

### AI usage:
- Drafting PlatformIO commands for building a merged file