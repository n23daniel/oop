#ifndef DYNAMIC_VECTOR_H
# define DYNAMIC_VECTOR_H

# include <stdlib.h>

typedef void *	Elem;

typedef struct	s_vector
{
	int	capacity;
	int	size;
	Elem	*elemente;
}		t_vector;

t_vector	*create_vector();
void		add_elem(t_vector *vect, Elem element, int pos);
void		free_vector(t_vector *vect);
#endif
