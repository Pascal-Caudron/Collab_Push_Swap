/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:02:49 by brouzaud          #+#    #+#             */
/*   Updated: 2025/12/22 09:07:55 by brouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **list)
{
	int		tmp;
	t_list	*lst;

	lst = (*list);
	while ((lst) && (lst)->next)
	{
		tmp = (lst)->data;
		(lst)->data = (lst)->next->data;
		(lst)->next->data = tmp;
		(lst) = (lst)->next;
	}
}
