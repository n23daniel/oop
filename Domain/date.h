#ifndef DATE_H
# define DATE_H

# include <string.h>
# include <stdlib.h>

typedef struct	s_date
{
	int day;
	int month;
	int year;
}		t_date;

t_date		*asign_date(char *str);

#endif
