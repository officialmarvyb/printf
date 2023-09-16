#include "main.h"

/**
 * print_number - Prints an integer.
 * @n: The integer to be printed.
 * Return: Length of int
 */

int print_number(int n)
{
	unsigned int num = n, len = 0;

	while (num)
	{
		num /= 10;
		len++;
	}
	num = n;
	if (n < 0)
	{
		_putchar('-');
		num = -num;
	}
	if ((num / 10) > 0)
		print_number(num / 10);
	_putchar((num % 10) + '0');
	return (len);
}
