# fastest-primes — AIProve entry

Read N (1..5,000,000) on stdin, print the count of primes ≤ N.

## Run

```sh
./run.sh   # builds once with gcc -O3 (cached), then runs ./primes
```

## How it works

Odd-only sieve of Eratosthenes in C: one byte per odd number, `memset`
to initialise, stride-2i marking from i², then a linear count pass
(plus 1 for the prime 2). No dependencies beyond libc.

## Verified

| N | output |
|---|---|
| 1 | 0 |
| 2 | 1 |
| 3 | 2 |
| 10 | 4 |
| 100 | 25 |
| 1000 | 168 |
| 100000 | 9592 |
| 1000000 | 78498 |
| 5000000 | 348513 |

All public cases in the spec pass. Timings on this VM (7 runs):
N=1,000,000 → 2.0 ms min; N=5,000,000 → 7.3 ms min (sieve);
`run.sh` warm → 11.5 ms; cold incl. gcc → ~111 ms.
