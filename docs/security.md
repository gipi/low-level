# Security

User input **must** be sanitized!

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

## Custom code execution

See also [shellcode](/shellcode/).

 - Understanding the fundamentals of attacks What is happening when someone writes an exploit? awesome [slides](what_happens_exploit.pdf) by Halvar Flake & Thomas Dullien trying
   to formalize exploits
 - https://gbmaster.wordpress.com/2015/06/28/x86-exploitation-101-house-of-force-jedi-overflow/
 - http://0x90909090.blogspot.it/2015/07/no-one-expect-command-execution.html
 - GHOST vulnerability [report](http://www.openwall.com/lists/oss-security/2015/01/27/9)
 - [commix](https://github.com/stasinopoulos/commix): Automated All-in-One OS Command Injection and Exploitation Tool
 - [How To Heap](https://github.com/shellphish/how2heap): A repository for learning various heap exploitation techniques.

### Format String

 - [Exploiting Format String Vulnerabilities](http://repository.root-me.org/Exploitation%20-%20Syst%C3%A8me/Unix/EN%20-%20Exploiting%20Format%20String%20vulnerabilities.pdf)
 - [Advances in format string exploitation](http://phrack.org/issues/59/7.html) 0x0b, Issue 0x3b, Phile #0x07 of 0x12
 - [Howto remotely and automatically exploit a format bug](http://julianor.tripod.com/bc/remotefs.txt)

## LFI/RFI

 - https://www.idontplaydarts.com/2011/02/using-php-filter-for-local-file-inclusion/
 - https://www.idontplaydarts.com/2011/03/php-remote-file-inclusion-command-shell-using-data-stream/
 - [Liffy](https://github.com/rotlogix/liffy): Local File Inclusion Exploitation Tool

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

## CSRF

 - [Stealing Facebook access_tokens using CSRF in device login flow](https://www.josipfranjkovic.com/blog/hacking-facebook-csrf-device-login-flow)

## SQLI

 - http://atta.cked.me/home/sqlite3injectioncheatsheet
 - http://gwae.trollab.org/sqlite-injection.html
 - https://www.trustwave.com/Resources/SpiderLabs-Blog/Sqlmap-Tricks-for-Advanced-SQL-Injection/
 - https://websec.wordpress.com/2010/03/19/exploiting-hard-filtered-sql-injections/
 - http://www.slideshare.net/stamparm/ph-days-2013miroslavstamparsqlmapunderthehood
 - Bypassing ``addslashes()`` ([post](http://shiflett.org/blog/2007/jan/addslashes-versus-mysql-real-escape-string))
 - http://ferruh.mavituna.com/sql-injection-cheatsheet-oku/
 - [Rails SQLI](http://rails-sqli.org/)

## XPath injection

 - [Slides](http://repository.root-me.org/Exploitation%20-%20Web/EN%20-%20Blind%20Xpath%20injection.pdf)
 - [Slides](https://github.com/feakk/xxxpwn/raw/master/HAAS_Kiwicon7-Automating%20Advanced%20XPath%20Injection%20Attacks.pdf)

## Side channel

 - http://johoe.mooo.com/trezor-power-analysis/
 - [Side-channel attacks on high-security electronic safe locks](https://media.defcon.org/DEF%20CON%2024/DEF%20CON%2024%20presentations/DEFCON-24-Plore-Side-Channel-Attacks-On-High-Security-Electronic-Safe-Locks.pdf)

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

## Heap 

 - [Once upon a free()](http://phrack.org/issues/57/9.html)
 - [Vudo - An object superstitiously believed to embody magical powers](http://phrack.org/issues/57/8.html)
 - [MALLOC DES-MALEFICARUM](http://phrack.org/issues/66/10.html)
 - [Understanding glibc malloc](https://sploitfun.wordpress.com/2015/02/10/understanding-glibc-malloc/)
 - [Heap Exploitation](http://security.cs.rpi.edu/courses/binexp-spring2015/lectures/17/10_lecture.pdf) slides from from Modern Binary Exploitation

## Kernel exploiting

 - [Kernel stack overflows (basics)](https://blog.0x80.org/kernel-stack-overflows-basics/)
 - [Writing kernel exploits](https://tc.gtisc.gatech.edu/bss/2014/r/kernel-exploits.pdf)
 - [Linux Kernel Exploitation](http://repository.root-me.org/Exploitation%20-%20Syst%C3%A8me/Unix/EN%20-%20Linux%20Kernel%20Exploitation%20-%20Patrick%20Biernat.pdf) slides from Modern Binary Exploitation

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

## CTF

 - [Vulnhub](https://www.vulnhub.com/) To provide materials that allows anyone to gain
   practical 'hands-on' experience in digital security, computer software & network administration.
 - [root-me](https://www.root-me.org)
 - [The DEFCON CTF VM](http://fuzyll.com/2016/the-defcon-ctf-vm/)
 - [TUM CTF 2016 video solution](https://www.youtube.com/watch?v=y69uIxU0eI8) and its [gist](https://gist.github.com/LiveOverflow/3bd87ba4ffc48bda07d82eb4223911fa)
   and [here](https://anee.me/writeup-for-zwiebel-tum-ctf-2016-e312fc129037) another writeup.

## Links

 - [online courses](https://github.com/prakhar1989/awesome-courses#security)
 - [ssh security](https://stribika.github.io/2015/01/04/secure-secure-shell.html)
 - [preg_replace()](https://bitquark.co.uk/blog/2013/07/23/the_unexpected_dangers_of_preg_replace)
 - [Modern Binary Exploitation](http://security.cs.rpi.edu/courses/binexp-spring2015/)
 - [CSAW Quals 2016 Pwn 500 - Mom's Spaghetti](http://ctfhacker.com/pwn/2016/09/19/csaw-moms-spaghetti.html)
 - [CFT Time](https://ctftime.org)
 - Rise of the machine [PDF](documents/ICIT-Brief-Rise-of-the-Machines.pdf)
 - [Readers of popular websites targeted by stealthy Stegano exploit kit hiding in pixels of malicious ads](http://www.welivesecurity.com/2016/12/06/readers-popular-websites-targeted-stealthy-stegano-exploit-kit-hiding-pixels-malicious-ads/)
