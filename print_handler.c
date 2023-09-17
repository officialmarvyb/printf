#include "main.h"

/**
 * handle_print - Prints an argument based on its type
 * @formatspeifier: Formatted string in which to print the arguments.
 * @args: List of arguments to be printed.
 * @ind: index.
 * @buffer: The buffer array to handle print.
 * @flags: Calculates active flags
 * @width: Get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *formatspecifier, int *ind, va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, chars = -1;
	fmt_s fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].formatspecifier != '\0'; i++)
		if (formatspecifier[*ind] == fmt_types[i].formatspecifier)
			return (fmt_types[i].fun(list, buffer, flags, width, precision, size));

	if (fmt_types[i].formatspecifier == '\0')
	{
		if (formatspecifier[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (formatspecifier[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (formatspecifier[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (formatspecifier[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &formatspecifier[*ind], 1);
		return (unknow_len);
	}
	return (chars);
}
