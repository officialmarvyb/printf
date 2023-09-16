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

	if (format == NULL)
	return (-1);

	while (*format)
	{
		if (*format != '%')
			_putchar(*format);
			k++;
		else if (*(format + 1) == '%')
			_putchar('%');
			k++;
			format++;
		else if (*(format + 1) == 'c')
		_putchar(va_arg(args, int));
		k++;
		format++;
		}
		else if (*(format + 1) == 's')
		{
			str = va_arg(args, char *);
			if (str == NULL)
				str = "(null)";
			while (*str)
			{
				_putchar(*str);
				k++;
				str++;
			}
			format++;
		}
		format++;
	}

	va_end(args);
	return (k);
}
