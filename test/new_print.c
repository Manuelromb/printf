#include "main.h"

/**
 * print_char - print character
 *
 * @c: char to print
 *
 * Return: nothing
 */

int print_char(char c)
{

	int count = 0;

	_putchar(c);

	count++;
	return (count);

}

/**
 * print_int - prints integers
 *
 * @num: number to print
 * Return: 0
 */

int print_int(int num)
{
	int i, index, count = 0;
	char buffer[12];

	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}
	if (num == 0)
	{
		_putchar('0');
	}

	index = 0;
	while (num > 0)
	{
		buffer[index] = '0' + (num % 10);
		num = num / 10;
		index++;
	}
	for (i = index - 1; i >= 0; i--)
	{
		_putchar(buffer[i]);
	}

	count++;
	return (count);
}

/**
 * print_str - prints string
 * @s: pointer to string
 *
 * Return: returns string value
 */
int print_str(char *s)
{
	int i = 0;

	while (*s)
	{
		_putchar(*s);
		s++;
		i++;
	}
	return (i);
}

/**
 *new_printf - prints anything.
 *@format: the format string.
 *
 *Return: the number of characters printed
 */
int new_printf(const char *format, ...)
{
	int len = 0;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			print_char(*format);
			len = len + 1;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
					print_char((char)va_arg(args, int));
					len = len + 1;
					break;
				case 's':
					len += print_str(va_arg(args, char *));
					break;
				case '%':
					len += print_char('%');
					break;
				case 'i':
				case 'd':
					len += print_int(va_arg(args, int));
					break;
				default:
					print_char('%');
					print_char(*format);
					len = len + 2;
			}
		}
		format++;
	}
	va_end(args);
	return (len);
}
