#include "dynamic_vector.h"

t_vector	*create_vector()
{
	t_vector *vect;

	vect = (t_vector *)malloc(sizeof(t_vector));
	vect->capacity = 100;
	vect->elemente = (Elem *)malloc(sizeof(Elem) * (vect->capacity));
	vect->size = 0;
	return (vect);
}

void		add_elem(t_vector *vect, Elem element, int pos)
{
	int new_capacity;

	if (vect->capacity == vect->size)
	{
		new_capacity = vect->capacity + vect->capacity / 2;
		vect->elemente = (Elem *)realloc(vect->elemente, new_capacity);
		vect->capacity = new_capacity;
	}
	vect->elemente[pos] = element;
	if (pos > vect->size)
		vect->size++;
}

void		free_vector(t_vector *vect)
{
//	int i;

//	i = 0;
//	while (i < vect->size)
//	{
//		free(vect->elemente[i]);
//		i++;
//	}
//	free(vect->elemente);
	free(vect);
}
