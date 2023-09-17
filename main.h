#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024

/**
 * struct formatspecifier - A new type describing formatspecifier
 *
 * @formatspecifier: The format.
 * @fun: The function associated.
 */

struct formatspecifier
{
	char formatspecifier;
	int (*fun)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct formatspecifier fmt_s - A new type describing a format.
 *
 * @formatspecifier: The format.
 * @fmt_s: Typedef for struct formatspecifier
 */

typedef struct formatspecifier fmt_s;

int _printf(const char *format, ...);
int handle_print(const char *formatspecifier, int *j,
va_list list, char buffer[], int flags, int width, int precision, int size);

#endif
