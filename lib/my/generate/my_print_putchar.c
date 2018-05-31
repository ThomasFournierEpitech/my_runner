/*
** EPITECH PROJECT, 2017
** printf
** File description:
** printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"
#include <unistd.h>
#include <stdarg.h>

void my_print_putchar(va_list list)
{
	char c = va_arg(list, int);

	write (1, &c, 1);
}
void my_putchar (char c)
{
	write (1, &c, 1);
}
