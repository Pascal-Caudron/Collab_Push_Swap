#include "push_swap.h"

void	sa(t_list **list)
{
	int tmp;
	t_list *head;

	if (!(*list)->data || !(*list)->next->data)
		return ;
	head = (*list);
	tmp = (*list)->data;
	(*list)->data = (*list)->next->data;
	(*list)->next->data = tmp;
	(*list) = head;
	return ;
}