#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * handle_unsigned_decimal - Prints the decimal representation of an unsigned integer
 * @num: The unsigned integer to convert and print
 *
 * Return: The number of characters printed
 */

int handle_unsigned_decimal(unsigned int num)
{
	unsigned int abs_num = num;
	int printed_chars = 0;

	if (abs_num / 10)
		printed_chars += handle_unsigned_decimal(abs_num / 10);
	_putchar('0' + abs_num % 10);
	printed_chars++;
	return (printed_chars);
}

/**
 * handle_octal_recursive - Converts an unsigned integer to octal representation recursively
 * @num: The unsigned integer to convert
 *
 * Return: The number of characters printed
 */

int handle_octal_recursive(unsigned int num)
{
	int printed_chars = 0;

	if (num / 8)
		printed_chars += handle_octal_recursive(num / 8);
	_putchar('0' + (num % 8));
	printed_chars++;
	return (printed_chars);
}

/**
 * handle_hexadecimal_recursive - Prints the hexadecimal representation of an unsigned integer (recursive version)
 * @num: The unsigned integer to convert and print
 * @uppercase: Flag indicating whether to use uppercase letters for hexadecimal digits
 *
 * Return: The number of characters printed
 */
int handle_hexadecimal_recursive(unsigned int num, int uppercase)
{
	int remainder;
	char hex_digit;
	int printed_chars;

	if (num == 0)
	return 0;

	remainder = num % 16;
	if (remainder < 10)
	hex_digit = '0' + remainder;
	else
	hex_digit = (uppercase) ? 'A' + remainder - 10 : 'a' + remainder - 10;
	printed_chars = handle_hexadecimal_recursive(num / 16, uppercase);
	_putchar(hex_digit);
	printed_chars++;
	return (printed_chars);
}
