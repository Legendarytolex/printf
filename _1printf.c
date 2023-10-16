#include "main.h"

/**
 * _printf - A function that produces output according to a format
 * @format: the format identifier
 * Return:the number of characters
 */
int _printf(const char *format, ...)
{
	int character, count = 0;
	const char *string;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			count++;
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				character = va_arg(args, int);
				_putchar(character);
				count++;
			}
			else  if (*format == 's')
			{
				string = va_arg(args, const char *);
				while (*string)
				{
					_putchar(*string);
					count++;
					string++;
				}
			}
			else if (*format == '%')
			{
				_putchar('%');
				count++;
			}
		}
		format++;
	}
	va_end(args);
	return (count);
}
