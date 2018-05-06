# Security

User input **must** be sanitized!

## Weird machines

 - [LANGSEC](http://langsec.org/) Language-theoretic Security
 - [Page](http://www.cs.dartmouth.edu/~sergey/wm/) about weird machines by halvar flake
 - [Weird machines, exploitability, and provable
unexploitability](http://ieeexplore.ieee.org/stamp/stamp.jsp?reload=true&tp=&arnumber=8226852) also [slide](https://docs.google.com/presentation/d/1lfQGEX2aGEA1H7flsXw4V30ZkbnrfikYk9IrctuwZO8/edit)
 - [Exploitation and state machines](http://archives.scovetta.com/pub/conferences/infiltrate_2011/Fundamentals_of_exploitation_revisited.pdf) Programming the “weird machine”, revisited)
 - [Hacking & Computer Science](https://events.ccc.de/congress/2010/Fahrplan/attachments/1807_ccc-hacker-research.pdf)
 - [The science of insecurity](http://langsec.org/insecurity-theory-28c3.pdf)
 - [Accidentally Turing-Complete](http://beza1e1.tuxen.de/articles/accidentally_turing_complete.html)
 - [Video](https://archive.org/details/2010-07-28LenSassaman-ExploitingTheForestWithTrees) 2010-07-28 Meredith L. Patterson and Len Sassaman - Black Hat USA 2010 - Exploiting the Forest with Trees
 - [From Buffer Overflows to “Weird Machines” and Theory of Computation](http://langsec.org/papers/Bratus.pdf)
 - [On Validating Inputs](https://noncombatant.org/2018/01/15/on-validating-inputs/)

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

## Custom code execution

See also [shellcode](/shellcode/).

 - Understanding the fundamentals of attacks What is happening when someone writes an exploit? awesome [slides](what_happens_exploit.pdf) by Halvar Flake & Thomas Dullien trying
   to formalize exploits
 - https://gbmaster.wordpress.com/2015/06/28/x86-exploitation-101-house-of-force-jedi-overflow/
 - http://0x90909090.blogspot.it/2015/07/no-one-expect-command-execution.html
 - GHOST vulnerability [report](http://www.openwall.com/lists/oss-security/2015/01/27/9)
 - [commix](https://github.com/stasinopoulos/commix): Automated All-in-One OS Command Injection and Exploitation Tool
 - [How To Heap](https://github.com/shellphish/how2heap): A repository for learning various heap exploitation techniques.

## Format String

Remember that using a too big string to exploit this vulnerability can overwrite sensible stuff, **use
a string as little as possible**.

 - [Exploiting Format String Vulnerabilities](http://repository.root-me.org/Exploitation%20-%20Syst%C3%A8me/Unix/EN%20-%20Exploiting%20Format%20String%20vulnerabilities.pdf)
 - [Advances in format string exploitation](http://phrack.org/issues/59/7.html) 0x0b, Issue 0x3b, Phile #0x07 of 0x12
 - [Howto remotely and automatically exploit a format bug](http://julianor.tripod.com/bc/remotefs.txt)
 - [libformatstr](https://github.com/hellman/libformatstr) Simplify format string exploitation.
 - [0CTF 2017 Quals: EasiestPrintf](https://poning.me/2017/03/23/EasiestPrintf/) exploiting ``__free_hook`` using ``printf``

## LFI/RFI

 - https://www.idontplaydarts.com/2011/02/using-php-filter-for-local-file-inclusion/
 - https://www.idontplaydarts.com/2011/03/php-remote-file-inclusion-command-shell-using-data-stream/
 - [Liffy](https://github.com/rotlogix/liffy): Local File Inclusion Exploitation Tool
 - [Upgrade from LFI to RCE via PHP Sessions](https://www.rcesecurity.com/2017/08/from-lfi-to-rce-via-php-sessions/)
 - [Exploiting PHP File Inclusion – Overview](https://websec.wordpress.com/2010/02/22/exploiting-php-file-inclusion-overview/)

## HTTP parameters pollution

HPP attacks can be defined as the feasibilty to override or add ``HTTP`` ``GET``/``POST`` parameters
by injecting query string delimiters. ``HtmlEntities`` are out of context here.


 - OWASP [slide](http://www.slideshare.net/Wisec/http-parameter-pollution-a-new-category-of-web-attacks)
 - Black Hat [slide](http://www.iseclab.org/people/embyte/slides/BHEU2011/hpp-bhEU2011.pdf)

## Session Fixation

 - http://shiflett.org/articles/session-fixation

## SSRF

 - [Understanding Server-Side Request Forgery](https://www.bishopfox.com/blog/2015/04/vulnerable-by-design-understanding-server-side-request-forgery/)
 - [Server Side Request Forgery (SSRF)](http://niiconsulting.com/checkmate/2015/04/server-side-request-forgery-ssrf/)
 - [Guide](documents/SSRFbible.Cheatsheet.pdf)
 - [A New Era of SSRF - Exploiting URL Parser in
Trending Programming Languages!](https://www.blackhat.com/docs/us-17/thursday/us-17-Tsai-A-New-Era-Of-SSRF-Exploiting-URL-Parser-In-Trending-Programming-Languages.pdf)
 - [How I Chained 4 vulnerabilities on GitHub Enterprise, From SSRF Execution Chain to RCE!](http://blog.orange.tw/2017/07/how-i-chained-4-vulnerabilities-on.html)

## CSRF

 - [Stealing Facebook access_tokens using CSRF in device login flow](https://www.josipfranjkovic.com/blog/hacking-facebook-csrf-device-login-flow)
 - [Report Spam. Get Owned](https://www.lanmaster53.com/2018/03/15/report-spam-get-owned/)

## SQLI

 - http://atta.cked.me/home/sqlite3injectioncheatsheet
 - http://gwae.trollab.org/sqlite-injection.html
 - https://www.trustwave.com/Resources/SpiderLabs-Blog/Sqlmap-Tricks-for-Advanced-SQL-Injection/
 - https://websec.wordpress.com/2010/03/19/exploiting-hard-filtered-sql-injections/
 - http://www.slideshare.net/stamparm/ph-days-2013miroslavstamparsqlmapunderthehood
 - Bypassing ``addslashes()`` ([post](http://shiflett.org/blog/2007/jan/addslashes-versus-mysql-real-escape-string))
 - http://ferruh.mavituna.com/sql-injection-cheatsheet-oku/
 - [Rails SQLI](http://rails-sqli.org/)
 - [Exploiting difficult SQL injection vulnerabilities using sqlmap: Part 1](http://www.thegreycorner.com/2017/01/exploiting-difficult-sql-injection.html)
 - [SQL Injection Wiki](https://sqlwiki.netspi.com/)

## XPath injection

 - [Slides](http://repository.root-me.org/Exploitation%20-%20Web/EN%20-%20Blind%20Xpath%20injection.pdf)
 - [Slides](https://github.com/feakk/xxxpwn/raw/master/HAAS_Kiwicon7-Automating%20Advanced%20XPath%20Injection%20Attacks.pdf)

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
 - [Linux ASLR and GNU Libc: Address space layout computing and defence, and “stack canary” protection bypass](documents/offensivecon-talk.pdf)
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
 - [ssh security](https://stribika.github.io/2015/01/04/secure-secure-shell.html)
 - [preg_replace()](https://bitquark.co.uk/blog/2013/07/23/the_unexpected_dangers_of_preg_replace)
 - [Modern Binary Exploitation](http://security.cs.rpi.edu/courses/binexp-spring2015/)
 - [CSAW Quals 2016 Pwn 500 - Mom's Spaghetti](http://ctfhacker.com/pwn/2016/09/19/csaw-moms-spaghetti.html)
 - [CFT Time](https://ctftime.org)
 - Rise of the machine [PDF](documents/ICIT-Brief-Rise-of-the-Machines.pdf)
 - [Readers of popular websites targeted by stealthy Stegano exploit kit hiding in pixels of malicious ads](http://www.welivesecurity.com/2016/12/06/readers-popular-websites-targeted-stealthy-stegano-exploit-kit-hiding-pixels-malicious-ads/)
 - [Don't use VPN services](https://gist.github.com/joepie91/5a9909939e6ce7d09e29)
 - [Facebook’s ImageTragick story](http://4lemon.ru/2017-01-17_facebook_imagetragick_remote_code_execution.html)
 - [Escaping a Python sandbox with a memory corruption bug](https://medium.com/@gabecpike/python-sandbox-escape-via-a-memory-corruption-bug-19dde4d5fea5)
 - [
Jinja2 template injection filter bypasses](https://0day.work/jinja2-template-injection-filter-bypasses/)
 - [Spring Boot RCE](http://deadpool.sh/2017/RCE-Springs/) via a template code injection
