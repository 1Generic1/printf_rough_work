#include "main.h"

/**
 * handle_binary - Prints the binary representation of an unsigned integer
 * @n: The unsigned integer to convert and print
 * Return: The number of characters printed
 */
int handle_binary(unsigned int n)
{
    int printed_chars = 0;
    unsigned int bit = 1;
    int i;

    if (n == 0)
    {
        _putchar('0');
        printed_chars++;
        return printed_chars;
    }

 for (i = sizeof(unsigned int) * 8 - 1; i >= 0; i--)
    {
        if ((n >> i) & bit)
            break;
    }
    for (; i >= 0; i--)
    {
        if ((n >> i) & bit)
        {
            _putchar('1');
            printed_chars++;
        }
        else
        {
            _putchar('0');
            printed_chars++;
        }
    }

    return printed_chars;
}
