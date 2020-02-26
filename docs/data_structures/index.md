# Data structures

 - http://bigocheatsheet.com/
 - [Open Data Structures (in pseudocode)](http://opendatastructures.org/ods-python.pdf)
 - [Coding Interview University](https://github.com/jwasham/coding-interview-university) A complete computer science study plan to become a software engineer.
 - [Shenanigans With Hash Tables](http://thume.ca/2019/07/29/shenanigans-with-hash-tables/)
 - [Think Complexity](http://greenteapress.com/complexity/index.html): free book about data structures and algorithm
 - [The Lost Art of C Structure Packing](http://www.catb.org/esr/structure-packing/)
 - [Lynda - Data Structure](https://archive.org/details/0102WhatYouShouldKnow)

## Hash tables

### Multiplicative hashing

We start with defining an hash function that takes a value
from w-bit integer and returns a d-bit integer (the hash)

```
hash(x):
    return ((z*x) mod 2**w) >> (w - d)
```

z is an **odd integer** chosen at random. Mathematically this works because the set of odd
integers module \\(2^w\\) forms a modular multiplicative group (I know \\(x\\) can be even
but hey, this is not cryptography :P). [Moreover](https://en.wikipedia.org/wiki/Multiplicative_group_of_integers_modulo_n#Powers_of_2)

$$
\left(Z/2^k Z\right)^\times\sim C_2\times C_{2^{k - 2}}
$$

not being a **cyclic group** we know that it will not span all the domain.

 - multiplicative hashing POC [hash.c](hash.c)

## Trees

 - [django-mptt/django-mptt](https://github.com/django-mptt/django-mptt) Utilities for implementing a modified pre-order traversal tree in django


## Tools

 - [visualgo.net](http://visualgo.net/): visualising data structures and algorithms through animation
