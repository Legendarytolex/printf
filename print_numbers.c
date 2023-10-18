#include "main.h"

/**
 * print_integer - prints an integer
 * @l: va_list argument
 * @f: a pointer to the flags struct file
 * Return: number of int printed
 */
int print_integer(va_list l, flags_t *f)
{
	int num = va_arg(l, int);
	int printed_chars = count_digit(num);

	if (f->space && !f->add && num >= 0)
	{
		printed_chars += _putchar(' ');
	}
	if (f->add && num >= 0)
	{
		printed_chars += _putchar('+');
	}
	if (num <= 0)
	{
		printed_chars++;
	}
	print_num(num);
	return (printed_chars);
}

/**
 * print_num - function that loops through an integer and prints all its digits
 * @a: integer to be printed
 * Return: nothing
 */
void print_num(int a)
{
	unsigned int num_abs;

	if (a < 0)
	{
		_putchar('-');
		num_abs = -a;
	}
	else
		num_abs = a;

	if (num_abs / 10)
	{
		print_num(num_abs / 10);
	}
	_putchar((num_abs % 10) + '0');
}

/**
 * count_digit - returns the number of digits in an integer
 * @j: the integer
 * Return: number of digits
 */
int count_digit(int j)
{
	unsigned int u = (j < 0) ? -j : j;
	int d = 0;

	while (u != 0)
	{
		u /= 10;
		d++;
	}
	return (d);
}

/**
 * print_unsigned_int - prints an unsigned integer
 * @l: va_list argument
 * @f: pointer to the flags struct
 * Return: number of character printed
 */
int print_unsigned_int(va_list l, flags_t *f)
{
	unsigned int u = va_arg(l, unsigned int);
	char *str = conv(u, 10, 0);

	(void)f;
	return (_puts(str));
}
