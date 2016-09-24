# XSS

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
 - [Building Advanced XSS Vectors](http://brutelogic.com.br/docs/advanced-xss.pdf)
 - [UNDERSTANDING XSS AUDITOR](https://www.virtuesecurity.com/blog/understanding-xss-auditor/)
 - [A comprehensive tutorial on cross-site scripting](http://excess-xss.com/)
 - [Writeup](https://medium.com/@eoftedal/xss-puzzler-622f6f86c277) about ``XSS puzzler``

## RPO

It stands for *relative path overwrite*.

 - [First article about it](http://www.thespanner.co.uk/2014/03/21/rpo/)
 - [RPO gadgets](http://blog.innerht.ml/rpo-gadgets/)
