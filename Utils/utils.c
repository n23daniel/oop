#include "utils.h"

int	is_nbr(char *str)
{
	while (*str != 0)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	is_digit(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	is_date(char *str)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (is_digit(str[i + k]))
		k++;
	if (k != 0 && str[i + k] == '/')
		i = i + k + 1;
	else
		return (0);
	k = 0;
	while (is_digit(str[i + k]))
		k++;
	if (k != 0 && str[i + k] == '/')
		i = i + k + 1;
	else
		return (0);
	while (is_digit(str[i + k]))
		k++;
	if (k != 0 && str[i + k] == 0)
		return (1);
	return (0);
}

void	add_error(char ***errors, char *error)
{
	int i;

	i = 0;
	while ((*errors)[i] != NULL)
		i++;
	(*errors)[i] = strdup(error);
}

void	print_vector(t_vector *vect)
{
	t_expense	*e;
	t_date		*d;
	int		i;

	i = 0;
	while (i < vect->size)
	{
		e = (t_expense *)vect->elemente[i];
		d = e->date;
		printf("%d  |  %d-%d-%d  |  %s  |  %d\n", e->id, d->day, d->month, d->year, e->type, e->value);
		i++;
	}
}

void	add_to_found_list(int **found_list, int found)
{
	int	i;

	i = 0;
	while ((*found_list)[i] != -1)
		i++;
	(*found_list)[i] = found;
	(*found_list)[i + 1] = -1;
}

int	search_found_list(int *found_list, int found)
{
	int	i;

	i = 0;
	while (found_list[i] != -1)
	{
		if (found_list[i] == found)
			return (1);
		i++;
	}
	return (0);
}
