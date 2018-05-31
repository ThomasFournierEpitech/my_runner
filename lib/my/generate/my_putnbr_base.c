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
#include <math.h>

int my_strlen(char const *str)
{
	int i = 0;

	if (str != NULL) {
		while((str[i]) != '\0') {
			i = i + 1;
		}
	}
	return(i);
}
long long unsigned int my_compute_power_rec(long long unsigned int nb, int p)
{	
	double result = 1;
	
	if (p == 0)
		return(1);
	if (p < 0)
		return(0);
	result = nb * my_compute_power_rec(nb ,p - 1);
	return(result);
}
int find_power(long long unsigned int nbr, int const lenght)
{
	int power = 0;

	while ((nbr / lenght) > 0) {
		nbr = nbr / lenght;
		power++;
	}
	return (power);
}
int change_base_it(long long unsigned int nbr, int const lenght, int power, char const *base)
{
	int value;
	long long unsigned int result = 0;

	while (power >= 0) {
		result = my_compute_power_rec(lenght, power);
		value = nbr / result;
		nbr = nbr % my_compute_power_rec(lenght, power);
		my_putchar(base[value]);
		power--;
	}
	return (0);
}
int my_putnbr_base(long long unsigned int nbr, char *base)
{
	int const lenght = my_strlen(base);
	int power = 0;

	power = find_power(nbr, lenght);
	change_base_it(nbr, lenght, power, base);
	return (0);
}
