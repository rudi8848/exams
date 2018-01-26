/*
Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions: 
--------------------------------------------------------------------------------

Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function 
pointer cmp to select the order to apply, and returns a pointer to the 
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h 
that is provided to you. You must include that file 
(#include "list.h"), but you must not turn it in. We will use our own 
to compile your assignment.

Functions passed as cmp will always return a value different from 
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list 
in ascending order:

int ascending(int a, int b)
{
	return (a <= b);
}
*/

typedef	struct s_list
{
	void 	*next;
	int 	data;
} t_list;


int 	(*cmp)(int, int);

int		ascending(int a, int b)
{
	return a >= b;
}

int		descending(int a, int b)
{
	return a < b;
}

int 	list_size(t_list *lst)
{
	int i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return i;
}

t_list 	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int i = 1;
	int j;
	t_list *tmp = lst->next;
	int size = list_size(lst);
	while (i < size)
	{
		j = 0;
		while (j < size - i)
		{
			if (cmp(t_list))
			j++;
		}
	}
}



int 	main(void)
{

	return 0;
}