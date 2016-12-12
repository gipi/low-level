# Random

A number is said to be random if the minimal size of a program generating n
decimals of the number is at least of size n. Intuitevely, this means that we
can't compress the information contained in this number.  More precisly, this
approach is linked to the fact that since the property of getting a precise
sequence of decimals is null, we can't easily use the thoerem of measure. But we
can use the computability theory developed in the 40s by Gödel, Turing, Church
and Kleene. This theory implies that not all sequences of numbers are
programable, hence can not be calculated by machines. With the help of those
work, other lead by Kolmogorov, Solomonoff, Chaitin and Martin-Löf in the 60s
precised the definition of a random number with Martin-Löf 's meaning as a
number not possesing an exceptional property that we can effectively check.

We land back on the theory of measure by defining an exceptional property as a
property that is certainly not checked. So that we don't get trapped by some
very special case but we don't know which, we add the condition of effective
checking. This signifies that we can verify the property with a program and a
risk of being wrong that lessen with the degree of checking.

## Tests

It's possible to use ``dieharder`` to asses randomness of a given sample:

```
$ dd if=/dev/zero of=random.bin bs=1M count=1024
1024+0 record dentro
1024+0 record fuori
1073741824 byte (1,1 GB) copiati, 1,71588 s, 626 MB/s
$ dieharder -g 201 -a -f random.bin

```

## Randomness of Pi

$$
\pi = \sum_{k=0}^\infty\,{1\over16^k}\left[{4\over 8k+1} - {2\over 8k+4} - {1\over 8i + 5} - {1\over 8k + 6}\right]
$$

## Links

 - https://www.cr0.org/progs/sshfun/
 - https://www.seancassidy.me/your-own-verifiable-hardware-rng-with-bladerf-sdr.html
 - [Randomness of Pi](http://www.pi314.net/eng/statistique.php)
 - [Post](http://www.turingfinance.com/hacking-the-random-walk-hypothesis/) about random walk and finance
 - Posts about hacking random number generators [1](https://jazzy.id.au/2010/09/20/cracking_random_number_generators_part_1.html) [2](https://jazzy.id.au/2010/09/21/cracking_random_number_generators_part_2.html) [3](https://jazzy.id.au/2010/09/22/cracking_random_number_generators_part_3.html)
 - [Can randomness add computability](https://mathoverflow.net/questions/58060/can-randomness-add-computability)
 - [Backdoors in Pseudorandom Number Generators: Possibility and Impossibility Results](https://eprint.iacr.org/2016/577.pdf)
