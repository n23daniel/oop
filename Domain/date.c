#include "date.h"

t_date	*asign_date(char *str)
{
	int	i;
	int	k;
	char	*day;
	char	*month;
	char	*year;
	t_date	*date;

	date = (t_date *)malloc(sizeof(t_date) * 10);
	day = (char *)malloc(sizeof(char) * 5);
	month = (char *)malloc(sizeof(char) * 5);
	year = (char *)malloc(sizeof(char) * 10);
	i = 0;
	k = 0;
	while (str[i] != '/')
	{
		day[k] = str[i];
		i++;
		k++;
	}
	day[k] = 0;
	i++;
	k = 0;
	while (str[i] != '/')
	{
		month[k] = str[i];
		i++;
		k++;
	}
	month[k] = 0;
	i++;
	k = 0;
	while (str[i] != 0)
	{
		year[k] = str[i];
		i++;
		k++;
	}
	year[k] = 0;
	date->day = atoi(day);
	date->month = atoi(month);
	date->year = atoi(year);
	return (date);
}
/*
void	test_ctodate()
{
	t_date date;

	asign_date(&date, "1/2/3");
	printf("(%d, %d, %d)\n", date.day, date.month, date.year);
	asign_date(&date, "15/15/2015");
	printf("(%d, %d, %d)\n", date.day, date.month, date.year);
	asign_date(&date, "0/0/0");
	printf("(%d, %d, %d)\n", date.day, date.month, date.year);
}
*/
