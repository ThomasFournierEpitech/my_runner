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

void check_pourcent (char *str)
{
	if (*str == '%') {
		write (1, str, 1);
	}
}
char	check_arg(char flag, va_list list, s_fptr *str)
{
	int cnt = 0;

	while (cnt < NB_FLAG) {
		if (str[cnt].balise == flag)
			str[cnt].fptr(list);
		cnt++;
	}
	
	return ('\0');
	
}
s_fptr *initialise_flag2(s_fptr *str)
{
	str[8].balise = 'p';
	str[8].fptr = &print_memory_address;
	str[9].balise = 'b';
	str[9].fptr = &from_uint_to_ubin;
	str[10].balise = 'S';
	str[10].fptr = &oct_unprintable;
	return (str);
}
s_fptr *initialise_flag()
{
	s_fptr *str;

	str = malloc(sizeof(s_fptr) * NB_FLAG);
	str[0].balise = 'c';
	str[0].fptr = &my_print_putchar;
	str[1].balise = 's';
	str[1].fptr = &my_print_putstr;
	str[2].balise = 'd';
	str[2].fptr = &my_print_put_nbr;
	str[3].balise = 'i';
	str[3].fptr = &my_print_put_nbr;
	str[4].balise = 'u';
	str[4].fptr = &from_uint_to_udec;
	str[5].balise = 'x';
	str[5].fptr = &from_uint_to_uhexa;
	str[6].balise = 'X';
	str[6].fptr = &from_uint_to_uhexA;
	str[7].balise = 'o';
	str[7].fptr = &from_uint_to_uoct;
	str = initialise_flag2(str);

	return (str);
}
void	my_printf(char *str, ...)
{
	va_list list;
	s_fptr *flag = initialise_flag();
	
	va_start(list, str);
	while (*str != '\0') {
		if (*str == '%' && *(str + 1) != '%') {
			check_arg(*(str + 1), list, flag);
			str += 2;
		} else if (*str == '%' && *(str + 1) == '%') {
			check_pourcent(str + 1);
			str += 2;
		} else {
		my_putchar(*str);
		str++;
		}
	}
	free(flag);
	va_end(list);
}
