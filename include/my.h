/*
** EPITECH PROJECT, 2017
** rush1
** File description:
**
*/

#ifndef MY_H_
#define MY_H_

int my_strncmp(char const *s1, char const *s2, int n);
void my_printf(char *, ...);
int my_strlen(char *str);
int start_game();
char	*my_getstr(int nb);
char	**my_str_to_word_array(char *str, char del);
int	my_getnbr(char *str);
void	get_flag(int *r, int *t, int ac, char **av);
config_t	create_config();

#endif /* MY_H_ */
