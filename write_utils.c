#include "main.h"

/**
 * type_is_printable - Evaluates if a character is printable
 * @c: Character to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int type_is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * write_hexa_code - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASCII CODE.
 * Return: Always 3
 */
int write_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * type_is_digit - Check if character is a digit
 * @c: Character to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int type_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_number_size - Casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_number_size(long int num, int size)
{
	if (size == SI_LONG)
		return (num);
	else if (size == SI_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_unsign_size - Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_unsign_size(unsigned long int num, int size)
{
	if (size == SI_LONG)
		return (num);
	else if (size == SI_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
