#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing format specifiers.
 *
 * Return: The number of characters printed (excluding the null byte).
 */

int _printf(const char *format, ...)
{
	va_list args;/*Declare Variable to hold argument*/
	char *str;
	int k = 0;
	/*Initialize the va_list with the variable number of arguments*/
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{ 
				case 'c':/*Character conversion specifier*/
					_putchar(va_arg(args, int));
					k++;
					break;
				case 's':/*String conversion specifier*/
				{
					str = va_arg(args, char *);
					if (str == NULL)
						str = "(null)";
					while (*str)
					{
						_putchar(*str);
						str++;
						k++;
					}
					break;
				}
				case '%':/* % conversion specifier*/
					_putchar('%');
					k++;
					break;
				default:
					_putchar('%');
					_putchar(*format);
					k += 2;
					break;
			}
		}
		else
		{
			_putchar(*format);
			k++;
		}
		format++;
	}

	va_end(args);/* Clean up the va_list*/
	return (k);
}
