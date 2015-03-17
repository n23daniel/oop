#ifndef UTILS_H
# define UTILS_H
# define BUFF_SIZE 20 //get_next_line.c

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include "../Domain/expense.h"
# include "dynamic_vector.h"

int	is_nbr(char *str);
int	is_date(char *str);
t_date	*asign_date(char *str);
void	add_error(char ***errors, char *error);
void	print_vector(t_vector *vect);
void	add_to_found_list(int **found_list, int found);
int	search_found_list(int *found_list, int found);

#endif
