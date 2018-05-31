
/*
** EPITECH PROJECT, 2017
** my_print_alpha.c
** File description:
** 
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"
#include <unistd.h>
#include <stdarg.h>


void my_putstr(void *copy)
{
	char const *str = copy;
	int i = 0;

	while(str[i] != '\0'){
		my_putchar(str[i]);
		i = i + 1;
	}
}
void my_print_putstr(va_list list)
{
	my_putstr(va_arg(list, char *));
}
