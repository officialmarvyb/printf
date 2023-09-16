#include "main.h"

/**
 * my_printf - a simplified printf-like function for %d and %i specifiers
 * @format: The format string
 * @...: A variable number of integer arguments
 */
void my_printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	while (*format)
	{

		if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
		{
			int value = va_arg(args, int);

			_printf("%d", value);
			format++;
		}
		else
		{
			_putchar(*format);
		}
		format++;
	}

	va_end(args);
}
