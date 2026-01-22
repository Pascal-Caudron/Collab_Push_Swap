/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:44:33 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/22 17:01:05 by brouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	square_root(int size)
{
	int	val;

	val = 0;
	while (val * val <= size)
		val++;
	return (val);
}

int	max_index(t_list **list)
{
	int		max;
	int		pos;
	t_list	*tmp;

	tmp = (*list);
	max = tmp->data;
	pos = tmp->index;
	while (tmp)
	{
		if (tmp->data > max)
		{
			max = tmp->data;
			pos = tmp->index;
		}
		tmp = tmp->next;
	}
	return (pos);
}

void	medium_push_back(char *argv[], t_list **a_list, t_list **b_list,
		t_count *count)
{
	int	index_max;
	int	size;

	// index_max = max_index(b_list);
	// presort_index(b_list);
	while (*b_list)
	{
		size = ft_lstsize((*b_list));
		index_max = max_index(b_list);
		if ((*b_list)->index == index_max)
		{
			pa(argv, a_list, b_list, count);
		}
		else if (index_max <= size / 2)
			rb(argv, b_list, count);
		else
			rrb(argv, b_list, count);
	}
	free(b_list);
}

void	bucket_sort(char *argv[], t_list **a_list, t_count *count)
// doit reduire ops
{
	t_list **b_list;
	int bucket_size;
	int size;
	int nb_values;
	int bucket_limit;

	b_list = malloc(sizeof(t_list *));
	*b_list = NULL;
	size = ft_lstsize((*a_list));
	nb_values = 0;
	bucket_size = square_root(size);
	presort_index(a_list);
	bucket_limit = bucket_size;
	while (nb_values < size)
	{
		if ((*a_list)->index < bucket_limit)
		{
			pb(argv, a_list, b_list, count);
			nb_values++;
		}
		else
			ra(argv, a_list, count);

		if (nb_values == bucket_limit)
			bucket_limit += bucket_size;
	}
	medium_push_back(argv, a_list, b_list, count);
}