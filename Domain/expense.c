#include "expense.h"
#include <string.h>

t_expense	*set_expense(int id, t_date *date, char *type, int value)
{
	t_expense	*exp;

	exp = (t_expense *)malloc(sizeof(t_expense) * 10000);
	exp->type = (char *)malloc(sizeof(char) * (strlen(type) + 1));
	set_id(exp, id);
	set_date(exp, date);
	set_type(exp, type);
	set_value(exp, value);
	return (exp);
}

void	set_id(t_expense *exp, int id)
{
	exp->id = id;
}

void	set_date(t_expense *exp, t_date *date)
{
	exp->date = date;
}

void	set_type(t_expense *exp, char *type)
{
	strcpy(exp->type, type);
}

void	set_value(t_expense *exp, int value)
{
	exp->value = value;
}

int	get_id(t_expense *exp)
{
	return (exp->id);
}

t_date	*get_date(t_expense *exp)
{
	return (exp->date);
}

char	*get_type(t_expense *exp)
{
	return (exp->type);
}

int	get_value(t_expense *exp)
{
	return (exp->value);
}
