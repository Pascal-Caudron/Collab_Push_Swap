/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:02:40 by brouzaud          #+#    #+#             */
/*   Updated: 2025/12/22 09:08:00 by brouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **list)
{
	int		tmp;
	t_list	*head;

	if (!(*list)->data || !(*list)->next->data)
		return ;
	head = (*list);
	tmp = (*list)->data;
	(*list)->data = (*list)->next->data;
	(*list)->next->data = tmp;
	(*list) = head;
	return ;
}
