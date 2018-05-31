/*
** EPITECH PROJECT, 2017
** my_compute_power_rec.c
** File description:
** 
*/

int my_compute_power_rec(int nb, int p)
{	
	int result=1;
	
	if (p == 0)
		return(1);
	if (p < 0)
		return(0);
	result = nb * my_compute_power_rec(nb,p-1);	
	return(result);
}

