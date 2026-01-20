/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjmrzd <bjmrzd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:56:30 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/17 17:05:35 by bjmrzd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_min(t_list **list)
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
	min = get_min(list);
	while (tmp)
	{
		if (tmp->data == min)
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (index);
}

int	get_max(t_list **list)
{
	int		max;
	t_list	*tmp;

	tmp = (*list);
	max = tmp->data;
	while (tmp)
	{
		if (tmp->data < max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}
