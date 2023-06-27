#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

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
	char buffer[BUFFER_SIZE];
	int buffer_index = 0;
	int field_width = 0;

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
			if (*format >= '0' && *format <= '9')
			{
				field_width = 0;
				while (*format >= '0' && *format <= '9')
				{
					field_width = (field_width * 10) + (*format - '0');
					format++;
				}
			}
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
					printed_chars += handle_flags_integer(va_arg(args, int), format[i - 1], format[i]);
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
				case 'S':
					handle_S(args, &printed_chars);
					break;
				case 'p':
					handle_pointer(args, &printed_chars);
					break;
				default:
					/*_putchar('%');
					_putchar(*format);
					printed_chars += 2;*/
					break;
			}
		}
		format++;
		if(buffer_index >= BUFFER_SIZE - 1)
		{
			write(1, buffer, buffer_index);
			buffer_index = 0;
		}
		if(buffer_index > 0)
		{
			write(1, buffer, buffer_index);
		}

	}
	va_end(args);
	return (printed_chars);
}

