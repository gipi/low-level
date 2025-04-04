# Data structures

 - [bigocheatsheet](http://bigocheatsheet.com/)
 - [Open Data Structures (in pseudocode)](http://opendatastructures.org/ods-python.pdf)
 - [Coding Interview University](https://github.com/jwasham/coding-interview-university) A complete computer science study plan to become a software engineer.
 - [Shenanigans With Hash Tables](http://thume.ca/2019/07/29/shenanigans-with-hash-tables/)
 - [Think Complexity](http://greenteapress.com/complexity/index.html): free book about data structures and algorithm
 - [The Lost Art of C Structure Packing](http://www.catb.org/esr/structure-packing/)
 - [Lynda - Data Structure](https://archive.org/details/0102WhatYouShouldKnow)

| Name        | Insert   | Deletion | Search | Note |
|-------------|----------|----------|--------|------|
| Linked list | O(1)     | O(1)     | O(N)   |      |
| Array       | O(1)     | O(1)     | O(N)   | insertion and deletion should take into account the memory management |
| Stack       | O(1)     | O(N)     | O(N)   | there is not proper delete/search operation |
| Queue       | O(1)     | O(N)     | O(N)   | there is not proper delete/search operation |
| BST         | O(N), O(log N) | O(N), O(log N) | O(N), O(log N) | depend strongly on how balanced is |
| Dictionary  | O(1)     | O(1)     | O(1)   | |


| Name        | Insert   | Extract Min | Min  |
|-------------|----------|-------------|------|
| Heap        | O(log N) | O(log N)    | O(1) |

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

A tree is a graph that is not cyclic.

The number of **unlabeled** trees with \\(N\\) nodes is given by the Catalan's numbers

$$
T(N) = \sum_{i=1}^{N} T(i - 1)\cdot T(N - i) = {(2N)!\over(N + 1)!N!}
$$

instead for **labeled** binary tree we have

$$
T^\prime(N)= N!T(N) = {(2N)!\over(N + 1)!}
$$

### Binary tree

This is a subset of trees where nodes can only have up to to 2 child, usually named **left**
and **right**.

There are a couple of ordering mechanism: take the following binary tree

```
      <A>
     /   \
   <B>   <C>
  /   \
<D>   <E>
```

**pre-order** returns ``A, B, D, E, C``performing the following steps

 - return the root node
 - traverse recursively the left subtree
 - traverse recursively the right subtree

**in-order** returns ``D, B, E, A, C`` performing the following steps

 - traverse recursively the left subtree
 - return the root node
 - traverse recursively the right subtree

**post-order** returns ``D, E, B, C, A`` instead with the following procedure

 - traverse recursively the left subtree
 - traverse recursively the right subtree
 - return the root node

**level-order** returns ``A, B, C, D, E``, the steps are

 1. add the root node to a queue
 2. pop the last node from the queue and return it
 3. add all children  of popped node to queue and continue from step 2 until queue is empty

### B-Tree

Particular form of tree that extends that binary search tree

According to Knuth's definition, a B-tree of order m is a tree which satisfies the following properties:

 - Every node has at most m children.
 - Every internal node has at least ⌈m/2⌉ children.
 - Every non-leaf node has at least two children.
 - All leaves appear on the same level.
 - A non-leaf node with k children contains k−1 keys.

Each internal node's keys act as separation values which divide its subtrees.
For example, if an internal node has 3 child nodes (or subtrees) then it must
have 2 keys: a1 and a2. All values in the leftmost subtree will be less than
a1, all values in the middle subtree will be between a1 and a2, and all values
in the rightmost subtree will be greater than a2.

### Links

 - [Modified pre order traversal tree](https://imrannazar.com/Modified-Preorder-Tree-Traversal)
 - [django-mptt/django-mptt](https://github.com/django-mptt/django-mptt) Utilities for implementing a modified pre-order traversal tree in django
 - [Tree traversal algorithms](https://www.coderbyte.com/algorithm/tree-traversal-algorithms)
 - [Inorder Tree Traversal without Recursion](https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/)


## Tools

 - [visualgo.net](http://visualgo.net/): visualising data structures and algorithms through animation
