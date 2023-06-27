#include "main.h"

/**
 * handle_flags_integer - Handles flag characters for integer conversion specifiers
 * @num: The integer value to print
 * @flag_plus: Flag indicating whether the '+' flag is present
 * @flag_space: Flag indicating whether the ' ' flag is present
 *
 * Return: The number of characters printed
 */

int handle_flags_integer(int num, int flag_plus, int flag_space)
{
	int printed_chars = 0;

    if (flag_plus && num >= 0)
    {
        _putchar('+');
        printed_chars++;
    }
    else if (flag_space && num >= 0)
    {
        _putchar(' ');
        printed_chars++;
    }

    printed_chars += _print_integer(num);

    return printed_chars;
}
