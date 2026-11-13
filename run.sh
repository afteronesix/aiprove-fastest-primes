#!/bin/sh
# Build once (cached), then run. Times the sieve, not the compiler, on repeats.
cd "$(dirname "$0")"
[ -x primes ] || gcc -O3 -o primes primes.c
exec ./primes
