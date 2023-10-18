#include "main.h"

/**
 * print_big_string - non printable char
 * @l: va_list argument
 * @f: pointer to the struct flag file
 * Return: number of char printed
 */
int print_big_string(va_list l, flags_t *f)
{
	int i;
	int count = 0;
	char *res;
	char *str = va_arg(l, char *);

	(void)f;

	if (!str)
		return (_puts("(null)"));

	for (i = 0; str[i]; i++)
	{
		if (str[i] > 0 && (str[i] < 32 || str[i] >= 127))
		{
			_puts("\\x");
			count += 2;
			res = conv(str[i], 16, 0);
			if (!res[1])
				count += _putchar('0');
			count += _puts(res);
		}
		else
			count += _putchar(str[i]);
	}
	return (count);
}

/**
 * print_rot13 - prints a string using rot13
 * @l: list of arguements
 * @f: pointer to the struct file
 * Return: length of the printed string
 */
int print_rot13(va_list l, flags_t *f)
{
	int i, j;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *s = va_arg(l, char *);

	(void)f;
	for (j = 0; s[j]; j++)
	{
		if (s[j] < 'A' || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z')
			_putchar(s[j]);
		else
		{
			for (i = 0; i <= 52; i++)
			{
				if (s[j] == rot13[i])
					_putchar(ROT13[i]);
			}
		}
	}
	return (j);
}

/**
 * print_percent - prints a percent symbol
 * @l: va_list argument
 * @f: a pointer to the struct flags file
 * Return: number of char printed
 */
int print_percent(va_list l, flags_t *f)
{
	(void)f;
	(void)l;
	return (_putchar('&'));
}

/**
 * print_rev - a function that prints a string in reverse
 * @l: argument from va_list
 * @f: pointer to the struct flag file
 * Return: length of printed string
 */
int print_rev(va_list l, flags_t *f)
{
	int i = 0;
	int j;
	char *str = va_arg(l, char *);

	(void)f;
	if (!str)
		str = "(null)";

	while (str[i])
		i++;

	for (j = i - 1; j >= 0; j--)
		_putchar(str[j]);

	return (i);
}
