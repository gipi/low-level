# Single board computers

## Omega2 plus

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

## Rpi

 - [bootflow](https://www.raspberrypi.org/documentation/hardware/raspberrypi/bootmodes/bootflow.md)
 - [The comprehensive GPIO Pinout guide for the Raspberry Pi](https://pinout.xyz/)
 - [Raspberry Pi Zero 4 Port USB Hub](https://openhardwarecoza.wordpress.com/2015/12/07/raspberry-pi-zero-4-port-usb-hub-open-source-pcb-design/)
 - [raspberrypi/hats](https://github.com/raspberrypi/hats)
 - [RPi troubleshooting](https://elinux.org/R-Pi_Troubleshooting)
 - Raspberry Pi Zero Extreme Teardown [video](https://www.youtube.com/watch?v=HH5cFqc9OcM)

## Beagle Bone Black

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

### U-Boot


 - http://www.twam.info/hardware/beaglebone-black/u-boot-on-beaglebone-black

### Android

It's possible to build Android using the following mannifest

    repo init -u git://gitorious.org/rowboat/manifest.git -m rowboat-jb-am335x.xml

and the command

    make TARGET_PRODUCT=beagleboneblack OMAPES=4.x droid -j8

source: https://eewiki.net/display/AOA/BeagleBone+Black

### Kernel


    $ git clone https://github.com/RobertCNelson/bb-kernel.git && cd bb-kernel
    $ git checkout --track origin/am33x-v3.18
    $ ./build_kernel.sh

### Serial pinout

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

### HDMI issues

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

