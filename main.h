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
 * struct fmt - A new type describing formatspecifier
 *
 * @fmt: The format.
 * @fun: The function associated.
 */

struct fmt
{
	char fmt;
	int (*fun)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_s - A new type describing a format.
 *
 * @fmt: The format.
 * @fmt_s: Typedef for struct formatspecifier
 */

typedef struct fmt fmt_s;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list args, char buffer[], int flags, int width, int precision, int size);

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
/* Functions to print numbers */
int print_int(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa(va_list args, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);
/* Function to print non printable characters */
int print_non_printable(va_list args, char buffer[],
	int flags, int width, int precision, int size);
/* Funcion to print memory address */
int print_pointer(va_list args, char buffer[],
	int flags, int width, int precision, int size);
/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
/*Function to print string in reverse*/
int print_reverse(va_list args, char buffer[],
	int flags, int width, int precision, int size);
/*Function to print a string in rot 13*/
int print_rot13string(va_list args, char buffer[],
	int flags, int width, int precision, int size);
/* width handler */
int write_character(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int num_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char buffer[], int flags, int width, int prc,
	int length, char padd, char extra_char);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_char, int padd_start);
int write_unsgn(int num_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int type_is_printable(char);
int write_hexa_code(char, char[], int);
int type_is_digit(char);

long int convert_number_size(long int num, int size);
long int convert_unsign_size(unsigned long int num, int size);

#endif
