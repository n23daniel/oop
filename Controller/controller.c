#include "controller.h"

char	**add_expense(int id, char *date_str, char *type, int value)
{
	char 		**errors;
	t_expense	*exp;
	t_date		*date;

	date = asign_date(date_str);
	exp = set_expense(id, date, type, value);
	errors = validate_expense(exp);
	if (errors[0] == NULL)
	{
		if (!add_to_vector(exp))
			add_error(&errors, "Id-ul dat este folosit");
	}
	return (errors);
}

char		**modify_date(int id, char *date_str)
{
	char		**errors;
	t_date		*date;
	t_vector	*vector;
	t_expense	*exp;
	int		i;
	int		found;

	date = asign_date(date_str);
	vector = get_all_exp_repo();
	i = 0;
	found = 0;
	while (i < vector->size)
	{
		exp = vector->elemente[i];
		if (exp->id == id)
		{
			found = 1;
			free(exp->elemente[i]);
			add_
		}
		i++;
	}

	
	return (errors);
}

char		**modify_type(int id, char *type)
{
	char	**errors;

	return (errors);
}

char		**modify_value(int id, int value)
{
	char	**errors;

	return (errors);
}

t_vector	*get_all_exp_ctrl()
{
	return (get_all_exp_repo());
}
