# Microcontrollers

## Atmel

 - [AVR Libc](https://www.nongnu.org/avr-libc/)

## ESP8266

 - [Wikipedia page](https://en.wikipedia.org/wiki/ESP8266)
 - [Datasheet](https://web.archive.org/web/20171201031911/http://espressif.com/sites/default/files/documentation/esp-wroom-02d_esp-wroom-02u_datasheet_en.pdf)

| Specs | Description |
|-----|----|
| Processor | L106 32-bit RISC microprocessor core based on the Tensilica Xtensa Diamond Standard 106Micro running at 80 MHz |
| Memory | 32 KiB instruction RAM 32 KiB instruction cache RAM 80 KiB user-data RAM 16 KiB ETS system-data RAM
| External QSPI flash | up to 16 MiB is supported (512 KiB to 4 MiB typically included) |
| IEEE 802.11 b/g/n Wi-Fi
| Integrated TR switch, balun, LNA, power amplifier and matching network
| WEP or WPA/WPA2 authentication, or open networks
| GPIOs | 16 pins |
| SPI | |
| I²C | (software implementation) |
| I²S | interfaces with DMA (sharing pins with GPIO)
| UART | on dedicated pins, plus a transmit-only UART can be enabled on GPIO2
| 10-bit ADC | (successive approximation ADC) |

## ESP32

 - [Wikipedia page](https://en.wikipedia.org/wiki/ESP32)
 - [Datasheet](https://www.espressif.com/sites/default/files/documentation/esp32_datasheet_en.pdf)
 - [Video](https://www.youtube.com/watch?v=k_D_Qu0cgu8) ESP32 Dual Core on Arduino IDE including Data Passing and Task Synchronization

## RP2040

 - [datasheet](https://datasheets.raspberrypi.org/rp2040/rp2040_datasheet.pdf)
 - [A closer look at Raspberry Pi RP2040 Programmable IOs (PIO)](https://www.cnx-software.com/2021/01/27/a-closer-look-at-raspberry-pi-rp2040-programmable-ios-pio/)
 - [Video](https://www.youtube.com/watch?v=yYnQYF_Xa8g) In-depth: Raspberry Pi Pico's PIO - programmable I/O!

## STM32F103C8T6 (Blue pill)

 [Reference manual](https://www.st.com/content/ccc/resource/technical/document/reference_manual/59/b9/ba/7f/11/af/43/d5/CD00171190.pdf/files/CD00171190.pdf/jcr:content/translations/en.CD00171190.pdf) | [datasheet](https://www.st.com/resource/en/datasheet/stm32f103c8.pdf)

| Specs | Description |
|-------|-------------|
| CPU | Arm Cortex-M3 |
| #core | 1 |
| Architecture | 32bit |
| CPU frequency | 72Mhz |
| Voltage | 2v7 - 3v3 |
| Connectivity | No |
| RAM | 20KB |
| Flash | 64KB |
| GPIOs | 37 |
| SPI | 2 |
| I2C | 2 |
| I2S | 0 |
| UART | 3 |
| CAN  | 1 |
| ADC | 12bit, 10 channels |
| DAC | 0 |
| Timers | 3 16bit |
| PWM | 1 |

![](../images/STM32-pinout.png)
