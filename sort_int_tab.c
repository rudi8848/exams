/*
Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions: 
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.

*/

#include <stdio.h>


void	sort_int_tab(int *tab, unsigned size)
{
	int 	i = 1;
	int 	j;
										//int 	temp;
	while (i < size)
	{
		j = 0;
		while (j < size - i)
		{
			if (tab[j] > tab[j+1])
			{
				tab[j] ^= tab[j+1];		//temp = tab[j];
				tab[j+1] ^= tab[j];		//tab[j] = tab[j+1];
				tab[j] ^= tab[j+1];		//tab[j+1] = temp;
			}
			j++;
		}
		i++;
	}
	
}

int 		main(void)
{
	int tab[6] = {65, 12, 78, 78, 13, 98};
	int i = 0;
	sort_int_tab(tab, 6);
	while (i < 6)
	{
		printf("[%d]%c", tab[i], i == 5 ? '\n' : ' ');
		i++;
	}
	return 0;
}
