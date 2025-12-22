#include "push_swap.h"

int	sorted(t_list *list)
{
	while (list && list->next)
	{
		if (list->data > list->next->data)
		{
			return (1);
		}
		list = list->next;
	}
	// printf("sorted");
	return (0);
}
int	ft_lstsize(t_list *lst)
{
	int	index;

	index = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		index++;
	}
	return (index);
}

void	bubble_sort(t_list **a_list)
{
	t_list	*tmp;
	int		sort;
	int		len;
	int		index;
	int		index2;

	sort = 1;
	tmp = (*a_list);
	len = ft_lstsize(tmp);
	if (sorted(tmp) == 0)
		return ;
	while (sort)
	{
		sort = 0;
		index2 = 0;
		while (index2 < len - 1)
		{
			if ((*a_list)->data > (*a_list)->next->data)
			{
				sa(a_list);
				sort = 1;
			}
			ra(a_list);
			index2++;
		}
		index = 0;
		while (index < len - 1)
		{
			rra(a_list);
			index++;
		}
	}
}
