#include "validator.h"

char	**validate_date(t_date *date)
{
	int		cont;
	char		**errors;
	const char	*invalid_day = "Data este invalida";
	const char	*invalid_month = "Luna este invalida";
	const char	*invalid_year = "Anul este invalid";

	errors = (char **)malloc(sizeof(char *) * 4);
	cont = 0;
	if (date->day <= 0 || date->day >= 32)
	{
		errors[cont] = strdup(invalid_day);
		cont++;
	}
	if (date->month <= 0 || date->month >= 13)
	{
		errors[cont] = strdup(invalid_month);
		cont++;
	}
	if (date->year <= 2010 || date->year >= 2020)
	{	
		errors[cont] = strdup(invalid_year);
		cont++;
	}
	errors[cont] = NULL;
	return (errors);
}

int	validate_type(char *type)
{
	const char	*types[] = {"mancare", "motorina", "casa", "medicamente", "diverse"};
	int 		i;

	i = 0;
	while (types[i] != NULL)
	{
		if (strcmp(types[i], type) == 0)
			return (1);
		i++;
	}
	return (0);
}

char	**validate_expense(t_expense *exp)
{
	int		i;
	char		**errors;
	char		**date_errors;
	const char	*invalid_type = "Tipul cheltuielii nu este unul din cele prestabilite";
	const char	*invalid_value = "Cheluiala trebuie sa fie un numar pozitiv";

	errors = (char **)malloc(sizeof(char *) * 6);
	date_errors = validate_date(exp->date);
	i = 0;
	while (date_errors[i] != NULL)
	{
		errors[i] = strdup(date_errors[i]);
		i++;
	}
	if (validate_type(exp->type) == 0)
	{
		errors[i] = strdup(invalid_type);
		i++;
	}
	if (exp->value < 0)
	{
		errors[i] = strdup(invalid_value);
		i++;
	}
	errors[i] = NULL;
	return (errors);
}
