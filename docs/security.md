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

 - https://gbmaster.wordpress.com/2015/06/28/x86-exploitation-101-house-of-force-jedi-overflow/
 - http://0x90909090.blogspot.it/2015/07/no-one-expect-command-execution.html
 - GHOST vulnerability [report](http://www.openwall.com/lists/oss-security/2015/01/27/9)
 - [commix](https://github.com/stasinopoulos/commix): Automated All-in-One OS Command Injection and Exploitation Tool

## LFI/RFI

 - https://www.idontplaydarts.com/2011/02/using-php-filter-for-local-file-inclusion/
 - https://www.idontplaydarts.com/2011/03/php-remote-file-inclusion-command-shell-using-data-stream/
 - [Liffy](https://github.com/rotlogix/liffy): Local File Inclusion Exploitation Tool

## RCE

 - [Bookfresh case](https://www.secgeek.net/bookfresh-vulnerability/)
 - Encoding Web Shell in PNG IDAT chunks ([post](https://www.idontplaydarts.com/2012/06/encoding-web-shells-in-png-idat-chunks/))
 - Exploiting PHP-GD imagecreatefromgif() function ([github repo](https://github.com/d0lph1n98/Defeating-PHP-GD-imagecreatefromgif))

## HTTP parameters pollution

HPP attacks can be defined as the feasibilty to override or add ``HTTP`` ``GET``/``POST`` parameters
by injecting query string delimiters. ``HtmlEntities`` are out of context here.


 - OWASP [slide](http://www.slideshare.net/Wisec/http-parameter-pollution-a-new-category-of-web-attacks)
 - Black Hat [slide](http://www.iseclab.org/people/embyte/slides/BHEU2011/hpp-bhEU2011.pdf)

## Session Fixation

 - http://shiflett.org/articles/session-fixation

## XSS

When a browser is rendering HTML and any other associated content like CSS, javascript, etc.
it identifies various rendering contexts for the different kinds of input and follows different
rules for each context. A rendering context is associated with the parsing of HTML tags and their
attributes. The HTML parser of the rendering context dictates how data is presented and laid out
on the page and can be further broken down into the standard contexts of HTML, HTML attribute, URL,
and CSS. The JavaScript or VBScript parser of an execution context is associated with the parsing
and execution of script code. Each parser has distinct and separate semantics in the way they can
possibly execute script code which make creating consistent rules for mitigating vulnerabilities
in various contexts difficult. The complication is compounded by the differing meanings and
treatment of encoded values within each subcontext (HTML, HTML attribute, URL, and CSS) within the
execution context.

 - https://www.owasp.org/index.php/DOM_based_XSS_Prevention_Cheat_Sheet

## SQLI

 - http://atta.cked.me/home/sqlite3injectioncheatsheet
 - http://gwae.trollab.org/sqlite-injection.html
 - https://www.trustwave.com/Resources/SpiderLabs-Blog/Sqlmap-Tricks-for-Advanced-SQL-Injection/
 - https://websec.wordpress.com/2010/03/19/exploiting-hard-filtered-sql-injections/
 - http://www.slideshare.net/stamparm/ph-days-2013miroslavstamparsqlmapunderthehood
 - Bypassing ``addslashes()`` ([post](http://shiflett.org/blog/2007/jan/addslashes-versus-mysql-real-escape-string))
 - http://ferruh.mavituna.com/sql-injection-cheatsheet-oku/

## XXE

 - http://blog.h3xstream.com/2014/06/identifying-xml-external-entity.html
 - https://www.owasp.org/images/5/5d/XML_Exteral_Entity_Attack.pdf
 - https://users.dimi.uniud.it/~massimo.franceschet/caffe-xml/dtd/dtd-definitions4.html

## Side channel

 - http://johoe.mooo.com/trezor-power-analysis/

## Tools

 - https://code.google.com/p/skipfish/
 - Damn Vulnerable Web App [site](http://www.dvwa.co.uk/)
 - [DNSteal](https://github.com/m57/dnsteal): stealthily extract files from a victim machine through DNS requests
 - [pwntools](https://pwntools.readthedocs.org) CTF framework and exploit development library
