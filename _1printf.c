#include "main.h"
#include <limits.h>

/**
 * _printf - A function that produces output according to a format
 * @format: the format identifier
 * Return:the number of characters
 */
int _printf(const char *format, ...)
{
	int (*pfunc)(va_list, flags_t *), count = 0;
	const char *s;
	va_list args;
	flags_t flags = {0, 0, 0};

	va_start(args, format);
	if (!format)
		return (-1);
	for (s = format; *s; s++)
	{
		if (*s == '%')
		{
			s++;
			if (*s == '%')
				count += _putchar('%');
			else
			{
				while (get_flag(*s, &flags))
					s++;
				pfunc = get_print(*s);
				if (pfunc)
					count += pfunc(args, &flags);
				else
				{
					count += _putchar('%');
					count += _putchar(*s);
				}
			}
		}
		else
			count += _putchar(*s);
	}
	va_end(args);
	return (count);
}
