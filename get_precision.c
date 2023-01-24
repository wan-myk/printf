#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
    int curr_i = *i + 1;
    int precision = -1;
    int negative_flag = 0;
    int max_precision = 100;

    if (format[curr_i] != '.')
        return (precision);

    curr_i++;

    if (format[curr_i] == '-') {
        negative_flag = 1;
        curr_i++;
    }

    precision = 0;
    for (; format[curr_i] != '\0'; curr_i++)
    {
        if (!is_digit(format[curr_i])) {
            if (format[curr_i] == '*')
            {
                curr_i++;
                precision = va_arg(list, int);
                if (negative_flag)
                    precision = -precision;
                break;
            }
            else
                break;
        }
        precision *= 10;
        precision += format[curr_i] - '0';
    }

    if (negative_flag)
        precision = -precision;

    if (precision > max_precision)
        precision = max_precision;

    *i = curr_i - 1;
    return (precision);
}
