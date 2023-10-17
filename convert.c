#include "main.h"

/**
 * conv -a function that converts number and base into string
 * @numb: input number
 * @base: the base of the input number
 * @lowercase: flag if hexa values need to be in lowercase
 *
 * Return: result string
 */
char *conv(unsigned int numb, int base, int lowercase);
{
	const char *hex_chars = (lowercase) ? "0123456789abcdef" :
		"0123456789ABCDEF";
	static char buffer[50];
	char *ptr = &buffer[49];

	*ptr = '\0';

	do {
		*--ptr = hex_chars[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}
