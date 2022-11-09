// gcc -o lde_solver lde_solver.c

#include <stdio.h>
#include <errno.h>  // errno
#include <limits.h> // INT_MAX, INT_MIN
#include <stdlib.h> // strtol

#define DEBUG 1

int main(int argc, char *argv[])
{
#ifdef DEBUG
	if(argc != 4)
	{
		printf("Usage: %s a b c\n(ax + by = c)\n", argv[0]);
		return 0;
	}

	char *ptr1, *ptr2, *ptr3;
	int a, b, c;

	// set errno
	errno = 0;
	// convert all args to base 10 ints
	long convert1 = strtol(argv[1], &ptr1, 10);
	long convert2 = strtol(argv[2], &ptr2, 10);
	long convert3 = strtol(argv[3], &ptr3, 10);

	// check for bad inputs
	if(errno != 0 ||
	 *ptr1 != '\0' || *ptr2 != '\0' || *ptr3 != '\0' || 
	 convert1 > INT_MAX || convert1 < INT_MIN || 
	 convert2 > INT_MAX || convert2 < INT_MIN || 
	 convert3 > INT_MAX || convert3 < INT_MIN)
	{
		printf("Bad inputs, please only pass integers greater than %d and less than %d.\n", INT_MIN, INT_MAX);
		printf("Usage: %s a b c\n(ax + by = c)\n", argv[0]);
		return 0;
	}
	
	// good inputs
	a = convert1;
	b = convert2;
	c = convert3;

	if(a == b)
	{
		printf("Not allowed yet.\n");
		return 0;
	}
	if(a < b)
	{
		int temp_a = a;
		a = b;
		b = temp_a;
	}

	// use EEA to get base solutions
	int i, j, k, l, q, r, prev_r, temp_l, temp_j, a1, b1; // vars for EEA

	// set values
	i = 1;
	j = 1;
	a1 = a;
	b1 = b;
	k = l = temp_l = temp_j = r = prev_r = q = 0;


	// EEA loop
	while(1)
	{
		prev_r = r;
		r = a1 % b1;
		
		if(r == 0) break;
		
		q = (a1 - r)/b1;
		a1 = b1;
		b1 = r;

		temp_l = l;
		temp_j = j;

		l = i - (q*l);
		j = k - (q*j);

		i = temp_l;
		k = temp_j;
	}

	// if GCD(a,b) != 1 then need to check if c is a multiple of the GCD(a,b)
	int mult = c;
	if(prev_r > 1)
	{
		mult = mult/prev_r;
		if(mult == 0)
		{
			printf("%dx + %dy = %d has no integer solutions.\n", a, b, c);
			return 0;
		}
	}

	int x_0 = l*mult;
	int y_0 = j*mult;

	// print solutions
	printf("Base solution: %d(%d) + %d(%d) = %d.\n", a, x_0, b, y_0, c);
	printf("General solution for %dx + %dy = %d: x = %d + (%d)n, y = %d - (%d)n, for all integers n.\n", a, b, c, x_0, (b/prev_r), y_0, (a/prev_r));
	
#else
#endif
	return 0;
}
