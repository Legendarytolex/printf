#include "main.h"

/**
 * print_base - prints a number in the speccified base
 * @l: va_list argument
 * @f: pointer to the struct file
 * @base: the base of the number
 * @uppercase: flag for uppercase
 *
 * Return: the number of character printed
 */
int print_base(va_list l, flags_t *f, int base, int uppercase)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = conv(num, base, uppercase);
	int count = 0;

	if (f->hash == 1 && str[0] != '0')
	{
		if (base == 16)
			count += _puts(uppercase ? "OX" : "Ox");
		else if (base == 8)
			count += _putchar('0');
	}

	count += _puts(str);
	return (count);
}

/**
 * print_hexa - prints a number in hexadecimal, in lowercase
 * @l: va_list arg
 * @f: pointer to the flags struct file
 *
 * Return: the number of character printed
 */
int print_hexa(va_list l, flags_t *f)
{
	return (print_base(l, f, 16, 1));
}

/**
 * print_hexa_big - prints a number in hexadecimal, in uppercase
 * @l: va_list argument
 * @f: pointer to the flags struct file
 * Return: the number of character printed
 */
int print_hexa_big(va_list l, flags_t *f)
{
	return (print_base(l, f, 16, 0));
}

/**
 * print_bin - prints in base two
 * @l: va_list argument
 * @f: pointer to the flags struct file
 * Return: the number of characters passed
 */
int print_bin(va_list l, flags_t *f)
{
	return (print_base(l, f, 2, 0));
}

/**
 * print_octa - prints in base 8
 * @l: va_list argument
 * @f: a pointer to the flags struct file
 * Return: the number of character
 */
int print_octa(va_list l, flags_t *f)
{
	return (print_base(l, f, 8, 0));
}
