#include "main.h"

/**
 * print_char - Prints a char
 * @types: arguments list
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char args = va_arg(types, int);
return (handle_write_char(args, buffer, flags, width, precision, size));
}
/**
 * print_string - Prints a string
 * @types: arguments list
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int len = 0, i;
char *str = va_arg(types, char *);

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (str == NULL)
{
str = "(null)";
if (precision >= 6)
str = "      ";
}
while (str[len] != '\0')
len++;
if (precision >= 0 && precision < len)
len = precision;
if (width > len)
{
if (flags & F_MINUS)
{
write(1, &str[0], len);
for (i = width - len; i > 0; i--)
write(1, " ", 1);
return (width);
}
else
{
for (i = width - len; i > 0; i--)
write(1, " ", 1);
write(1, &str[0], len);
return (width);
}
}
return (write(1, str, len));
}
/**
 * print_percent - Prints a percent sign
 * @types: arguments list
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size)
{

UNUSED(types);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
return (write(1, "%%", 1));
}

/**
 * print_int - Print int
 * @types: arguments list
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
int is_neg = 0;
long int n = va_arg(types, long int);
unsigned long int num;
n = convert_size_number(n, size);

if (n == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
num = (unsigned long int)n;

if (n < 0)
{
num = (unsigned long int)((-1) * n);
is_neg = 1;
}
while (num > 0)
{
buffer[i--] = (num % 10) + '0';
num /= 10;
}

i++;

return (write_number(is_neg, i, buffer, flags, width, precision, size));
}

/**
 * print_binary - Prints an unsigned number
 * @types: arguments list
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
unsigned int n, j, i, add;
unsigned int a[32];
int count;

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

n = va_arg(types, unsigned int);
j = 2147483648;
a[0] = n / j;
for (i = 1; i < 32; i++)
{
j /= 2;
a[i] = (n / j) % 2;
}
for (i = 0, add = 0, count = 0; i < 32; i++)
{
add += a[i];
if (add || i == 31)
{
char z = '0' + a[i];
write(1, &z, 1);
count++;
}
}
return (count);
}
