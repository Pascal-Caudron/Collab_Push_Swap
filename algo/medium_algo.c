/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjmrzd <bjmrzd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:44:33 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/17 17:01:26 by bjmrzd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	square_root(int size)
{
	int	val;

	val = 0;
	while (val * val < size)
		val++;
	return (val);
}

int	max_index(t_list **list)
{
	int		max_index;
	t_list	*tmp;

	tmp = (*list);
	presort_index(list);
	max_index = tmp->index;
	while (tmp)
	{
		if (tmp->index > max_index)
			max_index = tmp->index;
		tmp = tmp->next;
	}
	return (max_index);
}

void	medium_push_back(char *argv[], t_list **a_list, t_list **b_list,
		t_count *count)
{
	int	index_max;

	while (*b_list)
	{
		index_max = max_index(b_list);
		if ((*b_list)->index == index_max)
			pa(argv, a_list, b_list, count);
		else
			rb(argv, b_list, count);
	}
	free(b_list);
}

void	bucket_sort(char *argv[], t_list **a_list, t_count *count)
{
	t_list	**b_list;
	int		bucket_size;
	int		size;
	int		nb_values;
	int		bucket_max;

	b_list = malloc(sizeof(t_list *));
	*b_list = NULL;
	size = ft_lstsize((*a_list));
	nb_values = 0;
	bucket_size = square_root(size);
	bucket_max = bucket_size;
	while (nb_values < size)
	{
		if ((*a_list)->index < bucket_size)
		{
			pb(argv, a_list, b_list, count);
			nb_values++;
		}
		else
			ra(argv, a_list, count);
		if (bucket_size <= nb_values && nb_values < size)
			bucket_size += bucket_max;
	}
	medium_push_back(argv, a_list, b_list, count);
}
