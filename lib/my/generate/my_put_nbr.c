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

void	my_putchar(char c);

void	my_put_nbr(long long unsigned int nb)
{
	if (nb < 0) {
		nb *= -1;
		my_putchar('-');
	}
	if (nb > 9)
		my_put_nbr(nb / 10);
	my_putchar(nb % 10 + '0');
}
