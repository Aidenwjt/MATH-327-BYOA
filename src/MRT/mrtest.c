#include <stdio.h>
#include <errno.h> // errno
#include <limits.h> // INT_MAX, INT_MIN
#include <stdlib.h> // strtol, srand, rand
#include <time.h> // time

/* Iterative Function to calculate (x^y)%p in O(log y) */
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

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Usage: %s n k\nn = number to check primality of, and k is the desired accuracy of the check.\n", argv[0]);
		return 0;
	}

	char *ptr1, *ptr2;
	int n, k, s, d, x, y, a, i, j, l;
	long long int temp;

	errno = 0;
	long convert1 = strtol(argv[1], &ptr1, 10);
	long convert2 = strtol(argv[2], &ptr2, 10);
	if(errno != 0 || 
	  *ptr1 != '\0' || *ptr2 != '\0' || 
          convert1 > INT_MAX || convert1 < INT_MIN || convert2 > INT_MAX || convert2 < INT_MIN)
	{
		printf("Bad inputs, please only pass integers greater than %d and less than %d.\n", INT_MIN, INT_MAX);
		printf("Usage: %s n k\nn = number to check primality of, and k is the desired accuracy of the check.\n", argv[0]);
		return 0;
	}
	n = convert1;
	k = convert2;
	if(n <= 3 || n >= 2047 || n%2 == 0 || k < 1)
	{
		printf("Please enter an odd integer 3 < n < 2047 and k > 1.\n");
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
	//printf("s = %d d = %d\n",s,d);

	time_t t;
	srand((unsigned) time(&t));

	a = 2;
	/* Primality test n < 2047 and a = 2 */
	for(i = 0; i < k; ++i)
	{
		//a = rand() % ( (n - 2) + 1 - 2) + 2;
		//temp = a;
		//printf("round i = %d a = %d ", i, a);
		//for(j = 0; j < d-1; ++j) temp *= a;
		//x = temp%n;
		x = power(a,d,n);
		//printf("temp = %lld x = %d ", temp, x);
		for(l = 0; l < s; ++l)
		{
			y = (x * x)%n;
			//printf("y = %d\n",y);
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
	}
	printf("%d is probably prime and tested with %d trials.\n", n, k);

	return 0;
}
