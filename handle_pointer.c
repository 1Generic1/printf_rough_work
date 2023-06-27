#include <stdio.h>
#include "main.h"

/**
 * handle_pointer - Handles the 'p' conversion specifier
 * @args: The va_list containing the pointer argument
 * @printed_chars: Pointer to the count of printed characters
 *
 * Description: Prints the memory address in hexadecimal format.
 */
void handle_pointer(va_list args, int *printed_chars)
{
	unsigned long int address;
	void *ptr;
	ptr = va_arg(args, void*);
	_putchar('0');
	_putchar('x');
	*printed_chars += 2;

	if (ptr == NULL)
	{
	_putchar('0');
	*printed_chars += 1;
	}
	else
	{
	address = (unsigned long int)ptr;
	*printed_chars += handle_hexadecimal_recursive(address, 0);
	}
}
