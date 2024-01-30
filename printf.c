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
				if (temp2 == NULL)
					temp2 = "(nil)";
				count = _strlen(temp2);
				write(1, temp2, count);
				i++;
				length += count - 2;
			}
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
            		{
                		temp = va_arg(args, int);
                		length += print_number(temp);
                		i++;
            		}
			else
				write(1, (format + i), 1);
		else
			write(1, (format + i), 1);
		length++;
	}
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

    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
        length++;
    }

    if (n == 0)
    {
        write(1, "0", 1);
        return 1;
    }

    if (n / 10)
        length += print_number(n / 10);

    char digit = (char)(n % 10 + '0');
    write(1, &digit, 1);

    return length + 1;
}
