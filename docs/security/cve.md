# CVE

## Links

 - [Submit a CVE Request](https://cveform.mitre.org/)
 - [awesome cve poc](https://github.com/qazbnm456/awesome-cve-poc)
 - [The Reports of CVE's Death Have Been Greatly Exaggerated](https://grsecurity.net/reports_of_cves_death_greatly_exaggerated)

## List

 - [CVE-2021-33909](https://www.qualys.com/2021/07/20/cve-2021-33909/sequoia-local-privilege-escalation-linux.txt) Sequoia: A deep root in Linux's filesystem layer
 - [CVE-2021-31440](https://www.zerodayinitiative.com/blog/2021/5/26/cve-2021-31440-an-incorrect-bounds-calculation-in-the-linux-kernel-ebpf-verifier): AN INCORRECT BOUNDS CALCULATION IN THE LINUX KERNEL EBPF VERIFIER
 - [CVE-2021-30465](http://blog.champtar.fr/runc-symlink-CVE-2021-30465/): runc mount destinations can be swapped via symlink-exchange to cause mounts outside the rootfs
 - [CVE-2021-26708](https://a13xp0p0v.github.io/2021/02/09/CVE-2021-26708.html) Four Bytes of Power: exploiting CVE-2021-26708 in the Linux kernel
 - [CVE-2021-23017](https://x41-dsec.de/lab/advisories/x41-2021-002-nginx-resolver-copy/): ``nginx`` DNS Resolver Off-by-One Heap Write Vulnerability
 - [CVE-2021-21017](https://blog.exodusintel.com/2021/06/28/analysis-of-a-heap-buffer-overflow-vulnerability-in-adobe-acrobat-reader-dc/) Analysis of a Heap Buffer-Overflow Vulnerability in Adobe Acrobat Reader DC
 - [CVE-2021-3156](https://www.qualys.com/2021/01/26/cve-2021-3156/baron-samedit-heap-based-overflow-sudo.txt) ``sudo`` heap based overflow
 - [Exim's Multiple vulnerabilities](https://www.qualys.com/2021/05/04/21nails/21nails.txt):
    - CVE-2020-28007: Link attack in Exim's log directory
    - CVE-2020-28008: Assorted attacks in Exim's spool directory
    - CVE-2020-28014: Arbitrary file creation and clobbering
    - CVE-2021-27216: Arbitrary file deletion
    - CVE-2020-28011: Heap buffer overflow in queue_run()
    - CVE-2020-28010: Heap out-of-bounds write in main()
    - CVE-2020-28013: Heap buffer overflow in parse_fix_phrase()
    - CVE-2020-28016: Heap out-of-bounds write in parse_fix_phrase()
    - CVE-2020-28015: New-line injection into spool header file (local)
    - CVE-2020-28012: Missing close-on-exec flag for privileged pipe
    - CVE-2020-28009: Integer overflow in get_stdinput()
    - CVE-2020-28017: Integer overflow in receive_add_recipient()
    - CVE-2020-28020: Integer overflow in receive_msg()
    - CVE-2020-28023: Out-of-bounds read in smtp_setup_msg()
    - CVE-2020-28021: New-line injection into spool header file (remote)
    - CVE-2020-28022: Heap out-of-bounds read and write in extract_option()
    - CVE-2020-28026: Line truncation and injection in spool_read_header()
    - CVE-2020-28019: Failure to reset function pointer after BDAT error
    - CVE-2020-28024: Heap buffer underflow in smtp_ungetc()
    - CVE-2020-28018: Use-after-free in tls-openssl.c
    - CVE-2020-28025: Heap out-of-bounds read in pdkim_finish_bodyhash()
 - [CVE-2020-11060](https://offsec.almond.consulting/playing-with-gzip-rce-in-glpi.html) An arbitrary path and a hashed path disclosure can be abused to execute code on a GLPI host, by creating a PHP/GZIP polyglot file.
 - [CVE-2020-10713](https://capsule8.com/blog/grubbing-secure-boot-the-wrong-way-cve-2020-10713/) Grubbing Secure Boot the Wrong Way: OOB in the GRUB parser
 - [CVE-2020-8835](https://www.thezdi.com/blog/2020/4/8/cve-2020-8835-linux-kernel-privilege-escalation-via-improper-ebpf-program-verification)
 - [CVE-2020-0423](https://www.longterm.io/cve-2020-0423.html): Exploiting a Single Instruction Race Condition in Binder
 - [CVE-2019-18683](https://a13xp0p0v.github.io/2020/02/15/CVE-2019-18683.html): Linux kernel UAF caused by a race condition in the V4L subsystem.
 - CVE-2019-18634: [first writeup](https://www.sudo.ws/alerts/pwfeedback.html), [second writeup](https://iamalsaher.tech/posts/2020-02-08-cve-2019-18634/) In Sudo before 1.8.26, if pwfeedback is enabled in /etc/sudoers, users can trigger a stack-based buffer overflow in the privileged sudo process.
 - [CVE-2019-11484](https://securitylab.github.com/research/ubuntu-whoopsie-CVE-2019-11484)
 - [CVE-2019-11707](https://blog.bi0s.in/2019/08/18/Pwn/Browser-Exploitation/cve-2019-11707-writeup/) Exploit code for a vulnerability in Firefox, found by saelo and coinbase security
 - [CVE-2019-11932](https://awakened1712.github.io/hacking/hacking-whatsapp-gif-rce/) How a double-free bug in WhatsApp turns to RCE
 - [CVE-2019-14378](https://blog.bi0s.in/2019/08/24/Pwn/VM-Escape/2019-07-29-qemu-vm-escape-cve-2019-14378/) Qemu escape
 - [CVE-2019-13272](https://bugs.chromium.org/p/project-zero/issues/detail?id=1903) Linux 4.10 < 5.1.17 PTRACE_TRACEME local root [PoC](https://github.com/bcoles/kernel-exploits/blob/master/CVE-2019-13272/poc.c)
 - CVE-2019-2215
    - [Android's ``/dev/binder`` UAF](https://dayzerosec.com/posts/analyzing-androids-cve-2019-2215-dev-binder-uaf/)
    - [Bad Binder: Android In-The-Wild Exploit](https://googleprojectzero.blogspot.com/2019/11/bad-binder-android-in-wild-exploit.html)
 - [CVE-2019-2107](https://github.com/marcinguy/CVE-2019-2107) Android stagefright-like HW vulnerability
 - [CVE-2019–0708](https://medium.com/@straightblast426/a-debugging-primer-with-cve-2019-0708-ccfa266682f6) A Debugging Primer with CVE-2019–0708
 - [CVE-2019–0708](https://www.malwaretech.com/2019/09/bluekeep-a-journey-from-dos-to-rce-cve-2019-0708.html) BlueKeep: A Journey from DoS to RCE (CVE-2019-0708)
 - [CVE-2019-0752](https://www.zerodayinitiative.com/blog/2019/5/21/rce-without-native-code-exploitation-of-a-write-what-where-in-internet-explorer) RCE WITHOUT NATIVE CODE: EXPLOITATION OF A WRITE-WHAT-WHERE IN INTERNET EXPLORER
 - [CVE-2019-0211](https://cfreal.github.io/carpe-diem-cve-2019-0211-apache-local-root.html) Apache Root Privilege Escalation
 - [CVE-2018-13784: PrestaShop 1.6.x Privilege Escalation](https://www.ambionics.io/blog/prestashop-privilege-escalation)
 - [CVE-2018-8120](https://www.welivesecurity.com/2018/05/15/tale-two-zero-days/) RCE in Acrobat reader
 - [CVE-1028-7445](https://medium.com/@maxi./finding-and-exploiting-cve-2018-7445-f3103f163cc1) Finding and exploiting CVE-2018–7445 (unauthenticated RCE in MikroTik’s RouterOS SMB)
 - CVE-2017-11176:  A step-by-step Linux Kernel exploitation
    - [part 1/4](https://blog.lexfo.fr/cve-2017-11176-linux-kernel-exploitation-part1.html)
    - [part 2/4](https://blog.lexfo.fr/cve-2017-11176-linux-kernel-exploitation-part2.html)
    - [part 3/4](https://blog.lexfo.fr/cve-2017-11176-linux-kernel-exploitation-part3.html)
    - [part 4/4](https://blog.lexfo.fr/cve-2017-11176-linux-kernel-exploitation-part4.html)
 - [CVE-2017-0781](https://jesux.es/exploiting/blueborne-android-6.0.1-english/) BlueBorne RCE on Android 6.0.1
 - [CVE-2016-6187](https://duasynt.com/blog/cve-2016-6187-heap-off-by-one-exploit) Exploiting Linux kernel heap off-by-one
 - [CVE-2016-5195](https://dirtycow.ninja/) also known as **Dirty Cow**, another [writeup](https://chao-tic.github.io/blog/2017/05/24/dirty-cow)
 - [CVE-2016-3714](https://imagetragick.com) ImageMagick RCE
 - [CVE-2016-3132](http://www.libnex.org/blog/doublefreeinstandardphplibrarydoublelinklist) Double Free in Standard PHP Library Double Link List
 - [CVE-2016-2384](https://xairy.github.io/blog/2016/cve-2016-2384) Exploiting a double-free in the USB-MIDI Linux kernel driver
 - [CVE-2016-0728](http://perception-point.io/2016/01/14/analysis-and-exploitation-of-a-linux-kernel-vulnerability-cve-2016-0728/)
 - [CVE-2015-3864](https://www.usenix.org/sites/default/files/conference/protected-files/woot16_slides_drake.pdf) stagefright
 - [Analysis of PHP's CVE-2016-6289 and CVE-2016-6297](https://blog.fortinet.com/2016/08/10/analysis-of-php-s-cve-2016-6289-and-cve-2016-6297)
 - [CVE-2016-5696](http://www.cs.ucr.edu/~zhiyunq/pub/sec16_TCP_pure_offpath.pdf) Off-Path TCP Exploits
 - [Slides](http://gsec.hitb.org/materials/sg2016/D1%20-%20Adam%20Donenfeld%20and%20Yaniv%20Mordekhay%20-%20Stumping%20The%20Mobile%20Chipset.pdf) for CVE-2016-5340, CVE-2016-2504, CVE-2016-2503 and CVE-2016-2059
 - [CVE-2016-8655](http://seclists.org/oss-sec/2016/q4/607) Linux ``af_packet.c`` race condition
 - [vmnc decoder](https://scarybeastsecurity.blogspot.it/2016/12/1day-poc-with-rip-deterministic-linux.html)
 - [CVE-2015-6565](http://www.openwall.com/lists/oss-security/2017/01/26/2)
 - [Android kernel CVE POCs](https://github.com/ScottyBauer/Android_Kernel_CVE_POCs)
 - [CVE-2017-6074](http://seclists.org/oss-sec/2017/q1/471)
 - [repo with POC](https://github.com/xairy/kernel-exploits)
 - [Unix privilege escalation exploits pack](https://github.com/LukaSikic/Unix-Privilege-Escalation-Exploits-Pack)
 - [CVE-2016-7201](https://www.endgame.com/blog/chakra-exploit-and-limitations-modern-mitigation-techniques) IE Edge
 - [CVE-2017-1000366](https://www.qualys.com/research/security-advisories/) Stack clash
 - [Solving a post exploitation issue with CVE-2017-7308](https://www.coresecurity.com/blog/solving-post-exploitation-issue-cve-2017-7308)
 - [CVE-2017-2636](https://a13xp0p0v.github.io/2017/03/24/CVE-2017-2636.html) race condition in the n_hdlc Linux kernel driver bypassing SMEP
 - CVE-2018-6789: Exim Off-by-one RCE
    - [writeup](https://devco.re/blog/2018/03/06/exim-off-by-one-RCE-exploiting-CVE-2018-6789-en/)
    - [writeup](https://medium.com/@straightblast426/my-poc-walk-through-for-cve-2018-6789-2e402e4ff588)

# Writeup

 - [How we broke PHP, hacked Pornhub and earned 20.000$](https://www.evonide.com/how-we-broke-php-hacked-pornhub-and-earned-20000-dollar/)
 - Explaining Dirty COW local root exploit - CVE-2016-5195 [Video](https://www.youtube.com/watch?v=kEsshExn7aE)
 - [PS4 kernel exploit write-up for 4.05](https://github.com/Cryptogenic/Exploit-Writeups/blob/master/PS4/%22NamedObj%22%204.05%20Kernel%20Exploit%20Writeup.md#stage-3---heap-sprayobject-fake)
