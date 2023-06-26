#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	unsigned int ui;

    len = _printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	_printf("String:[%s]\n", "I am a string !");
	_printf("Negative:[%d]\n", -762534);
	_printf("Length:[%d, %i]\n", len, len);
	_printf("%b\n", 98);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	return (0);
}
