#ifndef CONTROLLER_H
# define CONTROLLER_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "../Domain/expense.h"
# include "../Domain/validator.h"
# include "../Utils/dynamic_vector.h"
# include "../Repository/repo.h"

t_vector	*get_all_exp_ctrl();
char		**add_expense(int id, char *date, char *type, int value);
char		**delete_expense(int id);
char		**modify_date(int id, char *date);
char		**modify_type(int id, char *type);
char		**modify_value(int id, int value);
t_vector	*sort_by_date(int reverse);
t_vector	*sort_by_type(int reverse);
t_vector	*sort_by_value(int reverse);

#endif
