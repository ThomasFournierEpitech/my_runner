/*
** EPITECH PROJECT , 2017
** Get_Next_line
** Main fonction
** fonction Get_Next_line complete
*/

#include "include.h"

char *my_linecat(char *src, char *add)
{
	char *new = NULL;
	int size = my_strlen(src) + my_strlen(add);
	int i = 0;
	int j = 0;

	if((new = malloc(sizeof(char) * size + 1)) == NULL)
		return NULL;
	new[size] = '\0';
	while (src != NULL && src[i] != '\0') {
		new[i] = src[i];
		i++;
	}
	if (src != NULL)
		free(src);
	while (add != NULL && add[j] != '\0') {
		new[i + j] = add[j];
		j++;
	}
	return (new);
}

char *fill_line(char *tmp, char buffer[], int *i, char *line)
{
	int j = 0;

	while (buffer[*i] != '\n' && buffer[*i] != '\0')
		tmp[j++] = buffer[(*i)++];
	tmp[j] = '\0';
	line = my_linecat(line, tmp);
	if (buffer[*i] == '\n')
		free(tmp);
	return (line);
}

char *alloc(int fd, char buffer[], int *i, char *line)
{
	int size = 0;
	char *tmp = NULL;;

	if ((tmp = malloc(sizeof(char) * READ_SIZE + 1)) == NULL)
		return NULL;
	while ((size = read(fd, buffer, READ_SIZE)) > 0) {
		buffer[size] = '\0';
		line = fill_line(tmp, buffer, i, line);
		if (buffer[*i] == '\n')
			return (line);
		*i = 0;
	}
	free(tmp);
	free(line);
	return (NULL);
}

char *ralloc(int fd, char buffer[], int *i, char *line)
{
	char *tmp = NULL;;
	int j = 0;

	if ((tmp = malloc(sizeof(char) * READ_SIZE + 1)) == NULL)
		return NULL;
	while (buffer[*i] != '\n' && buffer[*i] != '\0') {
			tmp[j] = buffer[*i];
			j++;
			(*i)++;
	}
	tmp[j] = '\0';
	line = my_linecat(line, tmp);
	free(tmp);
	if (buffer[*i] == '\n')
		return (line);
	*i = 0;
	return(alloc(fd, buffer, i, line));
}

char *get_next_line(int fd)
{
	static char buffer[READ_SIZE];
	static int i = -1;
	char *line = NULL;

	if (buffer[i] == '\n')
		i++;
	if (i == -1) {
		i = 0;
		buffer[0] = '0';
	}
	if (i != 0)
		line = ralloc(fd, buffer, &i, line);
	if (buffer[i] == '\n')
		return (line);
	line = alloc(fd, buffer, &i, line);
	if (buffer[i] == '\n')
		i++;
	return (line);
}
