#include "main.h"

/**
 * print_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int j = BUFF_SIZE - 2;
unsigned long int num1 = va_arg(types, unsigned long int);
num1 = convert_size_unsgnd(num1, size);
if (num1 == 0)
buffer[j--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num1 > 0)
{
buffer[j--] = (num1 % 10) + '0';
num1 /= 10;
}

j++;

return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}

/**
 * print_octal - Unsigned number in octal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{

int j = BUFF_SIZE - 2;
unsigned long int num1 = va_arg(types, unsigned long int);
unsigned long int init_num = num1;

UNUSED(width);
num1 = convert_size_unsgnd(num1, size);
if (num1 == 0)
buffer[j--] = '0';

buffer[BUFF_SIZE - 1] = '\0';
while (num1 > 0)
{
buffer[j--] = (num1 % 8) + '0';
num1 /= 8;
}

if (flags & F_HASH && init_num != 0)
buffer[j--] = '0';

j++;

return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: arguments list
 * @buffer: Print buffer array
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789abcdef", buffer,
flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: arguments list
 * @buffer: Buffer array
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789ABCDEF", buffer,
flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: arguments list
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
int j = BUFF_SIZE - 2;
unsigned long int num1 = va_arg(types, unsigned long int);
unsigned long int init_num = num1;

UNUSED(width);
num1 = convert_size_unsgnd(num1, size);

if (num1 == 0)
buffer[j--] = '0';

buffer[BUFF_SIZE - 1] = '\0';
while (num1 > 0)
{
buffer[j--] = map_to[num1 % 16];
num1 /= 16;
}

if (flags & F_HASH && init_num != 0)
{
buffer[j--] = flag_ch;
buffer[j--] = '0';
}

j++;

return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}
