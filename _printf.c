#include "main.h"

void print_buffer(char buffer[], int *buffer_index);

/**
 * _printf - produce output according to a format.
 * @format: A character string containing format specifiers.
 *
 * Return: The number of characters printed (excluding the null byte).
 */

int _printf(const char *format, ...)
{
	int j, c = 0, chars = 0;
	int flags, width, precision, size, buffer_index = 0;
	va_list arg;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(arg, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[buffer_index++] = format[j];
			if (buffer_index == BUFFER_SIZE)
				print_buffer(buffer, &buffer_index);
			chars++;
		}
		else
		{
			print_buffer(buffer, &buffer_index);
			flags = get_flags(format, &j);
			width = get_width(format, &j, arg);
			precision = get_precision(format, &j, arg);
			size = get_size(format, &j);
			++j;
			c = handle_print(format, &j, arg, buffer,
					flags, width, precision, size);
			if (c == -1)
				return (-1);
			chars += c;
		}
	}
	print_buffer(buffer, &buffer_index);
	va_end(arg);
	return (chars);
}

/**
 * print_buffer - Prints the contents of the buffer if encountered
 * @buffer: Array of characters
 * @buffer_index: Index to add next character
 */

void print_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);
	*buffer_index = 0;
}
