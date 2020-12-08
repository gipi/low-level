# Microcontrollers&Embedded Systems

 - [SO YOU WANT TO BUILD AN EMBEDDED LINUX SYSTEM?](https://jaycarlson.net/embedded-linux/) A primer on how embedded Linux systems are developed, plus an exploration of the hardware and software ecosystems of ten different commonly-available CPUs
 - [Anatomy of cross-compilation toolchains](https://elinux.org/images/1/15/Anatomy_of_Cross-Compilation_Toolchains.pdf)
 - [From zero to main(): Bare metal C](https://interrupt.memfault.com/blog/zero-to-main-1)
 - [Demystifying Firmware Linker Scripts](https://interrupt.memfault.com/blog/how-to-write-linker-scripts-for-firmware)
 - [Get the most out of the linker map file](https://interrupt.memfault.com/blog/get-the-most-out-of-the-linker-map-file)
 - [Cross debugging for ARM / MIPS ELF with QEMU/toolchain](https://reverseengineering.stackexchange.com/questions/8829/cross-debugging-for-arm-mips-elf-with-qemu-toolchain)
 - [Emulating Embedded Linux Devices with QEMU](https://www.novetta.com/2018/02/emulating-embedded-linux-devices-with-qemu/)
 - [Emulating Embedded Linux Systems with QEMU](https://www.novetta.com/2018/02/emulating-embedded-linux-systems-with-qemu/)
 - [GNU Build IDs for Firmware](https://interrupt.memfault.com/blog/gnu-build-id-for-firmware)
 - [ARM Cortex-M RTOS Context Switching](https://interrupt.memfault.com/blog/cortex-m-rtos-context-switching)
 - [ARM-X Firmware Emulation Framework](https://armx.exploitlab.net/)
 - [Awesome IOT](https://github.com/phodal/awesome-iot)
 - [Analyzing Malware for Embedded Devices: TheMoon Worm](https://w00tsec.blogspot.it/2014/02/analyzing-malware-for-embedded-devices.html)
 - [Build a Debian Jessie root filesystem](http://www.acmesystems.it/debian_jessie)
 - [Device Tree for dummies](http://free-electrons.com/pub/conferences/2013/elce/petazzoni-device-tree-dummies/petazzoni-device-tree-dummies.pdf)
 - [Device Tree Usage](https://elinux.org/Device_Tree_Usage)
 - Series about hardware analysis and firmware reversing
     - [Part 1](http://jcjc-dev.com/2016/04/08/reversing-huawei-router-1-find-uart/) Hunting for Debug Ports
     - [Part 2](http://jcjc-dev.com/2016/04/29/reversing-huawei-router-2-scouting-firmware/) Scouting the Firmware
     - [Part 3](http://jcjc-dev.com/2016/05/23/reversing-huawei-3-sniffing/) Following the Data
     - [Part 4](http://jcjc-dev.com/2016/06/08/reversing-huawei-4-dumping-flash/) Dumping the Flash
     - [Part 5](http://jcjc-dev.com/2016/12/14/reversing-huawei-5-reversing-firmware/) Digging Through the Firmware

 - [nvram-faker](https://github.com/zcutlip/nvram-faker) A simple library to intercept calls to libnvram when running embedded linux applications in emulated environments.

## Power management

 - [Racing to Sleep](https://www.embeddedrelated.com/showarticle/1316.php)

## Bootloader

 - [A tour of bootloading](http://www.bxsays.com/blog/2015/09/03/a-toure-of-bootloading.html)

## GPIO

Usually an embedded system has a certain numbers of devices interconnected via different signals. To configure
these interconnections in some cases **gpio** are used.

```
>>> gpio2num = lambda a,b:(a -1)*32 + b
>>> print gpio2num(7,16)
208
>>> print gpio2num(7,9)
201
num2gpio = lambda x: (x /32 + 1, x%32)
>>> num2gpio(98)
(4, 2)
```

 - [Definitive GPIO guide](https://www.kosagi.com/w/index.php?title=Definitive_GPIO_guide)


## Update mechanisms

 - [Mender](https://mender.io/) Mender is a secure and robust software update
   system designed to handle large number of devices. Mender is designed
   according to a simple client/server architecture, allowing central management
   of deployments to all devices.
 - [RAUC](https://rauc.readthedocs.io/) is a lightweight update client that runs
   on your embedded device and reliably controls the procedure of updating your
   device with a new firmware revision
