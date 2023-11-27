#!/usr/bin/env python3
"""
A module that contains functions for finding prime factors of a natural number
using Fermat's factorization method and the Miller-Rabin primality test.
"""

import random
import math


def find_prime_factors(number):
    """Return a list of prime factors of a natural number.

    Args:
        number (int): The natural number to be factorized.

    Returns:
        list: A sorted list of prime factors of the number.

    Raises:
        ValueError: If the number is not a natural number.
    """
    if number < 0:
        raise ValueError(f"{number} is not a natural number")

    prime_factors = []
    if number % 2 == 0:
        number = number // 2
        prime_factors.append(2)
    while number % 2 == 0:
        number = number // 2
        prime_factors.append(2)
    if number == 1:
        return prime_factors
    if is_prime(number):
        prime_factors.append(number)
        return prime_factors

    a = math.ceil(math.sqrt(number))
    b = math.floor(math.sqrt(number))
    while True:
        c = a * a - b * b
        if c == number:
            if is_prime(a - b):
                prime_factors.append(a - b)
            else:
                prime_factors.extend(find_prime_factors(a - b))
            if is_prime(a + b):
                prime_factors.append(a + b)
            else:
                prime_factors.extend(find_prime_factors(a + b))
            break
        elif c < number:
            a += 1
        else:
            b -= 1
    return sorted(prime_factors)


def is_prime(number):
    """if a natural number is prime using the Miller-Rabin primality test.

    Args:
        number (int): The natural number to be checked.

    Returns:
        bool: True if the number is prime, False otherwise.

    Raises:
        ValueError: If the number is not a natural number.
    """
    if number < 0:
        raise ValueError(f"{number} is not a natural number")

    if number == 2 or number == 3:
        return True
    if number < 2 or number % 2 == 0:
        return False
    r = 0
    d = number - 1
    while d % 2 == 0:
        r += 1
        d = d // 2

    a = random.randint(2, number - 2)
    x = pow(a, d, number)
    if x == 1 or x == number - 1:
        return True
    for _ in range(r - 1):
        x = pow(x, 2, number)
        if x == 1:
            return False
        if x == number - 1:
            return True
    return False


def main(filename):
    """Read a natural number from a file and print its prime factors.

    Args:
        filename (str): The name of the file that contains the number.

    Prints:
        str: A string that shows the number and its prime factors.
    """
    try:
        with open(filename, "r") as f:
            line = f.readline()
    except FileNotFoundError:
        print("File not found")
        return
    if not line:
        print("File is empty")
        return
    try:
        number = int(line.strip())
    except ValueError:
        print("Invalid input")
        return
    if number == 0:
        print("0 cannot be factorized")
        return
    if number < 0:
        print(f"{number} is not a natural number")
        return
    prime_factors = find_prime_factors(number)
    print(f"{number} = {prime_factors[0]} * {prime_factors[1]}")


if __name__ == "__main__":
    import sys
    main(sys.argv[1])
