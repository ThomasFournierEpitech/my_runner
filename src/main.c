/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "include.h"

int my_strcmp(char const *s1, char const *s2)
{
	int i = 0;

	while(s1[i] != '\0' || s2[i] != '\0' ) {
		if(s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
		else
			i++;
	}
	return (0);
}
void print_rules()
{
	char *s = NULL;
	int fd = open("rules", O_RDONLY);

	s = get_next_line(fd);
	while (s != NULL) {
		my_printf("%s\n", s);
		s = get_next_line(fd);
	}
}
int main(int ac, char **av)
{
	sfBool infinity = sfFalse;
	char *filename = NULL;
	int i = 0;
	int h = 0;

	get_flag(&i, &h, ac, av);
	if (h) {
		print_rules();
		return (0);
	}
	if (ac < 2) {
		my_printf("Not enought argument, use -h.\n");
		return (84);
	}
	filename = av[1];
	if (my_strncmp("map", filename, 3) != 0) {
		my_printf("Wrong map.\n");
		return (84);
	}
	if (i)
		infinity = sfTrue;
	start_game(filename, infinity);
	return (0);
}
