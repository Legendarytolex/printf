#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct flags - struct containing flags
 * @add: flag for +
 * @space: flag for ' '
 * @hash: flag for '#'
 */
typedef struct flags
{
	int add;
	int space;
	int hash;
} flags_t;

/**
 * struct print_handler - struct to choose function
 * @s: format specifier
 * @f: pointer to the printed function
 */
typedef struct print_handler
{
	char s;
	int (*f)(va_list ap, flags_t *f);
} ph;

/*prototypes to print bases*/
int print_base(va_list l, flags_t *f, int base, int uppercase);
int print_hexa(va_list l, flags_t *f);
int print_hexa_big(va_list l, flags_t *f);
int print_bin(va_list l, flags_t *f);
int print_octa(va_list l, flags_t *f);

/*prototypes to print numbers*/
int print_integer(va_list l, flags_t *f);
void print_num(int a);
int print_unsigned_int(va_list l, flags_t *f);
int count_digit(int j);

/* prototype for base converter */
char *conv(unsigned long int numb, int base, int lowercase);

int _printf(const char *format, ...);
int (*get_print(char s))(va_list, flags_t *);
int get_flag(char s, flags_t *f);

/* prototypes for alphabets */
int print_str(va_list l, flags_t *f);
int print_character(va_list l, flags_t *f);

/*prototypes for write function */
int _putchar(char c);
int _puts(char *str);

/* prototype for print custom values */
int print_rot13(va_list l, flags_t *f);
int print_rev(va_list l, flags_t *f);
int print_big_string(va_list l, flags_t *f);

/* prototypes for address and percent*/
int print_address(va_list l, flags_t *f);
int print_percent(va_list l, flags_t *f);

#endif
