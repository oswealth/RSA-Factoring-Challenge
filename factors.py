#!/usr/bin/env python3

import random
import math


"""
A function that returns a list of factors of a natural number
using Fermat's factorization method
"""


def find_factors(n):
    factors = []
    if n % 2 == 0:
        n = n // 2
        factors.append(2)

    while n % 2 == 0:
        n = n // 2
        factors.append(2)
    if n == 1:
        return factors
    if is_prime(n):
        factors.append(n)
        return factors

    a = math.ceil(math.sqrt(n))
    b = math.floor(math.sqrt(n))
    while True:
        c = a * a - b * b
        if c == n:
            factors.append(a - b)
            factors.append(a + b)
            break
        elif c < n:
            a += 1
        else:
            b -= 1
    return factors


"""
A function that checks if a natural number is prime
using the Miller-Rabin primality test
"""


def is_prime(n):
    if n == 2 or n == 3:
        return True
    if n < 2 or n % 2 == 0:
        return False
    r = 0
    d = n - 1
    while d % 2 == 0:
        r += 1
        d = d // 2

    a = random.randint(2, n - 2)
    x = pow(a, d, n)
    if x == 1 or x == n - 1:
        return True
    for _ in range(r - 1):
        x = pow(x, 2, n)
        if x == 1:
            return False
        if x == n - 1:
            return True
    return False


"""
A function that returns a pair of two smaller numbers that multiply to n
"""


def choose_pair(factors):
    p = factors[0]
    q = factors[-1]
    return p, q


"""
A main function that takes a file name as an argument and prints the output
"""


def main(filename):
    try:
        with open(filename, "r") as f:
            lines = f.readlines()
    except FileNotFoundError:
        print("File not found")
        return
    if not lines:
        print("File is empty")
        return
    for line in lines:
        try:
            n = int(line.strip())
        except ValueError:
            print("Invalid input")
            continue
        if n == 0:
            print("0 cannot be factorized")
            continue
        if n < 0:
            print(f"{n} is not a natural number")
            continue
        factors = find_factors(n)
        p, q = choose_pair(factors)
        print(f"{n} = {p} * {q}")


if __name__ == "__main__":
    import sys
    main(sys.argv[1])
