/*
** EPITECH PROJECT, 2018
** textcount
** File description:
** textcount
*/

#include "include.h"

void	get_flag(int *i, int *h, int ac, char **av)
{
	int n = 0;

	while (n < ac) {
		if (my_strncmp("-i", av[n], 3) == 0)
			*i = 1;
		if (my_strncmp("-h", av[n], 3) == 0)
			*h = 1;
		n++;
	}
}
