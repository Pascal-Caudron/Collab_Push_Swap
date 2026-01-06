/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjmrzd <bjmrzd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:02:32 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/06 04:02:51 by bjmrzd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (sorted(*list) == 0)
			exit(2);
		size = ft_lstsize((*list));
		if (size == 3)
			sort3(list, count);
		else
			selection_sort(list, count);
	}
}

int	getMin(t_list **list)
{
	int		min;
	t_list	*tmp;

	tmp = (*list);
	min = tmp->data;
	while (tmp)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}
int	min_index(t_list **list)
{
	int		min;
	t_list	*tmp;
	int		index;

	index = 0;
	tmp = (*list);
	min = getMin(list);
	while (tmp)
	{
		if (tmp->data == min)
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (index);
}

void	sort3(t_list **a_list, t_count *count)
{
	t_list	*last;
	int		first;
	int		second;

	first = (*a_list)->data;
	second = (*a_list)->next->data;
	last = ft_lstlast((*a_list));
	if (sorted((*a_list)) == 0)
		exit(2);
	if (first > second && second < last->data && last->data > first)
		sa(a_list, count);
	else if (first > second && second > last->data && last->data < first)
	{
		sa(a_list, count);
		rra(a_list, count);
	}
	else if (first > second && second < last->data && last->data < first)
		ra(a_list, count);
	else if (first < second && second > last->data && last->data > first)
	{
		sa(a_list, count);
		ra(a_list, count);
	}
	else
		rra(a_list, count);
}

void	selection_sort(t_list **a_list, t_count *count)
{
	int		index;
	int		len;
	t_list	**b_list;

	b_list = malloc(sizeof(t_list *));
	len = ft_lstsize((*a_list));
	while (len > 0)
	{
		index = min_index(a_list);
		if (index <= len / 2)
		{
			while (index-- > 0)
				ra(a_list, count);
		}
		else
		{
			while ((len - index) > 0)
				rra(a_list, count);
		}
		pb(a_list, b_list, count);
		len--;
	}
	while (*b_list)
		pa(a_list, b_list, count);
}
