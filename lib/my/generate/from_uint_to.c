/*
** EPITECH PROJECT, 2017
** rush1
** File description:
** 
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"
#include <unistd.h>

void from_uint_to_uoct(va_list list)
{
	long long nb = va_arg(list, long long int);

	if (nb >= 0)
		my_putnbr_base(nb, "01234567");
	else
		my_putnbr_base(4294967296 + nb, "01234567");
}
void from_uint_to_udec(va_list list)
{
	long long nb = va_arg(list, long long int);

	if (nb >= 0)
		my_putnbr_base(nb, "0123456789");
	else
		my_putnbr_base(4294967296 + nb, "0123456789");
}
void from_uint_to_uhexa(va_list list)
{
	long long nb = va_arg(list, long long int);

	if (nb >= 0)
		my_putnbr_base(nb, "0123456789abcdef");
	else
		my_putnbr_base(4294967296 + nb, "0123456789abcdef");
}
void from_uint_to_uhexA(va_list list)
{
	long long nb = va_arg(list, long long int);

	if (nb >= 0)
		my_putnbr_base(nb, "0123456789ABCDEF");
	else
		my_putnbr_base(4294967296 + nb, "0123456789ABCDEF");
}
void from_uint_to_ubin(va_list list)
{
	long long nb = va_arg(list, long long int);

	if (nb >= 0)
		my_putnbr_base(nb, "01");
	else
		my_putnbr_base(4294967296 + nb, "01");
}
