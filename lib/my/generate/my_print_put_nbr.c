/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** 
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"
#include <unistd.h>
#include <stdarg.h>

void my_print_put_nbr(va_list list)
{
	my_put_nbr(va_arg(list, int));
}
