/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:02:49 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/16 17:27:44 by brouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(char *argv[], t_list **list, t_count *count)
{
	t_list	*head;
	t_list	*tmp;
	t_list	*end;

	if (!(*list) || !(*list)->next)
		return ;
	head = (*list);
	tmp = (*list)->next;
	(*list) = (head)->next;
	end = ft_lstlast(*list);
	end->next = head;
	(*list) = tmp;
	head->next = NULL;
	count->ra_count++;
	if (arg_error(argv) == BENCH)
		return ;
	else
		write(1, "ra\n", 3);
	return ;
}

void	rb(char *argv[], t_list **list, t_count *count)
{
	t_list	*head;
	t_list	*tmp;
	t_list	*end;

	if (!(*list) || !(*list)->next)
		return ;
	head = (*list);
	tmp = (*list)->next;
	(*list) = (head)->next;
	end = ft_lstlast(*list);
	end->next = head;
	(*list) = tmp;
	head->next = NULL;
	count->rb_count++;
	if (arg_error(argv) == BENCH)
		return ;
	else
		write(1, "rb\n", 3);
	return ;
}
