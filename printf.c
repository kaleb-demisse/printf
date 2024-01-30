#include "main.h"

/**
 * _printf - does what printf does
 * @format: the string to be printed
 *
 * Return: the number of characters printed
*/

int _printf(const char *format, ...)
{
	int length = 0;
	va_list args;
	int i = 0;
	char temp;
	int count;
	char *temp2;

	va_start(args, format);
	for (; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				write(1, (format + i), 1);
				i++;
			}
			else if (format[i + 1] == 'c')
			{
				temp = (char)(va_arg(args, int));
				write(1, &temp, 1);
				i++;
			}
			else if (format[i + 1] == 's')
			{
				temp2 = va_arg(args, char*);
				count = _strlen(temp2);
				write(1, temp2, count);
				i++;
				length += count - 2;
			}
			else
				write(1, (format + i), 1);
		}
		else
			write(1, (format + i), 1);
		length++;
	}
	va_end(args);
	return (length);
}
