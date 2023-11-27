#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/**
 * find_factors - returns a list of factors of a natural number
 * using Fermat's factorization method
 * @n: the natural number to be factorized
 * Return: a pointer to an array of size 2 that contains the factors
 */
long long int *find_factors(long long int n)
{
	long long int *factors = malloc(2 * sizeof(long long int));

	if (n % 2 == 0)
	{
		n = n / 2;
		factors[0] = 2;
	}
	while (n % 2 == 0)
	{
		n = n / 2;
		factors[0] = 2;
	}
	if (n == 1)
	{
		return (factors);
	}
	if (is_prime(n))
	{
		factors[0] = n;
		return (factors);
	}
	long long int a = (long long int)ceil(sqrt(n));
	long long int b = (long long int)floor(sqrt(n));

	while (1)
	{
		long long int c = a * a - b * b;

		if (c == n)
		{
			factors[0] = a - b;
			factors[1] = a + b;
			break;
		}
		else if (c < n)
		{
			a++;
		}
		else
		{
			b--;
		}
	}
	return (factors);
}

/**
 * is_prime - checks if a natural number is prime
 * using the Miller-Rabin primality test
 * @n: the natural number to be checked
 * Return: 1 if the number is prime, 0 otherwise
 */
int is_prime(long long int n)
{
	if (n == 2 || n == 3)
	{
		return (1);
	}
	if (n < 2 || n % 2 == 0)
	{
		return (0);
	}
	long long int r = 0;
	long long int d = n - 1;

	while (d % 2 == 0)
	{
		r++;
		d = d / 2;
	}
	srand(time(NULL));
	long long int a = rand() % (n - 3) + 2;

	/* Compute a^d modulo n */
	long long int x = modular_pow(a, d, n);

	if (x == 1 || x == n - 1)
	{
		return (1);
	}
	for (long long int i = 0; i < r - 1; i++)
	{
		x = modular_pow(x, 2, n);
		if (x == 1)
		{
			return (0);
		}
		if (x == n - 1)
		{
			return (1);
		}
	}
	/* Return 0 */
	return (0);
}
