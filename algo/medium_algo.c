#include "../push_swap.h"

void	chunk_sort(t_list **a_list) // marche pas doit faire fonctionner
{
	int **tab;
	int size;
	int index;
	int index2;
	t_list *tmp;
	int val;

	tmp = (*a_list);
	size = ft_lstsize((*a_list));
	tab = malloc((size / 5) * sizeof(int *));
	if (!tab)
		return ;
	index = 0;
	index2 = 0;
	while (index < 5)
		tab[index++] = malloc(5 * sizeof(int));
	index = 1;
	while (tmp)
	{
		if (index2 == 5)
		{
			index++;
			index2 = 0;
		}

		val = tmp->data;
		tab[index][index2] = val;
		index2++;
		tmp = tmp->next;
	}
	printf(" tab = %d\n ", tab[2][2]);
}