#include <stdio.h>
#include "main.h"

/**
 * print_non_printable_char - Prints a non-printable character in a special format
 * @c: The character to print
 * @printed_chars: Pointer to the count of printed characters
 *
 * Description: Prints non-printable characters as \x followed by the ASCII code
 *              value in uppercase hexadecimal format.
 */
void print_non_printable_char(char c, int *printed_chars)
{
	if (c < 32 || c >= 127)
	{
		_putchar('\\');
		_putchar('x');
		_putchar((c / 16) < 10 ? (c / 16) + '0' : (c / 16) - 10 + 'A');
		_putchar((c % 16) < 10 ? (c % 16) + '0' : (c % 16) - 10 + 'A');
		*printed_chars += 4;
	}
	else
	{
		_putchar(c);
		(*printed_chars)++;
	}
}
/**
 * handle_S - Handles the 'S' conversion specifier
 * @args: The va_list containing the arguments
 * @printed_chars: Pointer to the count of printed characters
 *
 * Description: Prints a string with special treatment for non-printable characters.
 */
void handle_S(va_list args, int *printed_chars)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		print_non_printable_char(*str, printed_chars);
		str++;
	}
}
