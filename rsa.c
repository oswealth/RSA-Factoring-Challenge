#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/**
 * find_prime_factors - Return a list of prime factors of a natural number
 * using Fermat's factorization method.
 * @n: The natural number to be factorized.
 * Return: A sorted list of prime factors of the number, or NULL on failure.
 */
long long int *find_prime_factors(long long int n)
{
	long long int *prime_factors;
	long long int a, b, c;

	if (n < 0)
		return (NULL);
	prime_factors = malloc(2 * sizeof(long long int));
	if (!prime_factors)
		return (NULL);
	if (n % 2 == 0)
	{
		n = n / 2;
		prime_factors[0] = 2;
	}
	while (n % 2 == 0)
	{
		n = n / 2;
		prime_factors[0] = 2;
	}
	if (n == 1)
		return (prime_factors);
	if (is_prime(n))
	{
		prime_factors[0] = n;
		return (prime_factors);
	}
	a = (long long int) ceil(sqrt(n));
	b = (long long int) floor(sqrt(n));
	while (1)
	{
		c = a * a - b * b;
		if (c == n)
		{
			if (is_prime(a - b))
				prime_factors[0] = a - b;
			else
				prime_factors[0] = find_prime_factors(a - b)[0];
			if (is_prime(a + b))
				prime_factors[1] = a + b;
			else
				prime_factors[1] = find_prime_factors(a + b)[0];
			break;
		}
		else if (c < n)
			a++;
		else
			b--;
	}
	return (prime_factors);
}

/**
 * is_prime - Check if a natural number is prime using the Miller-Rabin
 * primality test.
 * @n: The natural number to be checked.
 * Return: 1 if the number is prime, 0 otherwise.
 */
int is_prime(long long int n)
{
	long long int r, d, a, x, i;

	if (n < 0)
		return (0);
	if (n == 2 || n == 3)
		return (1);
	if (n < 2 || n % 2 == 0)
		return (0);
	r = 0;
	d = n - 1;
	while (d % 2 == 0)
	{
		r++;
		d = d / 2;
	}
	srand(time(NULL));
	a = rand() % (n - 3) + 2;
	x = modular_pow(a, d, n);
	if (x == 1 || x == n - 1)
		return (1);
	for (i = 0; i < r - 1; i++)
	{
		x = modular_pow(x, 2, n);
		if (x == 1)
			return (0);
		if (x == n - 1)
			return (1);
	}
	return (0);
}

/**
 * modular_pow - Compute the power of a number modulo another number.
 * @base: The base number.
 * @exponent: The exponent number.
 * @modulus: The modulus number.
 * Return: The result of base^exponent modulo modulus.
 */
long long int modular_pow(long long int base, long long int exponent,
			  long long int modulus)
{
	long long int result = 1;

	base = base % modulus;
	while (exponent > 0)
	{
		if (exponent % 2 == 1)
			result = (result * base) % modulus;
		exponent = exponent / 2;
		base = (base * base) % modulus;
	}
	return (result);
}

/**
 * main - Read a natural number from a file and print its prime factors.
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char **argv)
{
	FILE *f;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	long long int n;
	long long int *prime_factors;

	if (argc != 2)
	{
		printf("Usage: factors <file>\n");
		return (1);
	}
	f = fopen(argv[1], "r");
	if (!f)
	{
		printf("File not found\n");
		return (1);
	}
	read = getline(&line, &len, f);
	if (read == -1)
	{
		printf("File is empty\n");
		return (1);
	}
	n = atoll(line);
	if (n == 0)
	{
		printf("0 cannot be factorized\n");
		return (1);
	}
	if (n < 0)
	{
		printf("%lld is not a natural number\n", n);
		return (1);
	}
	prime_factors = find_prime_factors(n);
	if (!prime_factors)
	{
		printf("Memory allocation error\n");
		return (1);
	}
	printf("%lld = %lld * %lld\n", n, prime_factors[0], prime_factors[1]);
	free(prime_factors);
	fclose(f);
	return (0);
}
