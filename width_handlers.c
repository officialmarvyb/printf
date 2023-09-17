#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * write_character - Prints a string
 * @c: character types.
 * @buffer: The buffer array to handle print
 * @flags: Calculates active flags.
 * @width: Get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters printed.
 */
int write_character(char c, char buffer[],
	int flags, int width, int precision, int size)
{ /* char is stored at left and paddind at buffer's right */
	int j = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & FL_ZERO)
		padd = '0';

	buffer[j++] = c;
	buffer[j] = '\0';

	if (width > 1)
	{
		buffer[BUFFER_SIZE - 1] = '\0';
		for (j = 0; j < width - 1; j++)
			buffer[BUFFER_SIZE - j - 2] = padd;

		if (flags & FL_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFFER_SIZE - j - 1], width - 1));
		else
			return (write(1, &buffer[BUFFER_SIZE - j - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * write_number - Prints a string
 * @num_negative: List of arguments
 * @ind: character types.
 * @buffer: The buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters printed.
 */
int write_number(int num_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFFER_SIZE - ind - 1;
	char padd = ' ', extra_char = 0;

	UNUSED(size);

	if ((flags & FL_ZERO) && !(flags & FL_MINUS))
		padd = '0';
	if (num_negative)
		extra_char = '-';
	else if (flags & FL_PLUS)
		extra_char = '+';
	else if (flags & FL_SPACE)
		extra_char = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		length, padd, extra_char));
}

/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: The buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width.
 * @precision: precision specifier
 * @length: Length of number
 * @padd: Padding of characters
 * @extra_c: Extra characters
 *
 * Return: Number of characters printed.
 */

int write_num(int ind, char buffer[],
	int flags, int width, int precision,
	int length, char padd, char extra_char)
{
	int i, padd_start = 1;

	if (precision == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (precision == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (precision > 0 && precision < length)
		padd = ' ';
	while (precision > length)
		buffer[--ind] = '0', length++;
	if (extra_char != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & FL_MINUS && padd == ' ')
		{
			if (extra_char)
				buffer[--ind] = extra_char;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & FL_MINUS) && padd == ' ')
		{
			if (extra_char)
				buffer[--ind] = extra_char;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & FL_MINUS) && padd == '0')
		{
			if (extra_char)
				buffer[--padd_start] = extra_char;
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_char)
		buffer[--ind] = extra_char;
	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - Write a memory address
 * @buffer: Arrays of characters
 * @ind: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Width specifier
 * @flags: Flag specifier
 * @padd: Character representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_char, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & FL_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_char)
				buffer[--ind] = extra_char;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & FL_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_char)
				buffer[--ind] = extra_char;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & FL_MINUS) && padd == '0')
		{
			if (extra_char)
				buffer[--padd_start] = extra_char;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_char)
		buffer[--ind] = extra_char;
	return (write(1, &buffer[ind], BUFFER_SIZE - ind - 1));
}

/**
 * write_unsigned - Writes an unsigned number
 * @num_negative: Number indicating if the number is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of characters
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters printed.
 */
int write_unsigned(int num_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFFER_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(num_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & FL_ZERO) && !(flags & FL_MINUS))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flags & FL_MINUS)
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}
