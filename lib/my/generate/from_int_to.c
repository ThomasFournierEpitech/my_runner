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

void print_memory_address(va_list list)
{
	long long unsigned int nb = va_arg(list, long long unsigned int);

	my_putstr("0x");
	my_putnbr_base(nb, "0123456789abcdef");
}
