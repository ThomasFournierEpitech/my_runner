/*
** EPITECH PROJECT, 2017
** printf
** File description:
** printf
*/

#ifndef MY_H_
#define MY_H_
#define NB_FLAG 11

typedef struct t_fptr
{
	char balise;
	void (*fptr)(va_list);
} s_fptr;
void print_memory_address(va_list list);
void oct_unprintable(va_list list);
void my_put_nbr(long long unsigned int nb);
void from_uint_to_ubin(va_list list);
void from_uint_to_uoct(va_list list);
void from_uint_to_uhexA(va_list list);
void from_uint_to_uhexa(va_list list);
void from_uint_to_udec(va_list list);
void from_uint_to_uoct(va_list list);
int my_putnbr_base(long long unsigned int nbr, char *base);
void my_putstr(void *copy);
void my_print_put_nbr(va_list list);
void my_print_putstr(va_list list);
void my_print_putchar(va_list list);
void my_putchar(char c);
char check_arg(char flag, va_list list, s_fptr *str);
s_fptr *initialise_flag(void);
void my_printf(char *, ...);

#endif /* MY_H_ */	
