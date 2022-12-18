// gcc -o lde_solver lde_solver.c

#include <stdio.h>
#include <errno.h>  // errno
#include <limits.h> // INT_MAX, INT_MIN
#include <stdlib.h> // strtol

int main(int argc, char *argv[])
{
	/* Some quick error checking */
	if(argc != 4)
	{
		printf("Usage: %s a b c\n(ax + by = c)\n", argv[0]);
		return 0;
	}

	char *ptr1, *ptr2, *ptr3;
	int a, b, c;
	int i, j, k, l, q, r, prev_r, temp_l, temp_j, a1, b1, mult;
	int temp_a, temp_b;
	int negative_flag;

	errno = 0;
	long convert1 = strtol(argv[1], &ptr1, 10);
	long convert2 = strtol(argv[2], &ptr2, 10);
	long convert3 = strtol(argv[3], &ptr3, 10);

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
	
	a = convert1;
	b = convert2;
	c = convert3;

	/* Setting values for EEA */
	i = j = 1;
	a1 = a;
	b1 = b;
	k = l = temp_l = temp_j = r = prev_r = q = 0;

	/* EEA loop */
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

	/* Swap signs if gcd is negative */
	negative_flag = 0;
	if(prev_r < 0)
	{
		prev_r *= -1;
		negative_flag = 1;
	}
	
	/* If GCD(a,b) != 1 then need to check if c is a multiple of the GCD(a,b) */
	mult = c;
	if(prev_r > 1)
	{
		if(mult%prev_r != 0)
		{
			printf("%dx + %dy = %d has no integer solutions.\n\n", a, b, c);
			return 0;
		}
		mult /= prev_r;
	}

	/* When absolute value of a and b are equal */
	if(prev_r == 0)
	{
		prev_r = a;
		if(mult%prev_r != 0)
		{
			printf("%dx + %dy = %d has no integer solutions.\n\n", a, b, c);
			return 0;
		}
		mult /= prev_r;
		l = 1;
		j = 0;
	}

	/* Base solutions to LDE */
	int x_0 = l*mult;
	int y_0 = j*mult;

	/* Make sure we are using proper signs */
	if(a*x_0 + b*y_0 != c)
	{
		if(a*(-1*x_0) + b*y_0 == c) x_0 *= -1;
		if(a*x_0 + b*(-1*y_0) == c) y_0 *= -1;
		if(a*(-1*x_0) + b*(-1*y_0) == c) 
		{
			x_0 *= -1;
			y_0 *= -1;
		}
	}
	if(negative_flag) prev_r *= -1;

	/* Print results */
	printf("Base solution for %dx + %dy = %d:\n\n%d(%d) + %d(%d) = %d.\n", a, b, c, a, x_0, b, y_0, c);
	printf("\nGeneral solution for %dx + %dy = %d:\n\nx = %d + (%d)n, and y = %d - (%d)n,\n\n%d(%d + (%d)n) + %d(%d - (%d)n) = %d, for all integers n.\n\n",
		       	a, b, c, x_0, (b/prev_r), y_0, (a/prev_r), a, x_0, (b/prev_r), b, y_0, (a/prev_r), c);
	
	return 0;
}
