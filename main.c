#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list *tmp;
	t_list **list = malloc(sizeof(t_list *));

	*list = NULL;
	parsing(argc, argv, list);
	tmp = (*list);
	bubble_sort(list);
	while (tmp)
	{
		printf("arg 1 = %d\n", tmp->data);
		tmp = tmp->next;
	}
	return (0);
}