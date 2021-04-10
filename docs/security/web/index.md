# Web vulnerabilities

## LFI/RFI

 - https://www.idontplaydarts.com/2011/02/using-php-filter-for-local-file-inclusion/
 - https://www.idontplaydarts.com/2011/03/php-remote-file-inclusion-command-shell-using-data-stream/
 - [Liffy](https://github.com/rotlogix/liffy): Local File Inclusion Exploitation Tool
 - [Upgrade from LFI to RCE via PHP Sessions](https://www.rcesecurity.com/2017/08/from-lfi-to-rce-via-php-sessions/)
 - [Exploiting PHP File Inclusion – Overview](https://websec.wordpress.com/2010/02/22/exploiting-php-file-inclusion-overview/)
 - [Exploiting Remote File Inclusion (RFI) in PHP application and bypassing remote URL inclusion restriction](http://www.mannulinux.org/2019/05/exploiting-rfi-in-php-bypass-remote-url-inclusion-restriction.html?)
 - [Bitbucket 6.1.1 Path Traversal to RCE](https://blog.ripstech.com/2019/bitbucket-path-traversal-to-rce/)

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
 - [Guide](/documents/SSRFbible.Cheatsheet.pdf)
 - [A New Era of SSRF - Exploiting URL Parser in
Trending Programming Languages!](https://www.blackhat.com/docs/us-17/thursday/us-17-Tsai-A-New-Era-Of-SSRF-Exploiting-URL-Parser-In-Trending-Programming-Languages.pdf)
 - [How I Chained 4 vulnerabilities on GitHub Enterprise, From SSRF Execution Chain to RCE!](http://blog.orange.tw/2017/07/how-i-chained-4-vulnerabilities-on.html)
 - [Vimeo upload function SSRF](https://medium.com/@dPhoeniixx/vimeo-upload-function-ssrf-7466d8630437)
 - [Hidden OAuth attack vectors](https://portswigger.net/research/hidden-oauth-attack-vectors)

## CSRF

 - [Stealing Facebook access_tokens using CSRF in device login flow](https://www.josipfranjkovic.com/blog/hacking-facebook-csrf-device-login-flow)
 - [Report Spam. Get Owned](https://www.lanmaster53.com/2018/03/15/report-spam-get-owned/)

## SQLI

 - [Understanding the full potential of sqlmap during bug bounty hunting](https://vavkamil.cz/2019/10/09/understanding-the-full-potential-of-sqlmap-during-bug-bounty-hunting/)
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

## Cloud

 - [madhuakula/kubernetes-goat](https://github.com/madhuakula/kubernetes-goat) designed to be intentionally vulnerable cluster environment to learn and practice Kubernetes security.
