#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _print_integer(int num);
int handle_binary(unsigned int n);
int handle_unsigned_decimal(unsigned int num);
int handle_octal_recursive(unsigned int num);
int handle_hexadecimal_recursive(unsigned int num, int uppercase);

#endif /* MAIN_H */

