# Security

User input **must** be sanitized!

## Custom code execution

See also [shellcode](/shellcode/).

## LFI/RFI

 - https://www.idontplaydarts.com/2011/02/using-php-filter-for-local-file-inclusion/
 - https://www.idontplaydarts.com/2011/03/php-remote-file-inclusion-command-shell-using-data-stream/

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


## Tools

 - https://code.google.com/p/skipfish/
