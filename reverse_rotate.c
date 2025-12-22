#include "push_swap.h"

void	rra(t_list **list)
{
	t_list *end;
	int tmp;
	t_list *lst;

	lst = (*list);
	end = ft_lstlast((lst));
	while (lst && (lst)->next)
	{
		tmp = (lst)->data;
		(lst)->data = end->data;
		end->data = tmp;
		lst = lst->next;
	}
	return ;
}