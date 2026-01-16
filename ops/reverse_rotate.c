/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:02:53 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/16 18:32:05 by brouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(char *argv[], t_list **list, t_count *count)
{
	t_list	*end;
	t_list	*head;
	t_list	*tmp;
	t_list	*node;

	if (!*list || !(*list)->next)
		return ;
	head = *list;
	tmp = head;
	while (tmp->next)
	{
		node = tmp;
		tmp = tmp->next;
	}
	end = tmp;
	if (!end)
		return ;
	node->next = NULL;
	(*list) = end;
	end->next = head;
	count->rra_count++;
	if (arg_error(argv) == BENCH)
		return ;
	else
		write(1, "rra\n", 4);
}

void	rrb(char *argv[], t_list **list, t_count *count)
{
	t_list	*end;
	t_list	*head;
	t_list	*tmp;
	t_list	*node;

	if (!*list || !(*list)->next)
		return ;
	head = *list;
	tmp = head;
	while (tmp->next)
	{
		node = tmp;
		tmp = tmp->next;
	}
	end = tmp;
	if (!end)
		return ;
	node->next = NULL;
	(*list) = end;
	end->next = head;
	count->rrb_count++;
	if (arg_error(argv) == BENCH)
		return ;
	else
		write(1, "rrb\n", 4);
}
