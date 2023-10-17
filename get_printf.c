#include "main.h"

/**
 * get_print - it selects the right printf function
 * @s: character that hold the conversion specifier
 *
 * Return: a pointer to the printed function
 */
int (*get_print(char s))(va_list, flag_t *)
{
	int i;

	static ph func_arr[] = {
		{'i', print_integer},
		{'s', print_str},
		{'c', print_character},
		{'d', print_integer},
		{'u', print_unsigned_int},
		{'x', print_hexa},
		{'X', print_hexa_big},
		{'b', print_bin},
		{'o', print_octa},
		{'R', print_rot13},
		{'r', print_rev},
		{'S', print_ big_string},
		{'p', print_address},
		{'%', print_percent}
	};

	for (i = 0; i < sizeof(func_arr) / sizeof(func_arr[0]); i++)
	{
		if (func_arr[i].s == s)
		{
			return (func_arr[i].f);
		}
	}

	return (NULL);
}
