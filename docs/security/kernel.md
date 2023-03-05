# Kernel exploiting

Exploitation in this environment is a little special because, first of all is the kernel,
so failure means all the system is fucked up, second you have all the particular
subsystems (think about memory allocation for example) and mitigations designed
specifically for it.


 - [Kernel stack overflows (basics)](https://blog.0x80.org/kernel-stack-overflows-basics/)
 - [Kernel exploitation for dummies](http://uaf.io/exploitation/misc/2016/09/10/Kernel-Exploitation-for-Dummies.html)
 - [Writing kernel exploits](https://tc.gtisc.gatech.edu/bss/2014/r/kernel-exploits.pdf)
 - [Linux Kernel Exploitation](http://repository.root-me.org/Exploitation%20-%20Syst%C3%A8me/Unix/EN%20-%20Linux%20Kernel%20Exploitation%20-%20Patrick%20Biernat.pdf) slides from Modern Binary Exploitation
 - [PAWNYABLE](https://pawnyable.cafe/linux-kernel/)
 - [repo](https://github.com/xairy/kernel-exploits) with a bunch of proof-of-concept exploits for the Linux kernel
 - [repo](https://github.com/xairy/linux-kernel-exploitation) with some writeup about kernel exploitation tecnique and exploit
 - [Presentation](https://jon.oberheide.org/files/summercon11-stackjacking.pdf) about **stackjacking** disclosure of
   kernel stack data (probably fixed by now)
 - [Practical SMEP/SMAP bypass techniques on Linux](https://www.syscan360.org/slides/2016_SG_Vitaly_Nikolenko_Practical_SMEP_Bypass_Techniques.pdf)
 - [SMEP: What is It, and How to Beat It on Linux](http://vulnfactory.org/blog/2011/06/05/smep-what-is-it-and-how-to-beat-it-on-linux/)
 - [Linux Kernel x86-64 bypass SMEP - KASLR - kptr_restric](http://blackbunny.io/linux-kernel-x86-64-bypass-smep-kaslr-kptr_restric/)
 - Linux Kernel ROP - Ropping your way to [part 1](https://www.trustwave.com/Resources/SpiderLabs-Blog/Linux-Kernel-ROP---Ropping-your-way-to---(Part-1)/) and [part 2](https://www.trustwave.com/Resources/SpiderLabs-Blog/Linux-Kernel-ROP---Ropping-your-way-to---(Part-2)/)
 - [Hacking the PS4, part 3](https://cturt.github.io/ps4-3.html) kernel exploitation
 - [Kernel-mode exploits primer](http://old.iseclab.org/projects/vifuzz/docs/exploit.pdf)
 - Smashing The Kernel Stack For Fun And Profit [Phrack 60::6](http://phrack.org/issues/60/6.html)
 - Attacking the Core: Kernel Exploitation Notes [Phrack 64::6](http://phrack.org/issues/64/6.html#article)
 - [Stairway to Successful Kernel Exploitation](http://booksite.elsevier.com/samplechapters/9781597494861/Chapter_3.pdf)
 - [Exploiting “BadIRET” vulnerability (CVE-2014-9322, Linux kernel privilege escalation)](https://blogs.bromium.com/exploiting-badiret-vulnerability-cve-2014-9322-linux-kernel-privilege-escalation/)
 - [Linux Kernel Vulnerability Can Lead to Privilege Escalation: Analyzing CVE-2017-1000112](https://securingtomorrow.mcafee.com/mcafee-labs/linux-kernel-vulnerability-can-lead-to-privilege-escalation-analyzing-cve-2017-1000112/)
 - [CVE-2016-0728](https://perception-point.io/2016/01/14/analysis-and-exploitation-of-a-linux-kernel-vulnerability-cve-2016-0728/)
 - [MMap Vulnerabilities](https://research.checkpoint.com/mmap-vulnerabilities-linux-kernel/) also [PDF](https://labs.mwrinfosecurity.com/assets/BlogFiles/mwri-mmap-exploitation-whitepaper-2017-09-18.pdf)
 - [out-of-tree](https://out-of-tree.io/) {module, exploit} development tool: is for automating some routine actions for creating development environments for debugging kernel modules and exploits, generating reliability statistics for exploits, and also provides the ability to easily integrate into CI (Continuous Integration).
 - [collection of verified Linux kernel exploits](https://github.com/jollheef/lpe)
 - [Tailoring CVE-2019-2215 to Achieve Root](https://hernan.de/blog/2019/10/15/tailoring-cve-2019-2215-to-achieve-root/)
 - CVE-2017-11176:  A step-by-step Linux Kernel exploitation
    - [part 1/4](https://blog.lexfo.fr/cve-2017-11176-linux-kernel-exploitation-part1.html)
    - [part 2/4](https://blog.lexfo.fr/cve-2017-11176-linux-kernel-exploitation-part2.html)
    - [part 3/4](https://blog.lexfo.fr/cve-2017-11176-linux-kernel-exploitation-part3.html)
    - [part 4/4](https://blog.lexfo.fr/cve-2017-11176-linux-kernel-exploitation-part4.html)
 - [pr0cf5/kernel-exploit-practice](https://github.com/pr0cf5/kernel-exploit-practice) repository for kernel exploit practice
 - [milabs/lkrg-bypass](https://github.com/milabs/lkrg-bypass) LKRG bypass methods
 - [a13xp0p0v/linux-kernel-defence-map](https://github.com/a13xp0p0v/linux-kernel-defence-map)
 - [Linux Kernel Teaching](https://linux-kernel-labs.github.io/refs/heads/master/index.html) This is a collection of lectures and labs Linux kernel topics. The lectures focus on theoretical and Linux kernel exploration.
 - [The Plight of TTY in the Linux Kernel](https://pr0cf5.github.io/ctf/2020/03/09/the-plight-of-tty-in-the-linux-kernel.html)
 - [Four Bytes of Power: exploiting CVE-2021-26708 in the Linux kernel](https://a13xp0p0v.github.io/2021/02/09/CVE-2021-26708.html)
 - Learning Linux Kernel Exploitation
    - [Part 1](https://lkmidas.github.io/posts/20210123-linux-kernel-pwn-part-1/)
    - [Part 2](https://lkmidas.github.io/posts/20210128-linux-kernel-pwn-part-2/)
    - [Part 3](https://lkmidas.github.io/posts/20210205-linux-kernel-pwn-part-3/)
 - [Writing a Linux Kernel Remote in 2022](https://blog.immunityinc.com/p/writing-a-linux-kernel-remote-in-2022/)
 - [Learning Linux kernel exploitation - Part 2](https://0x434b.dev/learning-linux-kernel-exploitation-part-2-cve-2022-0847/) Continuing to walk down Linux Kernel exploitation lane. This time around with an unanticipated topic: DirtyPipe as it actually nicely fits the series as an example.
 - [The Android kernel mitigations obstacle race](https://github.blog/2022-06-16-the-android-kernel-mitigations-obstacle-race/) CVE-2022-22057, a use-after-free in the Qualcomm gpu kernel driver
 - [DirtyCred](https://i.blackhat.com/USA-22/Thursday/US-22-Lin-Cautious-A-New-Exploitation-Method.pdf): A New Exploitation Method! No Pipe but as Nasty as Dirty Pipe
 - [Exploiting CVE-2022-42703 - Bringing back the stack attack](https://googleprojectzero.blogspot.com/2022/12/exploiting-CVE-2022-42703-bringing-back-the-stack-attack.html)

## Mitigations

 - Kernel stack cookies
 - Address space layout randomization (``KASLR``)
 - Supervisor mode access prevention (``SMAP``): all the userland pages in the
   page table are set not executable when the system is in kernel mode
 - Kernel page table isolation (``KPTI``): user-space and kernel-space table are
   completely separated when in user-mode

### Links

 - [The State of Kernel Self Protection](https://outflux.net/slides/2018/lca/kspp.pdf)
 - [Control Flow Integrity (CFI) in the Linux kernel](https://outflux.net/slides/2020/lca/cfi.pdf)
 - [Put an io_uring on it: Exploiting the Linux Kernel](https://www.graplsecurity.com/post/iou-ring-exploiting-the-linux-kernel)

### KASLR

 - [bcoles/kasld](https://github.com/bcoles/kasld) A collection of various techniques to bypass KASLR and retrieve the Linux kernel base virtual address on x86 / x86_64 architectures as an unprivileged user.


## Fuzzing

 - Fuzzing the Linux kernel (x86) entry code, [part 1](https://blogs.oracle.com/linux/fuzzing-the-linux-kernel-x86-entry-code%2c-part-1-of-3), [part 2](https://blogs.oracle.com/linux/fuzzing-the-linux-kernel-x86-entry-code%2c-part-2-of-3), [part 3](https://blogs.oracle.com/linux/fuzzing-the-linux-kernel-x86-entry-code%2c-part-3-of-3)
 - [Looking for Remote Code Execution bugs in the Linux kernel](https://xairy.io/articles/syzkaller-external-network) This article covers my experience with fuzzing the Linux kernel externally over the network. I’ll explain how I extended a kernel fuzzer called syzkaller for this purpose and show off the found bugs.

## Heap

 - [Linux Kernel universal heap spray](https://duasynt.com/blog/linux-kernel-heap-spray)
 - [An Analysis of Linux Kernel Heap Hardening](https://blog.infosectcbr.com.au/2020/04/an-analysis-of-linux-kernel-heap.html)
 - [SLAB quarantine](https://a13xp0p0v.github.io/2020/11/30/slab-quarantine.html)
 - [Exploiting Linux kernel heap off-by-one](https://duasynt.com/blog/cve-2016-6187-heap-off-by-one-exploit)
 - [Playing for K(H)eaps: Understanding and Improving Linux Kernel Exploit Reliability](https://www.usenix.org/system/files/sec22fall_zeng.pdf)
 - [Linux kernel heap feng shui in 2022](https://duasynt.com/blog/linux-kernel-heap-feng-shui-2022)
 - [CVE-2022-1786 | A Journey To The Dawn](https://blog.kylebot.net/2022/10/16/CVE-2022-1786/)

## iOS

 - [One Byte to rule them all](https://googleprojectzero.blogspot.com/2020/07/one-byte-to-rule-them-all.html)
 - [Writing an iOS Kernel Exploit from Scratch](https://secfault-security.com/blog/chain3.html)
 - [An iOS zero-click radio proximity exploit odyssey](https://googleprojectzero.blogspot.com/2020/12/an-ios-zero-click-radio-proximity.html)

## Papers

### KEPLER: Facilitating Control-flow Hijacking Primitive Evaluation for Linux Kernel Vulnerabilities

 - [presentation](https://www.usenix.org/conference/usenixsecurity19/presentation/wu-wei)

### ret2dir: Rethinking Kernel Isolation

 - [paper](https://www.usenix.org/system/files/conference/usenixsecurity14/sec14-paper-kemerlis.pdf)

### KOOBE: Towards Facilitating Exploit Generation of Kernel Out-Of-Bounds Write Vulnerabilities

 - [paper](https://www.usenix.org/system/files/sec20summer_chen-weiteng_prepub.pdf)

### A Systematic Study of Elastic Objects in Kernel Exploitation

 - [paper](https://dl.acm.org/doi/pdf/10.1145/3372297.3423353)

### Jump Over ASLR: Attacking Branch Predictors to Bypass ASLR

 - [paper](https://www.cs.ucr.edu/~nael/pubs/micro16.pdf)

### Dirty Cred

This exploitation method swaps unprivileged and privileged kernel credentials

 - [paper](https://zplin.me/papers/DirtyCred.pdf)
