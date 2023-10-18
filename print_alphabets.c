#include "main.h"

/**
 * print_character - prints a character
 * @l: va_list args
 * @f: pointer to the struct flags
 *
 * Return: Number of character printed
 */
int print_character(va_list l, flags_t *f)
{
	(void)f;

	_putchar(va_arg(l, int));

	return (1);
}

/**
 * print_str - a function that prints every char in a string
 * @l: va_list argument
 * @f: a pointer to the struct flags
 *
 * Return: number of character printed
 */
int print_str(va_list l, flags_t *f)
{
	char *s = va_arg(l, char *);

	(void)f;

	if (!s)
		s = "(null)";

	return (_puts(s));
}
