#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing format specifiers.
 *
 * Return: The number of characters printed (excluding the null byte).
 */

int _printf(const char *format, ...)
{
	va_list args;
	int k = 0;
	char *str;
	/*Initialize the va_list with the variable number of arguments*/
	va_start(args, format);

	while (format && *format)
	{
		if (*format == '%' && format++)
		{
			if (*format == 'c')
				k += _putchar(va_arg(args, int));
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				while (*str)
					k += _putchar(*str++);
			}
			else if (*format == '%')
				k += _putchar('%');
			else
			{
				k += _putchar('%');
				k += _putchar(*format);
			}
		}
		else
			k += _putchar(*format);
		format++;
	}

	va_end(args);
	return (k);
}
