/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:02:32 by brouzaud          #+#    #+#             */
/*   Updated: 2025/12/22 09:33:18 by brouzaud         ###   ########.fr       */
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

int	check_bubble_sort(t_list **a_list, int argc, char *argv[])
{
	t_list	*tmp;
	t_flag	flag;
	int		len;

	flag = arg_error(argc, argv);
	if (flag == COMPLEX || flag == MEDIUM)
		exit(2);
	tmp = (*a_list);
	len = ft_lstsize(tmp);
	if (sorted(tmp) == 0)
		exit(2);
	return (len);
}

void	bubble_sort(t_list **a_list, int argc, char *argv[])
{
	t_list	*tmp;
	int		sort;
	int		index2;

	sort = 1;
	tmp = (*a_list);
	tmp->index2 = check_bubble_sort(a_list, argc, argv);
	while (sort)
	{
		sort = 0;
		tmp->index = 0;
		while (tmp->index < tmp->index2 - 1)
		{
			if (tmp->data > tmp->next->data)
			{
				sa(a_list);
				sort = 1;
			}
			ra(a_list);
			tmp->index++;
		}
		index2 = 0;
		while (index2++ < tmp->index2 - 1)
			rra(a_list);
	}
}
