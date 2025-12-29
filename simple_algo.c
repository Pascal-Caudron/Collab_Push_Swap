/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjmrzd <bjmrzd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:02:32 by brouzaud          #+#    #+#             */
/*   Updated: 2025/12/29 23:22:36 by bjmrzd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void	simple_sort(int argc, char *argv[], t_list **list, t_count *count)
{
	t_flag	flag;
	t_flag	isbench;
	int		size;

	isbench = arg_error(argc, argv);
	if (isbench == BENCH)
		flag = second_flag(argc, argv);
	else
		flag = arg_error(argc, argv);
	if (flag == SIMPLE)
	{
		size = ft_lstsize((*list));
		if (size == 3)
			sort3(list, count);
	}
}

void	sort3(t_list **a_list, t_count *count)
{
	// t_list	*last;
	// last = ft_lstlast((*a_list));
	if (sorted((*a_list)) == 0)
		exit(2);
	if ((*a_list)->data > (*a_list)->next->data)
	{
		ra(a_list, count);
	}
}