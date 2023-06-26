#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _print_integer - Prints an integer
 * @num: The integer to print
 *
 * Return: Number of characters printed
 */
int _print_integer(int num)
{
    unsigned int abs_num = (num < 0) ? -num : num;
    int printed_chars = 0;

    if (num < 0)
    {
        _putchar('-');
        printed_chars++;
    }

    if (abs_num / 10)
        printed_chars += _print_integer(abs_num / 10);

    _putchar('0' + abs_num % 10);
    printed_chars++;

    return printed_chars;
}
