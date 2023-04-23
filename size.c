#include "main.h"

/**
 * get_size - Arguments size
 * @format: arguments in a formatted string
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
int curr = *i + 1;
int size = 0;

if (format[curr] == 'l')
size = S_LONG;
else if (format[curr] == 'h')
size = S_SHORT;

if (size == 0)
*i = curr - 1;
else
*i = curr;

return (size);
}
