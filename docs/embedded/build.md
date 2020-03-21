# Build&Integration systems

 - [Build systems](http://elinux.org/Build_Systems)

## Yocto

 - [Yocto project](https://www.yoctoproject.org/)
 - [OpenEmbedded layers index](https://layers.openembedded.org/)
 - [Improving Your Embedded Linux Security Posture with Yocto](/documents/improving-embedded-linux-security-yocto.pdf)
 - [Building Raspberry Pi Systems with Yocto](http://www.jumpnowtek.com/rpi/Raspberry-Pi-Systems-with-Yocto.html)
 - [Creating Linux based Embedded System Images with Yocto](https://github.com/Nuand/bladeRF/wiki/Creating-Linux-based-Embedded-System-Images-with-Yocto)
 - [Integrating Yocto and OpenEmbedded](https://elinux.org/images/d/de/Elc2011_kooi.pdf)
 - [Yocto Project Quick Start](https://www.yoctoproject.org/docs/current/yocto-project-qs/yocto-project-qs.html)
 - [Building Our First Poky Image for the Raspberry Pi](https://hub.packtpub.com/building-our-first-poky-image-raspberry-pi/)

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

## Multistrap

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

