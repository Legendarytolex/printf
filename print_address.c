#include "main.h"

/**
 * print_address - prints the address in hexadecimal format
 * @l: va_list arg
 * @f: pointer to the struct flag
 *
 * Return: number of characters printed
 */
int print_address(va_list l, flags_t *f)
{
	unsigned long int p = va_arg(1, unsigned long int);
	char *str;
	int count;

	if (!p)
	{
		return (_puts("(nil)"));
	}

	str = conv(p, 16, 1);
	count = _puts("Ox") + _puts(str);

	return (count);
}
