# Browsers security

A browser works like a modern operating system and has its own
library, memory model etc...

## JavascriptCore

 - [Phrack's paper](http://www.phrack.org/papers/attacking_javascript_engines.html) .:: Attacking JavaScript Engines: A case study of JavaScriptCore and CVE-2016-4622 ::.
 - [CVE-2017-2446 or JSC::JSGlobalObject::isHavingABadTime](https://doar-e.github.io/blog/2018/07/14/cve-2017-2446-or-jscjsglobalobjectishavingabadtime/)
 - [Patch Gapping a Safari Type Confusion](https://blog.theori.io/research/webkit-type-confusion/)
 - [JITSploitation I: A JIT Bug](https://googleprojectzero.blogspot.com/2020/09/jitsploitation-one.html)
 - [JITSploitation II: Getting Read/Write](https://googleprojectzero.blogspot.com/2020/09/jitsploitation-two.html)
 - [THIS IS FOR THE PWNERS: EXPLOITING A WEBKIT 0-DAY IN PLAYSTATION ](https://www.synacktiv.com/publications/this-is-for-the-pwners-exploiting-a-webkit-0-day-in-playstation-4.html)
 - [Some Brief Notes on WebKit Heap Hardening](https://labs.f-secure.com/archive/some-brief-notes-on-webkit-heap-hardening/)
 - [Step-by-Step Walkthrough of CVE-2022-32792 - WebKit B3ReduceStrength Out-of-Bounds Write](https://starlabs.sg/blog/2022/09-step-by-step-walkthrough-of-cve-2022-32792/)
 - [Exploiting WebKit JSPropertyNameEnumerator Out-of-Bounds Read (CVE-2021-1789)](https://starlabs.sg/blog/2022/08-exploiting-webkit-jspropertynameenumerator-out-of-bounds-read-cve-2021-1789/)

## V8

 - [Exploiting Logic Bugs in JavaScript JIT Engines](http://phrack.org/papers/jit_exploitation.html) by saelo on Phrack
 - [Intro to Chrome’s V8 from an exploit development angle](https://sensepost.com/blog/2020/intro-to-chromes-v8-from-an-exploit-development-angle/)
 - [Geluchat/chrome_v8_exploit](https://github.com/Geluchat/chrome_v8_exploit) A collection of 1days and solutions to challenges related to v8/chrome I developed
 - [Exploiting the Math.expm1 typing bug in V8](https://abiondo.me/2019/01/02/exploiting-math-expm1-v8/)
 - [Modern attacks on the Chrome browser : optimizations and deoptimizations](https://doar-e.github.io/blog/2020/11/17/modern-attacks-on-the-chrome-browser-optimizations-and-deoptimizations/)
 - [ELECTRIC CHROME - CVE-2020-6418 on Tesla Model 3](https://leethax0.rs/2021/04/ElectricChrome/)
 - [V8 Exploitation Series](https://www.madstacks.dev/categories/v8-series/)
 - [Chrome Browser Exploitation, Part 3: Analyzing and Exploiting CVE-2018-17463](https://jhalon.github.io/chrome-browser-exploitation-3/)

## SpiderMonkey

 - [Exploiting CVE-2019-17026 - A Firefox JIT Bug](https://labs.f-secure.com/blog/exploiting-cve-2019-17026-a-firefox-jit-bug/)
 - [BUT YOU TOLD ME YOU WERE SAFE: ATTACKING THE MOZILLA FIREFOX RENDERER (PART 1)](https://www.zerodayinitiative.com/blog/2022/8/17/but-you-told-me-you-were-safe-attacking-the-mozilla-firefox-renderer-part-1)

## Links

 - [browsersploit](https://github.com/julienbedard/browsersploit) is an advanced browser exploit pack for doing internal and external pentesting, helping gaining access to internal computers.
 - [malware jail](https://github.com/HynekPetrak/malware-jail) Sandbox for semi-automatic Javascript malware analysis, deobfuscation and payload extraction. Written for Node.js
 - [phoenhex.re](https://phoenhex.re/) pwning WebKit related browsers
 - [Learning browser exploitation via 33C3 CTF feuerfuchs challenge](https://bruce30262.github.io/2017/12/15/Learning-browser-exploitation-via-33C3-CTF-feuerfuchs-challenge/)
 - [Timeless Debugging of Complex Software - Root Cause Analysis of a Non-Deterministic JavaScriptCore Bug](https://blog.ret2.io/2018/06/19/pwn2own-2018-root-cause-analysis/)
 - [Introduction to SpiderMonkey exploitation](https://doar-e.github.io/blog/2018/11/19/introduction-to-spidermonkey-exploitation/)
 - [CVE-2019-0539 Exploitation. Microsoft Edge Chakra JIT Type Confusion](https://perception-point.io/resources/research/cve-2019-0539-exploitation/)
 - [Writeup for CVE-2019-11707](https://blog.bi0s.in/2019/08/18/Pwn/Browser-Exploitation/cve-2019-11707-writeup/)
 - [saelo/3_years_of_attacking_javascript_engines.txt](https://gist.github.com/saelo/dd598a91a27ddd7cb9e410dc92bf37a1)
 - [Cleanly Escaping the Chrome Sandbox](https://theori.io/research/escaping-chrome-sandbox/)

