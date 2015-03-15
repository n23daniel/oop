#ifndef EXPENSE_H
# define EXPENSE_H

# include <stdlib.h>
# include "date.h"

typedef struct 	s_expense
{
	int	id;
	t_date	*date;
	char	*type;
	int	value;
}		t_expense;

t_expense	*set_expense(int id, t_date *date, char *type, int value);
void		set_id(t_expense *exp, int id);
void		set_date(t_expense *exp, t_date *date);
void		set_type(t_expense *exp, char *type);
void		set_value(t_expense *exp, int value);
int		get_id(t_expense *exp);
t_date		*get_date(t_expense *exp);
char		*get_type(t_expense *exp);
int		get_value(t_expense *exp);

#endif
