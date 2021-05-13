# Security

User input **must** be sanitized!

## Weird machines

 - [LANGSEC](http://langsec.org/) Language-theoretic Security
 - [Page](http://www.cs.dartmouth.edu/~sergey/wm/) about weird machines by halvar flake
 - [Weird machines, exploitability, and provable
unexploitability](http://ieeexplore.ieee.org/stamp/stamp.jsp?reload=true&tp=&arnumber=8226852) also [slide](https://docs.google.com/presentation/d/1lfQGEX2aGEA1H7flsXw4V30ZkbnrfikYk9IrctuwZO8/edit)
 - [Limiting weird machines](https://docs.google.com/presentation/d/1-7XQWUHpGTrFls8M5OysefpF_HZ2YYCYW3huLPo6ArM/edit#slide=id.p) Putting boundaries around emergent insecurity
 - [Exploitation and state machines](http://archives.scovetta.com/pub/conferences/infiltrate_2011/Fundamentals_of_exploitation_revisited.pdf) Programming the “weird machine”, revisited)
 - [Hacking & Computer Science](https://events.ccc.de/congress/2010/Fahrplan/attachments/1807_ccc-hacker-research.pdf)
 - [The science of insecurity](http://langsec.org/insecurity-theory-28c3.pdf)
 - [Accidentally Turing-Complete](http://beza1e1.tuxen.de/articles/accidentally_turing_complete.html)
 - [Video](https://archive.org/details/2010-07-28LenSassaman-ExploitingTheForestWithTrees) 2010-07-28 Meredith L. Patterson and Len Sassaman - Black Hat USA 2010 - Exploiting the Forest with Trees
 - [From Buffer Overflows to “Weird Machines” and Theory of Computation](http://langsec.org/papers/Bratus.pdf)
 - [On Validating Inputs](https://noncombatant.org/2018/01/15/on-validating-inputs/)
 - [Security, Moore’s law, and the anomaly of cheap complexity](https://docs.google.com/presentation/d/17bKudNDduvN-7hWv7S84MiHUj2AnOPNbwjTM8euDC8w/edit)
 - [Proving un-exploitability of parsers](https://docs.google.com/presentation/d/1ODczTJnajepL-TCeN-9Ob_AIxxIzY4vXQvN5fL543Ac/edit)
 - [Maths for Hackers - The Hacker Theorem](https://unprovable.github.io/jekyll/update/2016/11/13/Maths-For-Hackers-The-Hacker-Theorem.html)
 - [The Good, the Bad, and the Weird](https://blog.trailofbits.com/2018/10/26/the-good-the-bad-and-the-weird/)
 - [Data oriented programming](https://huhong-nus.github.io/advanced-DOP/papers/dop.pdf)
 - [Secure Code Partitioning With ELF binaries, aka. SCOP](http://bitlackeys.org/papers/secure_code_partitioning_2018.txt)
 - [A Guide to Undefined Behavior in C and C++, Part 1](https://blog.regehr.org/archives/213)
 - Now you C me
   - [part 1](https://securitylab.github.com/research/now-you-c-me)
   - [part 2](https://securitylab.github.com/research/now-you-c-me-part-two)

Unrelated for now but there is an Android's vulnerabilities [CVE-2017-13156](https://www.guardsquare.com/en/blog/new-android-vulnerability-allows-attackers-modify-apps-without-affecting-their-signatures) where the system parses an ``APK`` or a ``DEX`` allowing to bypass signature.

## Pentesting

There are several phases

 1. **recon**
 2. **scan**
 3. **gain access**
 4. **maintain access**
 5. **cover tracks**

 - https://github.com/coreb1t/awesome-pentest-cheat-sheets
 - https://github.com/nixawk/pentest-wiki
 - Kali Linux Revelead [PDF](https://kali.training/downloads/Kali-Linux-Revealed-1st-edition.pdf)
 - [OWASP-Testing-Checklist](https://github.com/tanprathan/OWASP-Testing-Checklist)

## Bruteforce

In some cases it's important to make the space containing certain variables
big enough to not be guessed in human time.

The most used tool is [john the ripper](http://www.openwall.com/john/): on a Linux
system is possible to edit the ``src/Makefile`` and compile it with

    $ make -C src  -f Makefile linux-x86-64-native

One usage is toto generate a mangled list of word starting from a pristine one with the following command:

    $ ./run/john --wordlist=wordlist.txt --stdout --rules > expanded-word-list.txt

With no options, john will start in "single" mode first, then move on to "wordlist" mode, and finally to "incremental" mode.

```
$ john --incremental=Digits --stdout
1952
12345
123456
0065663
```

 - http://www.lanmaster53.com/2011/02/creating-complex-password-lists-with-john-the-ripper/
 - http://backreference.org/2009/10/26/password-recovery-with-john-the-ripper/

Obviously you need a good wordlist!

 - [Munging password](https://th3s3cr3tag3nt.blogspot.it/2017/03/munging-passwords.html)
 - [wordsmith](https://github.com/skahwah/wordsmith)

## Privilege escalation

 - [Privilege Escalation Cheatsheet](https://www.hackingarticles.in/privilege-escalation-cheatsheet-vulnhub/)
 - [WINDOWS PRIVILEGE ESCALATION – AN APPROACH FOR PENETRATION TESTERS](https://sec-consult.com/en/blog/2019/04/windows-privilege-escalation-an-approach-for-penetration-testers/)

## Custom code execution

See also [shellcode](/shellcode/).

 - Understanding the fundamentals of attacks What is happening when someone writes an exploit? awesome [slides](/what_happens_exploit.pdf) by Halvar Flake & Thomas Dullien trying
   to formalize exploits
 - https://gbmaster.wordpress.com/2015/06/28/x86-exploitation-101-house-of-force-jedi-overflow/
 - http://0x90909090.blogspot.it/2015/07/no-one-expect-command-execution.html
 - GHOST vulnerability [report](http://www.openwall.com/lists/oss-security/2015/01/27/9)
 - [commix](https://github.com/stasinopoulos/commix): Automated All-in-One OS Command Injection and Exploitation Tool
 - [How To Heap](https://github.com/shellphish/how2heap): A repository for learning various heap exploitation techniques.
 - [Pure In-Memory (Shell)Code Injection In Linux Userland](https://blog.sektor7.net/#!res/2018/pure-in-memory-linux.md)
 - [How I Hacked Google App Engine: Anatomy of a Java Bytecode Exploit](https://blog.polybdenum.com/2021/05/05/how-i-hacked-google-app-engine-anatomy-of-a-java-bytecode-exploit.html)

## Format String

Remember that using a too big string to exploit this vulnerability can overwrite sensible stuff, **use
a string as little as possible**.

 - [Exploiting Format String Vulnerabilities](http://repository.root-me.org/Exploitation%20-%20Syst%C3%A8me/Unix/EN%20-%20Exploiting%20Format%20String%20vulnerabilities.pdf)
 - [Advances in format string exploitation](http://phrack.org/issues/59/7.html) 0x0b, Issue 0x3b, Phile #0x07 of 0x12
 - [Howto remotely and automatically exploit a format bug](http://julianor.tripod.com/bc/remotefs.txt)
 - [libformatstr](https://github.com/hellman/libformatstr) Simplify format string exploitation.
 - [0CTF 2017 Quals: EasiestPrintf](https://poning.me/2017/03/23/EasiestPrintf/) exploiting ``__free_hook`` using ``printf``


## XPath injection

 - [Slides](http://repository.root-me.org/Exploitation%20-%20Web/EN%20-%20Blind%20Xpath%20injection.pdf)
 - [Slides](https://github.com/feakk/xxxpwn/raw/master/HAAS_Kiwicon7-Automating%20Advanced%20XPath%20Injection%20Attacks.pdf)

## Serialization

 - [DISGUISE PHAR PACKAGES AS IMAGES](https://www.nc-lp.com/blog/disguise-phar-packages-as-images) also [slide](https://github.com/s-n-t/presentations/blob/master/us-18-Thomas-It's-A-PHP-Unserialization-Vulnerability-Jim-But-Not-As-We-Know-It.pdf) from US BlackHat 2018

## Side channel

 - http://johoe.mooo.com/trezor-power-analysis/
 - [Side-channel attacks on high-security electronic safe locks](https://media.defcon.org/DEF%20CON%2024/DEF%20CON%2024%20presentations/DEFCON-24-Plore-Side-Channel-Attacks-On-High-Security-Electronic-Safe-Locks.pdf)
 - [Exploiting Timed Based RCE](https://securitycafe.ro/2017/02/28/time-based-data-exfiltration/)
 - [commix](https://github.com/commixproject/commix) Automated All-in-One OS command injection and exploitation tool.
 - [BranchScope: A New Side-Channel Attack on Directional Branch Predictor](http://www.cs.ucr.edu/~nael/pubs/asplos18.pdf)

## Type juggling

This is possible in language that casts automatically different types when operators are used,
particularly when are present more than one equal operator (``==`` and ``===``).

In ``PHP`` this is more dangerous when a conversion from ``JSON`` is done.

 - [Php type juggling slides](http://repository.root-me.org/Exploitation%20-%20Web/EN%20-%20PHP%20loose%20comparison%20-%20Type%20Juggling%20-%20OWASP.pdf)

## Advanced protection mechanism bypass

 - [ASLR Smack & Laugh Reference](http://www.icir.org/matthias/cs161-sp13/aslr-bypass.pdf)
 - [Bypassing non-executable-stack during exploitation using return-to-libc](http://www.infosecwriters.com/text_resources/pdf/return-to-libc.pdf)
 - [The advanced return-into-lib(c) exploits: PaX case study](http://phrack.org/issues/58/4.html)
 - [PAYLOAD ALREADY INSIDE: DATA REUSE FOR ROP EXPLOITS](https://media.blackhat.com/bh-us-10/whitepapers/Le/BlackHat-USA-2010-Le-Paper-Payload-already-inside-data-reuse-for-ROP-exploits-wp.pdf)
 - [Linux ASLR and GNU Libc: Address space layout computing and defence, and “stack canary” protection bypass](/documents/offensivecon-talk.pdf)
 - [New bypass and protection techniques for ASLR on Linux](http://blog.ptsecurity.com/2018/02/new-bypass-and-protection-techniques.html)

## Cloud

 - https://nvisium.com/documents/aws.pdf
 - [Hardening AWS Environments and Automating Incident Response](http://threatresponse.cloud/derbycon)

## Hardware

 - [Secure Systems and Pwning Popular Platforms](http://security.cs.rpi.edu/courses/binexp-spring2015/lectures/13/08_lecture.pdf)

## Tools

 - https://code.google.com/p/skipfish/
 - Damn Vulnerable Web App [site](http://www.dvwa.co.uk/)
 - [security headers](https://securityheaders.io/): check headers of your site
 - [DNSteal](https://github.com/m57/dnsteal): stealthily extract files from a victim machine through DNS requests
 - [pwntools](https://pwntools.readthedocs.org) CTF framework and exploit development library

### Fuzzing

 - [Hunting For Bugs With AFL 101 - A PRIMER](http://research.aurainfosec.io/hunting-for-bugs-101/)

## Phishing

  - [Spam and phishing in 2016](https://securelist.com/analysis/kaspersky-security-bulletin/77483/kaspersky-security-bulletin-spam-and-phishing-in-2016/)

## DNS Rebinding

 - https://lock.cmpxchg8b.com/rebinder.html
 - https://bugs.chromium.org/p/project-zero/issues/detail?id=1471&desc=2

## Links

 - [online courses](https://github.com/prakhar1989/awesome-courses#security)
 - [Exploit Development](https://rmusser.net/docs/Exploit%20Development.html)
 - [ssh security](https://stribika.github.io/2015/01/04/secure-secure-shell.html)
 - [preg_replace()](https://bitquark.co.uk/blog/2013/07/23/the_unexpected_dangers_of_preg_replace)
 - [Modern Binary Exploitation](http://security.cs.rpi.edu/courses/binexp-spring2015/)
 - [CSAW Quals 2016 Pwn 500 - Mom's Spaghetti](http://ctfhacker.com/pwn/2016/09/19/csaw-moms-spaghetti.html)
 - [CFT Time](https://ctftime.org)
 - Rise of the machine [PDF](/documents/ICIT-Brief-Rise-of-the-Machines.pdf)
 - [Readers of popular websites targeted by stealthy Stegano exploit kit hiding in pixels of malicious ads](http://www.welivesecurity.com/2016/12/06/readers-popular-websites-targeted-stealthy-stegano-exploit-kit-hiding-pixels-malicious-ads/)
 - [Don't use VPN services](https://gist.github.com/joepie91/5a9909939e6ce7d09e29)
 - [Facebook’s ImageTragick story](http://4lemon.ru/2017-01-17_facebook_imagetragick_remote_code_execution.html)
 - [Escaping a Python sandbox with a memory corruption bug](https://medium.com/@gabecpike/python-sandbox-escape-via-a-memory-corruption-bug-19dde4d5fea5)
 - [Jinja2 template injection filter bypasses](https://0day.work/jinja2-template-injection-filter-bypasses/)
 - [Spring Boot RCE](http://deadpool.sh/2017/RCE-Springs/) via a template code injection
 - [CVE-2018-13784: PrestaShop 1.6.x Privilege Escalation](https://www.ambionics.io/blog/prestashop-privilege-escalation)
 - [HTTP Desync Attacks: Request Smuggling Reborn](https://portswigger.net/research/http-desync-attacks-request-smuggling-reborn)
 - [JWT (JSON Web Token) (in)security](https://research.securitum.com/jwt-json-web-token-security/)
 - [Unlocking Heaven's Gate on Linux](https://redcanary.com/blog/heavens-gate-technique-on-linux/)
 - [Linux Hardening Guide](https://madaidans-insecurities.github.io/guides/linux-hardening.html)
 - [Dependency Confusion: How I Hacked Into Apple, Microsoft and Dozens of Other Companies](https://medium.com/@alex.birsan/dependency-confusion-4a5d60fec610)
