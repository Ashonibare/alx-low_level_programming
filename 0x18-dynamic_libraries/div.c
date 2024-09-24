#include <stdio.h>

/**
 * div: divide 2 ints.
 * @a: first integer
 * @b: second integer
 * Return: outcome of a / b
*/
int div(int a, int b)
{
	if (b == 0)
	{
		return 0;
	}
	return a / b;
}