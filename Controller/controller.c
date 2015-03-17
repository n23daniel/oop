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
		if (!add_to_vector(exp, -1))
			add_error(&errors, "Id-ul dat este folosit");
	}
	return (errors);
}

char		**modify_date(int id, char *date_str)
{
	char		**errors;
	t_date		*date;
	t_vector	*vect;
	t_expense	*exp;
	t_expense	*new_exp;
	int		i;
	int		found;

	date = asign_date(date_str);
	errors = (char **)malloc(sizeof(char *) * 5);
	errors[0] = NULL;
	errors = validate_date(date);
	vect = get_all_exp_repo();
	i = 0;
	found = 0;
	while (i < vect->size)
	{
		exp = vect->elemente[i];
		if (exp->id == id)
		{
			found = 1;
			new_exp = set_expense(id, date, exp->type, exp->value);
			add_to_vector(new_exp, i);
			break ;
		}
		i++;
	}
	if (found == 0)
		add_error(&errors, "Id-ul dat nu a fost gasit");
	return (errors);
}

char		**modify_type(int id, char *type)
{
	char		**errors;
	t_date		*date;
	t_vector	*vect;
	t_expense	*exp;
	t_expense	*new_exp;
	int		i;
	int		found;


	errors = (char **)malloc(sizeof(char *) * 5);
	errors[0] = NULL;
	if (validate_type(type))
		add_error(&errors, "Tipul cheluielii nu este unu predefinit");
	vect = get_all_exp_repo();
	i = 0;
	found = 0;
	while (i < vect->size)
	{
		exp = vect->elemente[i];
		if (exp->id == id)
		{
			found = 1;
			new_exp = set_expense(id, exp->date, type, exp->value);
			add_to_vector(new_exp, i);
			break ;
		}
		i++;
	}
	if (found == 0)
		add_error(&errors, "Id-ul dat nu a fost gasit");
	return (errors);
}

char		**modify_value(int id, int value)
{
	char	**errors;

	t_date		*date;
	t_vector	*vect;
	t_expense	*exp;
	t_expense	*new_exp;
	int		i;
	int		found;


	errors = (char **)malloc(sizeof(char *) * 5);
	errors[0] = NULL;
	if (value < 0)
		add_error(&errors, "Valoarea trebuie sa fie un numar pozitiv");
	vect = get_all_exp_repo();
	i = 0;
	found = 0;
	while (i < vect->size)
	{
		exp = vect->elemente[i];
		if (exp->id == id)
		{
			found = 1;
			new_exp = set_expense(id, exp->date, exp->type, value);
			add_to_vector(new_exp, i);
			break ;
		}
		i++;
	}
	if (found == 0)
		add_error(&errors, "Id-ul dat nu a fost gasit");
	return (errors);
}

t_vector	*sort_by_date(int reversed)
{
	t_vector	*vect;
	int		i;
	t_vector	*sorted;

	vect = get_all_exp_repo();
	sorted = create_vector();
	i = 0;
	while (i < vect->size)
	{
		
	}

	return (vect);
}

t_vector	*sort_by_type(int reversed)
{
	t_vector	*vect;
	int		i;
	int		j;
	t_vector	*sorted;
	char		*min;
	char		*max;
	int		found;
	int		*found_list;
	t_expense	*exp;


	vect = get_all_exp_repo();
	sorted = create_vector();
	found_list = (int *)malloc(sizeof(int) * (vect->size + 1));
	found_list[0] = -1;
	i = 0;
	found = 0;
	while (i < vect->size)
	{
		j = 0;
		min = strdup("{");
		max = strdup("");
		max[0] = 0;
		while (j < vect->size)
		{
			exp = vect->elemente[j];
			printf("min: ~%s~|~%s~ = %d\n", exp->type, min, strcmp(exp->type, min));
			printf("max: ~%s~|~%s~ = %d\n", exp->type, max, strcmp(exp->type, max));
			if (strcmp(exp->type, min) > 0 && search_found_list(found_list, j) == 0 && reversed == 1)
			{
				min = strdup(exp->type);
				found = j;
			}
			if (strcmp(exp->type, max) < 0 && search_found_list(found_list, j) == 0 && reversed == -1)
			{
				max = strdup(exp->type);
				found = j;
			}
			j++;
		}
		add_to_found_list(&found_list, found);
		add_elem(sorted, vect->elemente[found], sorted->size);
		exp = vect->elemente[found];
		i++;
	}
	return (vect);
}

t_vector	*sort_by_value(int reversed)
{
	t_vector	*vect;
	int		i;
	int		j;
	t_vector	*sorted;
	int		min;
	int		max;
	int		found;
	int		*found_list;
	t_expense	*exp;


	vect = get_all_exp_repo();
	sorted = create_vector();
	found_list = (int *)malloc(sizeof(int) * (vect->size + 1));
	found_list[0] = -1;
	i = 0;
	found = 0;
	while (i < vect->size)
	{
		j = 0;
		min = 32000;
		max = -1;
		while (j < vect->size)
		{
			exp = vect->elemente[j];
			if (exp->value < min && search_found_list(found_list, j) == 0 && reversed == 1)
			{
				min = exp->value;
				found = j;
			}
			if (exp->value > max && search_found_list(found_list, j) == 0 && reversed == -1)
			{
				max = exp->value;
				found = j;
			}
			j++;
		}
		add_to_found_list(&found_list, found);
		add_elem(sorted, vect->elemente[found], sorted->size);
		exp = vect->elemente[found];
		i++;
	}
	return (sorted);
}

t_vector	*get_all_exp_ctrl()
{
	return (get_all_exp_repo());
}
