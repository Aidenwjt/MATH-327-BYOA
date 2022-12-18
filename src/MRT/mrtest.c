#include <stdio.h>
#include <errno.h> // errno
#include <limits.h> // INT_MAX, INT_MIN
#include <stdlib.h> // strtol, srand, rand
#include <time.h> // time

// =================================================================================
// Modular exponentiation function copied from:
// https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/
int power(long long x, unsigned int y, int p)
{
	int res = 1;
	x = x % p;

	if (x == 0) return 0;

	while (y > 0)
	{
		if (y%2 != 0)
			res = (res*x) % p;

		y = y>>1;
		x = (x*x) % p;
	}
	return res;
}
// ============================ end of copied code =================================


// =================================================================================
// Miller-rabin test adapted from Wikipedia pseudo-code:
// https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test
int main(int argc, char *argv[])
{
	/* Some quick error checking */
	if(argc != 2)
	{
		printf("Usage: %s n\nn = number to check primality of.\n", argv[0]);
		return 0;
	}

	char *ptr;
	int n, s, d, x, y, temp, i;

	errno = 0;
	long convert = strtol(argv[1], &ptr, 10);
	if(errno != 0 || *ptr != '\0' || convert > INT_MAX || convert < INT_MIN)
	{
		printf("Bad inputs, please only pass integers greater than %d and less than %d.\n", INT_MIN, INT_MAX);
		printf("Usage: %s n \nn = number to check primality of.\n", argv[0]);
		return 0;
	}
	n = convert;

	/* Making sure our number is in the proper range and not even */
	if(n <= 2 || n >= 2047 || n%2 == 0)
	{
		printf("Please enter an odd integer 2 < n < 2047.\n");
		return 0;
	}

	/* First need to find values s > 0 and odd d > 0 such that n - 1 = 2^s * d */
	s = 1;
	d = 0;
	while(1)
	{
		int twos = 2;
		for(i = 0; i < s-1; ++i) twos *= 2;

		for(i = 0; i < n-1; ++i)
		{
			if( (twos * i == n-1) && (i % 2 != 0) )
			{
				temp = i;
				d = temp;
				break;
			}
		}

		if(d != 0) break;
		s++;
	}

	/* Primality test 2 < n < 2047 and witness prime a = 2 */
	x = power(2,d,n);
	for(i = 0; i < s; ++i)
	{
		y = (x * x)%n;
		if( (y == 1) && (x != 1) && (x != n-1) )
		{
			printf("%d is definitely composite.\n", n);
			return 0;
		}
		x = y;
	}
	if(y != 1)
	{
		printf("%d is definitely composite.\n", n);
		return 0;
	}
	printf("%d is prime, and tested again witness prime 2.\n", n);

	return 0;
}
// ============================ end of adapted code ================================
