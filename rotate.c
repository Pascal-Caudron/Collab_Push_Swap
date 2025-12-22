#include "push_swap.h"

void	ra(t_list **list)
{
	int tmp;
	t_list *lst;

	lst = (*list);
	while ((lst) && (lst)->next)
	{
		tmp = (lst)->data;
		(lst)->data = (lst)->next->data;
		(lst)->next->data = tmp;
		(lst) = (lst)->next;
	}
}