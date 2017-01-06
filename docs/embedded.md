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
