#ifndef UI_H
# define UI_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "../Domain/expense.h"
# include "../Controller/controller.h"
# include "../Utils/utils.h"

# define RESET "\x1B[0m"
# define ERROR "\x1B[38;5;160m"
# define WARNING "\x1B[0m"
# define TEXT "\x1B[38;5;25m"
# define SUBTEXT "\x1B[38;5;24m"
# define CMD "\x1B[1m"

int	start_ui();

#endif
