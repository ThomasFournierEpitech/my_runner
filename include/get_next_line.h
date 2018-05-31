/*
** EPITECH PROJECT, 2017
** rush1
** File description:
** 
*/

#ifndef GET_NEXT_LINE_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *get_next_line(int fd);

struct read_variables {
	int size;
	int fd;
};
typedef struct read_variables rd_t;

#ifndef READ_SIZE
#define READ_SIZE (999)
#endif /* ! READ_SIZE */

#endif /* !GET_NEXT_LINE_H */
