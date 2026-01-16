/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:44:54 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/16 19:55:55 by brouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

float	disorder(t_list **list) // voir si disorder est pb ou si autre choses (print_float)
{
	int mistakes;
	int total_args;
	float dis;
	t_list *tmp;

	tmp = (*list);
	mistakes = 0;
	total_args = ft_lstsize(tmp);
	if (sorted(list) == 0)
		mistakes = 0;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
		{
			mistakes += 1;
		}
		tmp = tmp->next;
	}
	dis = (float)mistakes / (float)total_args;
	return (dis);
}

void	init_disorder(t_list **list, t_dis *init)
{
	init->dis = disorder(list);
}
