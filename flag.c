#include "main.h"

/**
 * get_flag - function to turn on flags when _printf finds a flag modifier
 * @s: holds the flag specifier
 * @f: pointer to the struct which turns n the flags
 *
 * Return: 1 if flag is on else 0
 */
int get_flag(char s, flags_t *f)
{
	int i = 0;

	if (s == '+')
	{
		f->add = 1;
		i = 1;
	}
	else if (s == ' ')
	{
		f->space = 1;
		i = 1;
	}
	else if (s == '#')
	{
		f->hash = 1;
		i = 1;
	}

	return (i);
}
