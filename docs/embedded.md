# Microcontrollers&Embedded Systems

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

## Build Systems

 - [Build systems](http://elinux.org/Build_Systems)

### Yocto

 - [Yocto project](https://www.yoctoproject.org/)
 - [OpenEmbedded layers index](https://layers.openembedded.org/)
 - [Improving Your Embedded Linux Security Posture with Yocto](/documents/improving-embedded-linux-security-yocto.pdf)
 - [Building Raspberry Pi Systems with Yocto](http://www.jumpnowtek.com/rpi/Raspberry-Pi-Systems-with-Yocto.html)
 - [Creating Linux based Embedded System Images with Yocto](https://github.com/Nuand/bladeRF/wiki/Creating-Linux-based-Embedded-System-Images-with-Yocto)
 - [Integrating Yocto and OpenEmbedded](https://elinux.org/images/d/de/Elc2011_kooi.pdf)
 - [Yocto Project Quick Start](https://www.yoctoproject.org/docs/current/yocto-project-qs/yocto-project-qs.html)
 - [Building Our First Poky Image for the Raspberry Pi](https://hub.packtpub.com/building-our-first-poky-image-raspberry-pi/)

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

## Microcontrollers

### ESP8266

 - [Wikipedia page](https://en.wikipedia.org/wiki/ESP8266)

### ESP32

 - [Wikipedia page](https://en.wikipedia.org/wiki/ESP32)
 - [Video](https://www.youtube.com/watch?v=k_D_Qu0cgu8) ESP32 Dual Core on Arduino IDE including Data Passing and Task Synchronization


## Embedded systems

In order to generate a rootfs for testing on QEMU of architecture on your desktop you can use ``multistrap``

```
$ sudo multistrap -a mips -d /tmp/RFS -f mips-multistrap.conf
$ sudo mount -o bind /dev/ /tmp/RFS/dev/
$ sudo cp /usr/bin/qemu-mips-static /tmp/RFS/usr/bin/
$ sudo LC_ALL=C LANGUAGE=C LANG=C chroot /tmp/RFS/ dpkg --configure -a
```

After that mith ``binfmt-support`` is possible to use a chroot directly

```
$ uname -a
Linux 4.9.0-3-amd64 #1 SMP Debian 4.9.30-2 (2017-06-12) x86_64 GNU/Linux
$ sudo chroot /tmp/RFS/ /bin/bash
/# uname -a
Linux 4.9.0-3-amd64 #1 SMP Debian 4.9.30-2 (2017-06-12) mips GNU/Linux
```

## Mips in Debian

Some hints from this [answer](https://reverseengineering.stackexchange.com/questions/8829/cross-debugging-for-mips-elf-with-qemu-toolchain)

```
# apt-get install emdebian-archive-keyring
# tee /etc/apt/sources.list.d/emdebian.list << EOF
deb http://mirrors.mit.edu/debian squeeze main
deb http://www.emdebian.org/debian squeeze main
EOF
# apt-get update
# apt-get install libc6-mipsel-cross
# apt-get install gcc-mipsel-linux-gnu
```

## OpenWRT

[OpenWrt](https://openwrt.org/) is described as a Linux distribution for embedded devices.

```
$ git clone git://github.com/openwrt/openwrt.git && cd openwrt
$ make menuconfig
  [choose Target System (like Broadcom BCM63xx or Malta if you want Qemu) and then Target Profile (like Netgear DG834G v4)]
$ make -j 8
```

Some of the targets available are

 - ``clean``
 - ``dirclean``
 - ``distclean``
 - ``defconfig``
 - ``menuconfig``

If you want to test it into Qemu you can launch it with the following oneliner
(for more info look at the [wiki](https://wiki.openwrt.org/doc/howto/qemu))

```
$ qemu-system-mipsel -kernel bin/malta/openwrt-malta-le-vmlinux-initramfs.elf -nographic -m 256
[    0.000000] Linux version 3.18.45 (packz@durruti) (gcc version 4.8.3 (OpenWrt/Linaro GCC 4.8-2014.04 r49389) ) #2 SMP Sun May 14 20:02:35 CEST 2017
[    0.000000] Early serial console at I/O port 0x3f8 (options '38400n8')
[    0.000000] bootconsole [uart0] enabled
 ...
Press the [f] key and hit [enter] to enter failsafe mode
Press the [1], [2], [3] or [4] key and hit [enter] to select the debug level
[    5.000000] procd: - early -
[    6.110000] procd: - ubus -
[    7.160000] procd: - init -
Please press Enter to activate this console.


BusyBox v1.23.2 (2017-05-14 19:59:13 CEST) built-in shell (ash)

  _______                     ________        __
 |       |.-----.-----.-----.|  |  |  |.----.|  |_
 |   -   ||  _  |  -__|     ||  |  |  ||   _||   _|
 |_______||   __|_____|__|__||________||__|  |____|
          |__| W I R E L E S S   F R E E D O M
 -----------------------------------------------------
 CHAOS CALMER (Chaos Calmer, r49389)
 -----------------------------------------------------
  * 1 1/2 oz Gin            Shake with a glassful
  * 1/4 oz Triple Sec       of broken ice and pour
  * 3/4 oz Lime Juice       unstrained into a goblet.
  * 1 1/2 oz Orange Juice
  * 1 tsp. Grenadine Syrup
 -----------------------------------------------------
root@(none):/#
```

## Single board computers

### Omega2 plus

It's a MIPS architecture

 - [Wikipedia page](https://en.wikipedia.org/wiki/Omega2_(computer))

```
# ifconfig 
apcli0    Link encap:Ethernet  HWaddr 42:A3:6B:00:90:99  
          inet addr:192.168.1.8  Bcast:192.168.1.255  Mask:255.255.255.0
          inet6 addr: fe80::40a3:6bff:fe00:9099/64 Scope:Link
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:42690 errors:0 dropped:0 overruns:0 frame:0
          TX packets:30343 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000 
          RX bytes:41187093 (39.2 MiB)  TX bytes:3014790 (2.8 MiB)

br-wlan   Link encap:Ethernet  HWaddr 40:A3:6B:C0:90:9B  
          inet addr:192.168.3.1  Bcast:192.168.3.255  Mask:255.255.255.0
          inet6 addr: fd1d:48c4:7633::1/60 Scope:Global
          inet6 addr: fe80::42a3:6bff:fec0:909b/64 Scope:Link
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:42629 errors:0 dropped:0 overruns:0 frame:0
          TX packets:48871 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000 
          RX bytes:5128061 (4.8 MiB)  TX bytes:40127972 (38.2 MiB)

eth0      Link encap:Ethernet  HWaddr 40:A3:6B:C0:90:9B  
          inet6 addr: fe80::42a3:6bff:fec0:909b/64 Scope:Link
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:0 errors:0 dropped:0 overruns:0 frame:0
          TX packets:3316 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000 
          RX bytes:0 (0.0 B)  TX bytes:804360 (785.5 KiB)
          Interrupt:5 

eth0.1    Link encap:Ethernet  HWaddr 40:A3:6B:C0:90:9B  
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:0 errors:0 dropped:0 overruns:0 frame:0
          TX packets:1189 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000 
          RX bytes:0 (0.0 B)  TX bytes:70957 (69.2 KiB)

eth0.2    Link encap:Ethernet  HWaddr 40:A3:6B:C0:90:9B  
          inet6 addr: fe80::42a3:6bff:fec0:909b/64 Scope:Link
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:0 errors:0 dropped:0 overruns:0 frame:0
          TX packets:2098 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000 
          RX bytes:0 (0.0 B)  TX bytes:714525 (697.7 KiB)

lo        Link encap:Local Loopback  
          inet addr:127.0.0.1  Mask:255.0.0.0
          inet6 addr: ::1/128 Scope:Host
          UP LOOPBACK RUNNING  MTU:65536  Metric:1
          RX packets:4712 errors:0 dropped:0 overruns:0 frame:0
          TX packets:4712 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1 
          RX bytes:306439 (299.2 KiB)  TX bytes:306439 (299.2 KiB)

ra0       Link encap:Ethernet  HWaddr 40:A3:6B:C0:90:99  
          inet6 addr: fe80::42a3:6bff:fec0:9099/64 Scope:Link
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:50025 errors:82 dropped:1 overruns:0 frame:0
          TX packets:49525 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000 
          RX bytes:7421805 (7.0 MiB)  TX bytes:40031962 (38.1 MiB)
          Interrupt:6
```

```
# brctl show
bridge name	bridge id		STP enabled	interfaces
br-wlan		7fff.40a36bc0909b	no		eth0.1
							ra0
```
```
# iwconfig 
eth0.1    no wireless extensions.

lo        no wireless extensions.

ra0       RTWIFI SoftAP  ESSID:"Omega-XXXX"  
          Mode:Managed  Channel=1  Access Point: XX:XX:XX:XX:XX:XX   
          Bit Rate=72 Mb/s   
          
eth0      no wireless extensions.

br-wlan   no wireless extensions.

apcli0    RTWIFI SoftAP  ESSID:"YYYYYYYYYY"  
          Mode:Managed  Channel=1  Access Point: YY:YY:YY:YY:YY:YY   
          Bit Rate=72 Mb/s   
          
eth0.2    no wireless extensions.
```

### Rpi

 - [bootflow](https://www.raspberrypi.org/documentation/hardware/raspberrypi/bootmodes/bootflow.md)
 - [The comprehensive GPIO Pinout guide for the Raspberry Pi](https://pinout.xyz/)
 - [Raspberry Pi Zero 4 Port USB Hub](https://openhardwarecoza.wordpress.com/2015/12/07/raspberry-pi-zero-4-port-usb-hub-open-source-pcb-design/)
 - [raspberrypi/hats](https://github.com/raspberrypi/hats)
 - [RPi troubleshooting](https://elinux.org/R-Pi_Troubleshooting)
 - Raspberry Pi Zero Extreme Teardown [video](https://www.youtube.com/watch?v=HH5cFqc9OcM)

### Beagle Bone Black

A variant of the Beagle Bone, a board with the [TI Sitara AM335x](http://www.ti.com/am335x), an application processor SoC containing an ARM Cortex-A8 core.

 - [eLinux page](https://elinux.org/BeagleBone_Community)
 - [AM335x Technical Reference Manual](https://www.ti.com/lit/ug/spruh73p/spruh73p.pdf)
 - [Writing MLO](https://witekio.com/blog/writing-mlo-beagleboard-xm/)
 - [Building BeagleBone Systems with Yocto](https://jumpnowtek.com/beaglebone/BeagleBone-Systems-with-Yocto.html)
 - https://www.eewiki.net/display/linuxonarm/BeagleBone+Black
 - http://icculus.org/~hendersa/android/

You can build a complete system with this [instruction](http://www.crashcourse.ca/wiki/index.php/BBB_meta-bb)
or create an image using [this](https://github.com/RobertCNelson/omap-image-builder)

[Home page](http://beagleboard.org/black) | [Wiki](http://www.elinux.org/Beagleboard:BeagleBoneBlack) | [Android](http://beagleboard.org/project/rowboat/)

The ``uENV.txt`` file is in the FAT partition not in the ``/boot`` directory, the ``BOOT`` button
decides only if the system will use the file from the ``eMMC`` or from the SD ([source](https://groups.google.com/d/msg/beagleboard/_mOlo6T-70E/yZdHiD_ftbcJ)).

![Schema](http://elinux.org/images/2/2b/Features.jpg)

#### U-Boot


 - http://www.twam.info/hardware/beaglebone-black/u-boot-on-beaglebone-black

#### Android

It's possible to build Android using the following mannifest

    repo init -u git://gitorious.org/rowboat/manifest.git -m rowboat-jb-am335x.xml

and the command

    make TARGET_PRODUCT=beagleboneblack OMAPES=4.x droid -j8

source: https://eewiki.net/display/AOA/BeagleBone+Black

#### Kernel


    $ git clone https://github.com/RobertCNelson/bb-kernel.git && cd bb-kernel
    $ git checkout --track origin/am33x-v3.18
    $ ./build_kernel.sh

#### Serial pinout

From the original [wiki](http://elinux.org/Beagleboard:BeagleBone_Black_Serial)

    J1 GND
    J4 RX
    J5 TX

The connection is

 - Baud 115,200
 - Bits 8
 - Parity N
 - Stop Bits 1
 - Handshake None

With the Bus Pirate remember to set select *normal* as output type

```
(1)>
Select output type:
 1. Open drain (H=Hi-Z, L=GND)
 2. Normal (H=3.3V, L=GND)
```

http://codechief.wordpress.com/2013/11/11/beaglebone-black-serial-debug-connection/

#### HDMI issues

```
root@beaglebone:/sys/class/drm/card0/card0-HDMI-A-1# xrandr --verbose                                                                                                                        
Screen 0: minimum 320 x 200, current 1280 x 720, maximum 2048 x 2048                                                                                                                         
HDMI-0 connected 1280x720+0+0 (0x42) normal (normal left inverted right x axis y axis) 474mm x 296mm                                                                                         
       Identifier: 0x40                                                                                                                                                                      
       Timestamp:  1523547016
       Subpixel:   unknown
       Gamma:      1.0:1.0:1.0
       Brightness: 1.0
       Clones:
       CRTC:       0
       CRTCs:      0
       Transform:  1.000000 0.000000 0.000000
                   0.000000 1.000000 0.000000
                   0.000000 0.000000 1.000000
                  filter:
       EDID:
               00ffffffffffff000469f12201010101
               20130103802f1e782e78f5a655489b26
               125054bfef80b30081809500950f9040
               714f0101010121399030621a274068b0
               3600da281100001c000000ff0039384c
               4d56443030343433360a000000fd0038
               4b1f5111000a202020202020000000fc
               00415355532d4c5332323148ffff01ff
               02031e764b909f859484930312010716
               230907078301000065030c000000023a
               801871382d40582c9600da2811000018
               023a80d072382d40102c4580da281100
               001e011d8018711c1620582c2500da28
               1100009e011d80d0721c1620102c2580
               da281100009e011d00bc52d01e20b828
               5540da281100001e00000000000000dd
  1280x720 (0x41)   74.2MHz +HSync +VSync
        h: width  1280 start 1720 end 1760 total 1980 skew    0 clock   37.5KHz
        v: height  720 start  725 end  730 total  750           clock   50.0Hz
  1280x720 (0x42)   74.2MHz +HSync +VSync *current
        h: width  1280 start 1390 end 1430 total 1650 skew    0 clock   45.0KHz
        v: height  720 start  725 end  730 total  750           clock   60.0Hz
  720x576 (0x43)   27.0MHz -HSync -VSync
        h: width   720 start  732 end  796 total  864 skew    0 clock   31.2KHz
        v: height  576 start  581 end  586 total  625           clock   50.0Hz
  720x480 (0x44)   27.0MHz -HSync -VSync
        h: width   720 start  736 end  798 total  858 skew    0 clock   31.5KHz
        v: height  480 start  489 end  495 total  525           clock   59.9Hz
  640x480 (0x45)   25.2MHz -HSync -VSync
        h: width   640 start  656 end  752 total  800 skew    0 clock   31.5KHz
        v: height  480 start  490 end  492 total  525           clock   59.9Hz
```
