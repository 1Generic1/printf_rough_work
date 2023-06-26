#include "main.h"
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;
	char c;
	char *str;
	unsigned int b;
	unsigned u;
	unsigned o;
	unsigned x;
	int uppercase;
	int i = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			printed_chars++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = va_arg(args, int);
					_putchar(c);
					printed_chars++;
					break;
				case 's':
					str = va_arg(args, char *);
					if (str == NULL)
						str = "(null)";
					while (*str)
					{
						_putchar(*str);
						printed_chars++;
						str++;
					}
					break;
				case '%':
					_putchar('%');
					printed_chars++;
					break;
				case 'd':
				case 'i':
					printed_chars += _print_integer(va_arg(args, int));
					break;
				case 'b':
					{
						b = va_arg(args, unsigned int);
						printed_chars += handle_binary(b);
					}
					break;
				case 'u':
					{
						u = va_arg(args, unsigned int);
						printed_chars += handle_unsigned_decimal(u);
					}
					break;
				case 'o':
					{
						o = va_arg(args, unsigned int);
						printed_chars += handle_octal_recursive(o);
					}
					break;
				case 'x':
				case 'X':
					{
						x = va_arg(args, unsigned int);
						uppercase = (format[i] == 'X') ? 1 : 0;
						printed_chars += handle_hexadecimal_recursive(x, uppercase);
					}
					break;
				default:
					/*_putchar('%');
					_putchar(*format);
					printed_chars += 2;*/
					break;
			}
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}

