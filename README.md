# diehard-hash-test

[A cryptographic hash function](https://en.wikipedia.org/wiki/Cryptographic_hash_function) does a one way transformation from a value to a hash value.
An attempt to return the hash value to its original value leads to a computation which is nearly impossible or not feasible to do.

[Avalanche effect](https://en.wikipedia.org/wiki/Avalanche_effect) is one of desired effects to be available on a hash function. It leads a small change in the input value to a completely different hash value.

Given a predictable sequence of numbers, this experiment tests the ability of a predefined set of hash functions to hide the pattern of the input sequence.
The hash function should returns an unpredictable sequence of hash values which will be tested using DieHard tests.

[DieHard tests](https://en.wikipedia.org/wiki/Diehard_tests) themselves are a battery of statistical tests which is used for testing randomness of a random number generator.
