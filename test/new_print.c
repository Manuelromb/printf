#include "main.h"

int new_printf(const char *format, ...)
{
	int len = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			len = len + 1;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
					buffer = (char)va_arg(args, int);
=======
=======
				{
>>>>>>> c3dd57c (one more)
>>>>>>> 7575e9f (one more)
					char c = (char)va_arg(args, int);

					_putchar(c);
					len = len + 1;
					break;
				}
				case 's':
				{
					char *buffer = va_arg(args, char *);
					while (*buffer)
					{
						_putchar(*buffer);
						buffer++;
						len = len + 1;
					}
					break;
				}
				case '%':
				{
					_putchar('%');
					len = len + 1;
					break;
				}
				default:
					_putchar('%');
					_putchar(*format);
					len = len + 2;
			}
		}
		format++;
	}
	va_end(args);
	return (len);
}
