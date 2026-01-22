/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:56:30 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/22 15:18:51 by brouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	min_index(t_list **list)
{
	int		min;
	int		count;
	int		pos;
	t_list	*tmp;

	tmp = (*list)->next;
	min = (*list)->data;
	pos = 0;
	count = 1;
	while (tmp)
	{
		if (tmp->data < min)
		{
			min = tmp->data;
			pos = count;
		}
		tmp = tmp->next;
		count++;
	}
	return (pos);
}
