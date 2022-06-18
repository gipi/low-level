# Algorithms

 - [Algorithm tutorials](http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=alg_index)
 - [Visualizing Algorithms](http://bost.ocks.org/mike/algorithms/)
 - [Ramer–Douglas–Peucker algorithm](http://en.wikipedia.org/wiki/Ramer%E2%80%93Douglas%E2%80%93Peucker_algorithm): is an algorithm for reducing the number of points in a curve that is approximated by a series of points.
 - [PID controller](http://playground.arduino.cc/Code/PIDLibrary): calculates an 'error' value as the difference between a measured [Input] and a desired setpoint. The controller attempts to minimize the error by adjusting [an Output].
 - http://brm.io/game-physics-for-beginners/
 - http://spin.atomicobject.com/2014/09/03/visualizing-garbage-collection-algorithms/
 - http://fabiensanglard.net/rayTracing_back_of_business_card/index.php
 - http://rayli.net/blog/data/top-10-data-mining-algorithms-in-plain-english/
 - https://pograph.wordpress.com/2009/06/04/notes-on-gzip-and-deflate-format/
 - [Stable sorting in javascript](http://blog.vjeux.com/2010/javascript/javascript-sorting-table.html)
 - [Blob Sallad — Canvas Tag and JavaScript Physics Simulation Experiment](https://dev.opera.com/articles/blob-sallad-canvas-tag-and-javascript/)
 - [algorithm-cheat](https://github.com/cirosantilli/algorithm-cheat) Algorithm tutorials and simple multi-language implementations with unit tests.
 - [Modified preorder tree traversal](https://www.caktusgroup.com/blog/2016/01/04/modified-preorder-tree-traversal-django/)
 - [Answer](http://cstheory.stackexchange.com/questions/19759/core-algorithms-deployed/19773#19773) with a list of implemented algorithms in well known softwares
 - [Image Quadrangulation](https://estebanhufstedler.com/2020/05/05/image-quadrangulation/)
 - [Image Triangulation](https://estebanhufstedler.com/2020/05/14/image-triangulation/)
 - [Image Triangulation: Voronoi Method](https://estebanhufstedler.com/2020/05/14/image-triangulation-voronoi-method/)
 - [Algorithms for sampling without replacement](https://timvieira.github.io/blog/post/2019/09/16/algorithms-for-sampling-without-replacement/)
 - [How a Kalman filter works, in pictures](https://www.bzarg.com/p/how-a-kalman-filter-works-in-pictures/)
 - [Floyd-Steinberg dithering](https://datagenetics.com/blog/february12021/index.html)

## Bloom filter

Bloom filters are space-efficient probablistic data structures used to test whether an element is a member of a set.

 - [Wikipedia entry](https://en.wikipedia.org/wiki/Bloom_filter)
 - [Bloom filter calculator](https://hur.st/bloomfilter/)
 - [Bloom filters debunked: Dispelling 30 Years of bad math with Coq!](https://gopiandcode.uk/logs/log-bloomfilters-debunked.html)
 - [When Bloom filters don't bloom](https://blog.cloudflare.com/when-bloom-filters-dont-bloom/)

## Channel coding&Error-correcting codes

 - [Reed-Solomon Codes](http://tesi.cab.unipd.it/43857/1/martini_tommaso_1008717_reedSolomonCodes.pdf)
 - [Linear Feedback Shift Registers for the Uninitiated, Part XVI: Reed-Solomon Error Correction](https://www.embeddedrelated.com/showarticle/1182.php)

### CRC

 - [Cyclic Redundancy Check (CRC)](http://ww1.microchip.com/downloads/en/appnotes/01148a.pdf)
 - [Cyclic Redundancy Check: TMS320C64+ Implementation](http://ww1.microchip.com/downloads/en/appnotes/01148a.pdf)
 - [What Truncated polynomial mean in CRC16 CCITT context](https://stackoverflow.com/questions/40787529/what-truncated-polynomial-mean-in-crc16-ccitt-context)
 - [Best CRC Polynomials](https://users.ece.cmu.edu/~koopman/crc/)
 - [Brute forcing CRC parameters](http://sitsec.net/blog/2012/02/10/brute-forcing-crc-parameters/)
 - [CRC16-CCITT](http://srecord.sourceforge.net/crc16-ccitt.html)
 - [crcmod](http://crcmod.sourceforge.net/) python module
 - [CRC Tool Kit](https://github.com/henryk/ctk)

## Search

### Breadth First Search (BFS)

In this mode you explore all states that can be reached on one step, then all
states that can be reached in two steps, etc...

Its time complexity can be expressed as

$$
O\left(\| V \| + \| E \|\right)
$$

#### 0-1 BFS

It's used for weighted graphs.

## Sorting

### Selection sort

**Time:** \\(\Omega(n^2)\\) **Space:** \\(\Omega(1)\\)

It works by iterating over each element of the list, in order to find
the smallest element to move in the needed position

 - [Wikipedia](https://en.wikipedia.org/wiki/Selection_sort)

### Insertion sort

**Time:** \\(\Omega(n^2)\\) or \\(\Omega(n)\\) **Space:** \\(\Omega(1)\\)

This works iterating over all elements for each entry ordering the ith element
via insertion in the right position (practically implemented swapping). This
has the property that at the ith step, the first i elements are ordered.

In general, insertion sort will write to the array \\(\Omega(n^2)\\) times,
whereas selection sort will write only \\(\Omega(n)\\) times. For this reason
selection sort may be preferable in cases where writing to memory is
significantly more expensive than reading, such as with EEPROM or flash memory.

### Merge sort

**Time:** \\(\Omega(n\log(n))\\) **Space:** \\(\Omega(n)\\)

This algorthm acts recursively: it works in two steps

 1. split in half the input and calls itself in each piece if length(piece) >= 4
 2. when it merges, it builds the new piece taking the smallest element available
 between the two originals

 - [Wikipedia](https://en.wikipedia.org/wiki/Merge_sort)

### Quick sort

**Time:** \\(\Omega(n\log(n))\\) **Space:** \\(\Omega(\log n)\\)

This is a divide and conquer algorithm that works in the following way

 1. picks a **pivot element**
 2. reorders the elements so that


 - [Insertion sort vs Bubble Sort Algorithms](https://stackoverflow.com/questions/17270628/insertion-sort-vs-bubble-sort-algorithms)

## Procedural generation

 - [Wave Function Collapse tips and tricks](https://www.boristhebrave.com/2020/02/08/wave-function-collapse-tips-and-tricks/)
