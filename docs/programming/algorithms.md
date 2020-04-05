# Algorithms

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

