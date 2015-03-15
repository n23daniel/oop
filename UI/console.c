#include "console.h"

void	print_errors(char **errors)
{
	int i;

	i = 0;
	printf("\n");
	while (errors[i] != NULL)
	{
		printf(ERROR"%s\n"RESET, errors[i]);
		i++;
	}
}

int	add_exp_ui()
{
	char	line[50];
	int	id;
	char	*date;
	char	*type;
	int	value;
	char	**errors;
	int	i;

	printf("Adauga id: ");
	scanf("%s", line);
	if (is_nbr(line))
		id = atoi(line);
	else
	{
		printf(ERROR"Id-ul trebuie format din cifre\n"RESET);
		return (0);
	}
	printf("Adauga data (ZI/LUNA/AN): ");
	scanf("%s", line);
	if (is_date(line))
		date = strdup(line);
	else
	{
		printf(ERROR"Data nu este bine formata\n"RESET);
		return (0);
	}
	printf("Adauga tip: ");
	scanf("%s", line);
	type = strdup(line);
	printf("Adauga valoare: ");
	scanf("%s", line);
	if (is_nbr(line))
		value = atoi(line);
	else
	{
		printf(ERROR"Valoarea trebuie formata din cifre\n"RESET);
		return (0);
	}
	errors = add_expense(id, date, type, value);
	if (errors[0] != NULL)
	{
		print_errors(errors);
	}
	else
		printf(WARNING"Cheluiala a fost adaugata...\n"RESET);
	return (1);
}

void	del_exp_ui()
{
		
}

int	mod_exp_ui()
{
	char	line[50];
	int	id;
	char	**errors;

	printf("Modifica cheluiala cu id-ul: ");
	scanf("%s", line);
	if (is_nbr(line))
		id = atoi(line);
	else
	{
		printf(ERROR"Id-ul trebuie format din cifre\n"RESET);
		return (0);
	}
	while (1)
	{
		printf(SUBTEXT"\n1: Modifica data\n");
		printf("2: Modifica tipul\n");
		printf("3: Modifica valoarea\n"RESET);
		printf(CMD"Alege comanda: "RESET);
		scanf("%s", line);
		if (strcmp(line, "1") == 0)
		{
			printf("Modifica cu data: ");
			scanf("%s", line);
			if (is_date(line))
				errors = modify_date(id, line);
			else
			{
				printf(ERROR"Data nu este bine formata\n"RESET);
				return (0);
			}
			if (errors[0] != NULL)
			{
				print_errors(errors);
			}
			else
				printf(WARNING"Data a fost modificata...\n"RESET);
			break ;
		}
		else if (strcmp(line, "2") == 0)
		{
			printf("Modifica cu tipul: ");
			scanf("%s", line);
			errors = modify_type(id, line);
			if (errors[0] != NULL)
			{
				print_errors(errors);
			}
			else
				printf(WARNING"Tipul a fost modificat...\n"RESET);
			break ;
		}
		else if (strcmp(line, "3") == 0)
		{
			printf("Modifica cu valoarea: ");
			scanf("%s", line);
			if (is_nbr(line))
				errors = modify_value(id, atoi(line));
			else
			{
				printf(ERROR"Valoarea trebuie sa fie formata din cifre\n"RESET);
				return (0);
			}
			if (errors[0] != NULL)
			{
				print_errors(errors);
			}
			else
				printf(WARNING"Valoarea a fost modificata...\n"RESET);
			break ;
		}
		else
			printf(ERROR"Comanda inexistenta\n"RESET);
	}
	return (1);
}

void	search_exp_ui()
{
	
}

void	sort_exp_ui()
{
	
}

void	show_all_ui()
{
	t_vector	*vect;
	int		i;
	t_expense	*e;
	t_date		*d;

	vect = get_all_exp_ctrl();
	i = 0;
	while (i < vect->size)
	{
		e = (t_expense *)vect->elemente[i];
		d = e->date;
		printf("%d  |  %d-%d-%d  |  %s  |  %d\n", e->id, d->day, d->month, d->year, e->type, e->value);
		i++;
	}
}

int	start_ui()
{
	char	*cmd;

	while (1)
	{
		printf(TEXT"1: Adauga cheluiala\n");
		printf("2: Modifica cheltuiala\n");
		printf("3: Sterge cheluiala\n");
		printf("4: Cauta cheluiala\n");
		printf("5: Sorteza cheluieli\n");
		printf("6: Afiseaza toate cheltuielile\n");
		printf("x: Exit\n"RESET);
		printf(CMD"Alege comanda: "RESET);
		cmd = (char *)malloc(sizeof(char) * 10);
		scanf("%s", cmd);
		if (strcmp(cmd, "1") == 0)
			printf("\n"), add_exp_ui();
		else if (strcmp(cmd, "2") == 0)
			printf("\n"), mod_exp_ui();
		else if (strcmp(cmd, "3") == 0)
			printf("\n"), del_exp_ui();
		else if (strcmp(cmd, "4") == 0)
			printf("\n"), search_exp_ui();
		else if (strcmp(cmd, "5") == 0)
			printf("\n"), sort_exp_ui();
		else if (strcmp(cmd, "6") == 0)
			printf("\n"), show_all_ui();
		else if (strcmp(cmd, "x") == 0)
			break ;
		else
			printf(ERROR"\nComanda inexistenta\n"RESET);
		cmd = 0;
		printf("\n");
	}
	return (0);
}
