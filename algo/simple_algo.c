/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:02:32 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/16 19:27:41 by brouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	simple_sort(char *argv[], t_list **list, t_count *count)
{
	int	size;

	size = ft_lstsize((*list));
	if (size == 3)
		sort3(argv, list, count);
	else
		selection_sort(argv, list, count);
}

void	sort3(char *argv[], t_list **a_list, t_count *count)
{
	t_list	*last;
	int		first;
	int		second;

	first = (*a_list)->data;
	second = (*a_list)->next->data;
	last = ft_lstlast((*a_list));
	if (sorted((a_list)) == 0)
		exit(2);
	if (first > second && second < last->data && last->data > first)
		sa(argv, a_list, count);
	else if (first > second && second > last->data && last->data < first)
	{
		sa(argv, a_list, count);
		rra(argv, a_list, count);
	}
	else if (first > second && second < last->data && last->data < first)
		ra(argv, a_list, count);
	else if (first < second && second > last->data && last->data > first)
	{
		sa(argv, a_list, count);
		ra(argv, a_list, count);
	}
	else
		rra(argv, a_list, count);
}

t_list	**sort_logic(char *argv[], t_list **a_list, t_count *count)
{
	int		index;
	int		len;
	int		val;
	t_list	**b_list;

	b_list = malloc(sizeof(t_list *));
	*b_list = NULL;
	len = ft_lstsize((*a_list));
	while (len > 0)
	{
		index = min_index(a_list);
		if (index <= len / 2)
		{
			while (index-- > 0)
				ra(argv, a_list, count);
		}
		else
		{
			val = len - index;
			while (val-- > 0)
				rra(argv, a_list, count);
		}
		pb(argv, a_list, b_list, count);
		len--;
	}
	return (b_list);
}

void	selection_sort(char *argv[], t_list **a_list, t_count *count)
{
	t_list	**b_list;

	if (sorted(a_list) == 0)
		exit(2);
	b_list = sort_logic(argv, a_list, count);
	while (*b_list)
		pa(argv, a_list, b_list, count);
	free(b_list);
}
