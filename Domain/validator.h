#ifndef VALIDATOR_H
# define VALIDATOR_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "expense.h"

char	**validate_date(t_date *date);
int	validate_type(char *type);
char	**validate_expense(t_expense *exp);

#endif
