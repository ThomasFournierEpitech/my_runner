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

void print_unprintable (char c)
{
	int nb = c;

	my_putchar('\\');
	my_putnbr_base(nb, "01234567");
	
}
void oct_unprintable(va_list list)
{
	void *str0 = va_arg(list, char *);
	char *str = str0;

	while(*str != '\0'){
		if ( *str < 32 || *str >= 127)
			print_unprintable(*str);
		else
			my_putchar(*str);
		str++;
	}
}
