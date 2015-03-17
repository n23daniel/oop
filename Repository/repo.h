#ifndef REPO_H
# define REPO_H

# define FILENAME "file.txt"

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
#include "../Utils/utils.h"
#include "../Domain/expense.h"
#include "../Utils/dynamic_vector.h"

t_vector	*get_all_exp_repo();
int		add_to_vector(t_expense *exp, int pos);

#endif
