#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024
#define UNUSED(x) (void)(x)

#define FL_MINUS 1
#define FL_PLUS 2
#define FL_ZERO 4
#define FL_HASH 8
#define FL_SPACE 16

/* SIZE */
#define SI_LONG 2
#define SI_SHORT 1

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

/*Specifiers*/
int get_flags(const char *format, int *j);
int get_width(const char *format, int *j, va_list arg);
int get_precision(const char *format, int *j, va_list arg);
int get_size(const char *format, int *j);

/*Funtions to print character, percent sign and string*/
int print_char(va_list arg, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list list, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list type, char buffer[],
	int flags, int width, int precision, int size);
#endif
