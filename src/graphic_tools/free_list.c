/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "include.h"

void	add_in_free_list(ll_free_t *root,
	void *shp, void (*free_fptr), void *free_this)
{
	ll_free_t *new = malloc(sizeof(*new));

	new->shp = shp;
	new->next = root->next;
	new->prev = root;
	new->free = free_fptr;
	new->free_this = free_this;
	if (root->next)
		root->next->prev = new;
	root->next = new;
}

ll_free_t	*create_free_list_root()
{
	ll_free_t *root = malloc(sizeof(*root));

	root->shp = NULL;
	root->next = NULL;
	root->prev = NULL;
	root->free = NULL;
	root->free_this = NULL;
	return (root);
}

void free_free_list(ll_free_t *block)
{
	block->free(block->free_this);
}

void my_free_list(ll_free_t *free_list)
{
	ll_free_t *tmp = free_list->next;
	ll_free_t *save = NULL;

	while (tmp) {
		save = tmp->next;
		free_free_list(tmp);
		free(tmp);
		tmp = save;
	}
	free_list->next = NULL;
}
