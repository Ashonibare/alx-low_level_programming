#include <stdio.h>
/**
 * main - alphabet in lowercase, and then uppercase.
 *
 * Return: returns zero at the end
 *
 **/
int main(void)
{
	char ch;

	for (ch = 'a'; ch <= 'z'; ch++)
	{
		putchar(ch);
	}
	for (ch = 'A'; ch <= 'Z'; ch++)
	{
		putchar(ch);
	}
	putchar('\n');
	return (0);
}
