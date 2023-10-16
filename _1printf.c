#include "main.h"

/**
 * _printf - A function that produces output according to a format
 * @format: the format identifier
 * Return:the number of characters
 */
int _printf(const char *format, ...)
{
	int count = 0;
	char c, specifier;
	const char *string;
	va_list args;

	va_start(args, format);
	while ((c = *format++))
	{
		if (c != '%')
			_putchar(c);
			count++;
		else
		{
			specifier = *format++;
			if (specifier == 'c')
				count += _putchar(va_arg(args, int));
			else  if (specifier == 's')
			{
				string = va_arg(args, char*);
				if (string)
				{

					while (*string)
						_putchar(*string++);
						count++;
				}
				else
					count += _putchar("(null)");
				else if (specifier == '%')
					count += _putchar('%');
				else
					count += putchar('%') + _putchar(specifier);
			}
		}
	}
	va_end(args);
	return (count);
}
