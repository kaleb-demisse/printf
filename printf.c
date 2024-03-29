#include "main.h"

/**
 * _printf - does what printf does
 * @format: the string to be printed
 *
 * Return: the number of characters printed
*/

int _printf(const char *format, ...)
{
	int length = 0, count, i = 0;
	va_list args;
	char temp, *temp2;

	if (format == NULL || (format[0] == '%' && format[1] == '\0') ||
	   (format[0] == ' ' && format[1] == '%' && format[2] == '\0'))
		return (-1);
	va_start(args, format);
	for (; format[i] != '\0'; i++, length++)
		if (format[i] == '%')
			switch (format[i + 1])
			{
				case '%':
					write(1, (format + i), 1);
					i++;
					break;
				case 'c':
					temp = (char)(va_arg(args, int));
					write(1, &temp, 1);
					i++;
					break;
				case 's':
					temp2 = va_arg(args, char*);
					count = _strlen(temp2);
					write(1, temp2, count);
					i++;
					length += count - 2;
					break;
				case 'd':
				case 'i':
					length += print_number(va_arg(args, int)) - 1;
					i++;
					break;
				default:
					write(1, (format + i), 1);
			}
		else
			write(1, (format + i), 1);
	va_end(args);
	return (length);
}

/**
 * print_number - prints an integer and returns its length
 * @n: the integer to be printed
 *
 * Return: the number of digits in the integer
 */

int print_number(int n)
{
	int length = 0;
	unsigned int x;
	char y;

	x = n;
	if (n < 0)
	{
		write(1, "-", 1);
		x = -n;
		length++;
	}
	if (n / 10)
		length += print_number(x / 10);

	y = x % 10 + '0';

	write(1, &y, 1);

	return (length + 1);
}
