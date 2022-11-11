// gcc -o dps_solver dps_solver.c -lm

#include <stdio.h>
#include <errno.h>  // errno
#include <limits.h> // INT_MAX, INT_MIN
#include <stdlib.h> // strtol
#include <math.h>   // pow

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Usage: %s k n\n(Sum of the kth powers of the positive divisors of n)\n", argv[0]);
		return 0;
	}

	char *ptr1, *ptr2;
	int k, n, i, j, l;

	errno = 0;
	long convert1 = strtol(argv[1], &ptr1, 10);
	long convert2 = strtol(argv[2], &ptr2, 10);

	if(errno != 0 || *ptr1 != '\0' || *ptr2 != '\0' || convert1 > INT_MAX || convert1 < INT_MIN || convert2 > INT_MAX || convert2 < INT_MIN)
	{
		printf("Usage: %s k n\n(Sum of the kth powers of the positive divisors of n)\n", argv[0]);
		return 0;
	}

	k = convert1;
	n = convert2;

	long long sum = 0;

	// Find the divisors (exhaustive search for now, can be improved with prime factorization)
	for(i = 1; i < n+1; ++i)
	{
		if(n%i == 0)
		{
			l = (int)pow((double)i, (double)k);
			sum += l;
		}
	}

	printf("The sum of the %dth powers of the positive divisors of %d is: %lld\n", k, n, sum);
}
