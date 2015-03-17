#include "repo.h"

void	*read_from_file()
{
	FILE		*fp;
	char		*line;
	int		ret;
	int		j;
	int		k;
	char		*id;
	char		*date;
	char		*type;
	char		*value;
	t_expense	*exp;
	t_vector	*vector;

	fp = fopen(FILENAME, "r");
	line = (char *)malloc(sizeof(char) * 100);
	id = (char *)malloc(sizeof(char) * 10);
	date = (char *)malloc(sizeof(char) * 20);
	vector = create_vector();
	while (fgets(line, 100, fp) != NULL)
	{
		j = 0;
		k = 0;
		while (line[j] != ' ')
		{
			id[k] = line[j];
			j++;
			k++;
		}
		id[k] = 0;
		j++;
		k = 0;
		while (line[j] != ' ')
		{
			date[k] = line[j];
			j++;
			k++;
		}
		date[k] = 0;
		j++;
		type = (char *)malloc(sizeof(char) * 50);
		k = 0;
		while (line[j] != ' ')
		{
			type[k] = line[j];
			j++;
			k++;
		}
		type[k] = 0;
		j++;
		k = 0;
		value = (char *)malloc(sizeof(char) * 10);
		while (line[j] != '\n')
		{
			value[k] = line[j];
			j++;
			k++;
		}
		value[k] = 0;
		exp = set_expense(atoi(id), asign_date(date), type, atoi(value));
		add_elem(vector, exp, vector->size);
	}
	return (vector);
}

void		write_to_file(t_vector *vect)
{
	FILE		*fp;
	t_expense	*exp;
	t_date		*date;
	int		i;

	fp = fopen(FILENAME, "w+");
	i = 0;
	while(i < vect->size)
	{
		exp = vect->elemente[i];
		date = exp->date;
		fprintf(fp, "%d %d/%d/%d %s %d\n", exp->id, date->day, date->month, date->year, exp->type, exp->value);
		i++;
	}
	fclose(fp);
}

int		add_to_vector(t_expense *cur_exp, int pos)
{
	t_vector	*vect;
	int		i;
	t_expense	*exp;

	vect = read_from_file();
	i = 0;
	while (i < vect->size && pos == -1)
	{
		exp = vect->elemente[i];
		if (exp->id == exp->id)
			return (0);
		i++;
	}
	if (pos == -1)
		add_elem(vect, cur_exp, vect->size);
	else
	{
		free(vect->elemente[pos]);
		add_elem(vect, cur_exp, pos);
	}
	write_to_file(vect);
	return (1);
}

t_vector	*get_all_exp_repo()
{
	t_vector	*vector;

	vector = read_from_file();
	return (vector);
}

