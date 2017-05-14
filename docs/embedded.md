# Embedded Systems

 - [Analyzing Malware for Embedded Devices: TheMoon Worm](https://w00tsec.blogspot.it/2014/02/analyzing-malware-for-embedded-devices.html)
 - [Build a Debian Jessie root filesystem](http://www.acmesystems.it/debian_jessie)
 - [Device Tree for dummies](http://free-electrons.com/pub/conferences/2013/elce/petazzoni-device-tree-dummies/petazzoni-device-tree-dummies.pdf)
 - Series about hardware analysis and firmware reversing
     - [Part 1](http://jcjc-dev.com/2016/04/08/reversing-huawei-router-1-find-uart/) Hunting for Debug Ports
     - [Part 2](http://jcjc-dev.com/2016/04/29/reversing-huawei-router-2-scouting-firmware/) Scouting the Firmware
     - [Part 3](http://jcjc-dev.com/2016/05/23/reversing-huawei-3-sniffing/) Following the Data
     - [Part 4](http://jcjc-dev.com/2016/06/08/reversing-huawei-4-dumping-flash/) Dumping the Flash
     - [Part 5](http://jcjc-dev.com/2016/12/14/reversing-huawei-5-reversing-firmware/) Digging Through the Firmware

 - [Build systems](http://elinux.org/Build_Systems)
 - [nvram-faker](https://github.com/zcutlip/nvram-faker) A simple library to intercept calls to libnvram when running embedded linux applications in emulated environments.

In order to generate a rootfs for testing on QEMU of architecture on your desktop you can use ``multistrap``

```
$ sudo multistrap -a mips -d /tmp/RFS -f mips-multistrap.conf
$ sudo mount -o bind /dev/ /tmp/RFS/dev/
$ sudo cp /usr/bin/qemu-mips-static /tmp/RFS/usr/bin/
$ sudo LC_ALL=C LANGUAGE=C LANG=C chroot /tmp/RFS/ dpkg --configure -a
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

 - [The comprehensive GPIO Pinout guide for the Raspberry Pi](https://pinout.xyz/)
 - [Raspberry Pi Zero 4 Port USB Hub](https://openhardwarecoza.wordpress.com/2015/12/07/raspberry-pi-zero-4-port-usb-hub-open-source-pcb-design/)
 - [raspberrypi/hats](https://github.com/raspberrypi/hats)

### Beagle Bone Black
