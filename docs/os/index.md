# Operating Systems

 - [Introduction to Paging](https://os.phil-opp.com/paging-introduction/)
 - [Raspberry pi os](https://github.com/s-matyukevich/raspberry-pi-os) This repository contains a step-by-step guide that teaches how to create a simple operating system (OS) kernel from scratch
 - [Sushi Roll](https://gamozolabs.github.io/metrology/2019/08/19/sushi_roll.html): A CPU research kernel with minimal noise for cycle-by-cycle micro-architectural introspection

Related to that there are **Hypervisor**s

 - [Hypervisor From Scratch – Part 1: Basic Concepts & Configure Testing Environment](https://rayanfam.com/topics/hypervisor-from-scratch-part-1/)
 - [Learning KVM - implement your own Linux kernel ](https://david942j.blogspot.com/2018/10/note-learning-kvm-implement-your-own.html)

## Unix quirkness

There are some aspects of ``UNIX`` that are broken

 - [Epoll is broken](https://idea.popcount.org/2017-03-20-epoll-is-fundamentally-broken-22/)
 - [POSIX close(2) is broken](https://www.daemonology.net/blog/2011-12-17-POSIX-close-is-broken.html)
 - [Eleven syscalls that suck](https://www.cloudatomiclab.com/antisyscall/)
 - [Use mmap With Care](https://www.sublimetext.com/blog/articles/use-mmap-with-care)
 - [signalfd is useless](https://ldpreload.com/blog/signalfd-is-useless)


## Linux

 - [The definitive guide to linux system calls](http://blog.packagecloud.io/eng/2016/04/05/the-definitive-guide-to-linux-system-calls/)
 - [Syscalls table 32](https://filippo.io/linux-syscall-table/)
 - [Syscalls table 64](https://syscalls.kernelgrok.com/)
 - Hello from a libc-free world!
    * [part1](https://blogs.oracle.com/ksplice/entry/hello_from_a_libc_free)
    * [part2](https://blogs.oracle.com/ksplice/entry/hello_from_a_libc_free1)
 - [Ftrace](https://jvns.ca/blog/2017/03/19/getting-started-with-ftrace/)
 - [The Design and Implementation of Userland Exec](https://grugq.github.io/docs/ul_exec.txt)
 - [How main() is executed on Linux](http://www.tldp.org/LDP/LG/issue84/hawk.html)
 - [__libc_start_main() specification](https://refspecs.linuxbase.org/LSB_3.0.0/LSB-PDA/LSB-PDA/baselib---libc-start-main-.html)
 - [What happens when you start a process on Linux?](http://jvns.ca/blog/2016/10/04/exec-will-eat-your-brain/)
 - [getauxval() and the auxiliary vector](https://lwn.net/Articles/519085/)
 - [OOPS debugging with GDB](http://mokosays.com/work/?p=22)
 - [slide](http://haifux.org/lectures/258/gpio_spi_i2c_userspace.pdf) on using ``SPI`` and ``I2C`` in user space.
 - [slide](http://www.cs.fsu.edu/~cop4610t/lectures/project2/kthreads/kthreads.pdf) about kthreads
 - [Evolution of the x86 context switch in Linux](http://www.maizure.org/projects/evolution_x86_context_switch_linux/)
 - [Linux Capabilities In Practice](https://blog.container-solutions.com/linux-capabilities-in-practice)
 - [Debugging network stalls on Kubernetes](https://github.blog/2019-11-21-debugging-network-stalls-on-kubernetes/)
 - [Eleven syscalls that rock the world](https://www.cloudatomiclab.com/prosyscall/)
 - [An introduction to Linux kernel initcalls](https://www.collabora.com/news-and-blog/blog/2020/07/14/introduction-to-linux-kernel-initcalls/)
 - [Static calls in Linux 5.10](https://blog.yossarian.net/2020/12/16/Static-calls-in-Linux-5-10): changes on linux 5.10 to improve performances but avoid Spectre-like attacks
 - [From HDL to Linux Userland](https://embed-me.com/from-hdl-to-linux-userland/)
 - [understanding thread stack sizes and how alpine is different](https://ariadne.space/2021/06/25/understanding-thread-stack-sizes-and-how-alpine-is-different/)
 - [How fast are Linux pipes anyway?](https://mazzo.li/posts/fast-pipes.html)
 - [random.c Inside the Linux kernel RNG](https://www.zx2c4.com/projects/linux-rng-5.17-5.18/inside-linux-kernel-rng-presentation-sept-13-2022.pdf)

### Networking

 - [Monitoring and Tuning the Linux Networking Stack: Sending Data](https://blog.packagecloud.io/monitoring-tuning-linux-networking-stack-sending-data/)
 - [Monitoring and Tuning the Linux Networking Stack: Receiving Data](https://blog.packagecloud.io/monitoring-tuning-linux-networking-stack-receiving-data/)

### Device tree


 - Post about Linux implementation and history of the [Device tree](http://junyelee.blogspot.com/2014/04/linux-device-tree.html)
 - [A TUTORIAL ON THE DEVICE TREE](http://junyelee.blogspot.com/2015/07/a-tutorial-on-device-tree.html)

### Containers

 - [What even is a container: namespaces and cgroups](https://jvns.ca/blog/2016/10/10/what-even-is-a-container/)
 - [p8952/bocker](https://github.com/p8952/bocker) Docker implemented in around 100 lines of bash
 - [Demystifying Containers - Part I: Kernel Space](https://medium.com/@saschagrunert/demystifying-containers-part-i-kernel-space-2c53d6979504)
 - [Demystifying Containers - Part II: Container Runtimes](https://medium.com/@saschagrunert/demystifying-containers-part-ii-container-runtimes-e363aa378f25)
 - [containers/skopeo](https://github.com/containers/skopeo) Work with remote images registries - retrieving information, images, signing content
 - [rootlesscontaine.rs/](https://rootlesscontaine.rs/) Rootless containers refers to the ability for an unprivileged user to create, run and otherwise manage containers
 - [Lesser known Docker tips for advanced users](https://offby2.com/posts/001-docker-lesser-known-tips/)
 - [Understanding how uid and gid work in Docker containers](https://medium.com/@mccode/understanding-how-uid-and-gid-work-in-docker-containers-c37a01d01cf)
 - [Connection refused?](https://pythonspeed.com/articles/docker-connection-refused/) Docker networking and how it impacts your image
 - [A deep dive into Linux namespaces](http://ifeanyi.co/posts/linux-namespaces-part-1/)
 - [How to run Docker containers using common Linux tools (without Docker)](https://ilearnedhowto.wordpress.com/tag/unshare/)
 - [Docker without Docker](https://fly.io/blog/docker-without-docker/)

### Memory

 - [Why mmap is faster than system calls](https://sasha-f.medium.com/why-mmap-is-faster-than-system-calls-24718e75ab37)
 - [How The Kernel Manages Your Memory](https://manybutfinite.com/post/how-the-kernel-manages-your-memory/)
 - [ARM32 Page Tables](https://people.kernel.org/linusw/arm32-page-tables)
 - [Kernel dynamic memory analysis](https://elinux.org/Kernel_dynamic_memory_analysis)
 - [SLUB](https://www.programmersought.com/article/34735202546/)
 - [SLUB debug](https://www.programmersought.com/article/34053451287/)

### Gate

 - [A little tour of linux-gate.so](https://www.technovelty.org/linux/a-little-tour-of-linux-gateso.html)
 - [Creating a vDSO: the Colonel's Other Chicken](https://www.linuxjournal.com/content/creating-vdso-colonels-other-chicken)

### Clock

 - [Clock Framework User Guide](http://processors.wiki.ti.com/index.php/Clock_Framework_User_Guide)
 - Common clock framework: how to use it [slide](https://elinux.org/images/b/b8/Elc2013_Clement.pdf)

### Modules/drivers

 - [How does the Linux kernel determine the order of __init calls?](https://stackoverflow.com/questions/10540008/how-does-the-linux-kernel-determine-the-order-of-init-calls/)
 - [Platform Device Driver - a practical approach](http://linuxseekernel.blogspot.com/2014/05/platform-device-driver-practical.html)
 - [Linux Kernel architecture for device drivers](http://2010.rmll.info/IMG/pdf/kernel-device-drivers-rmll2010.pdf)
 - https://elinux.org/Device_drivers
 - [An Introduction to the Video4Linux Framework](https://events.static.linuxfound.org/sites/events/files/slides/v4l2-testing.pdf)
 - [Linux media subsystem docs](https://linuxtv.org/downloads/v4l-dvb-apis/index.html)
 - [Linux kernel module cheat](https://github.com/cirosantilli/linux-kernel-module-cheat) The perfect emulation setup to study and modify the Linux kernel, kernel modules, QEMU and gem5
 - [Writing USB Device Drivers](https://www.kernel.org/doc/html/v4.15/driver-api/usb/writing_usb_driver.html)

### Tracing and debugging

 - [Linux kernel tracing](https://www.slideshare.net/vh21/linux-kernel-tracing) from COSCUP 2016
 - [goldshtn/linux-tracing-workshop](https://github.com/goldshtn/linux-tracing-workshop) Examples and hands-on labs for Linux tracing tools workshops
 - [Debugging disk IO](https://github.com/alexeldeib/bpf-demo/blob/master/docs/disk_io.md)
 - [Linux debugging, profiling and tracing training](https://bootlin.com/doc/training/debugging/debugging-slides.pdf)

### eBPF

 - [eBPF homepage](https://ebpf.io)
 - [Hardening Hostile Code in eBPF](https://samsung.github.io/kspp-study/bpf.html)
 - [Use our suite of eBPF libraries](https://blog.trailofbits.com/2023/08/09/use-our-suite-of-ebpf-libraries/) by trailofbits
 - [trailofbits/ebpfault](https://github.com/trailofbits/ebpfault) A BPF-based syscall fault injector
 - [All your tracing are belong to BPF](https://blog.trailofbits.com/2021/11/09/all-your-tracing-are-belong-to-bpf/)

## Zephyr

 - [Project page](https://www.zephyrproject.org/)
 - [Documentation](https://docs.zephyrproject.org/)

## Fuchsia

 - [Playing Around With The Fuchsia Operating System](https://blog.quarkslab.com/playing-around-with-the-fuchsia-operating-system.html)
