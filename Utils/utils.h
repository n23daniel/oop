#ifndef UTILS_H
# define UTILS_H
# define BUFF_SIZE 20 //get_next_line.c

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include "../Domain/expense.h"
/*
typedef struct	s_date
{
	int day;
	int month;
	int year;
}		t_date;
*/

int	is_nbr(char *str);
int	is_date(char *str);
t_date	*asign_date(char *str);
void	add_error(char ***errors, char *error);

#endif
