/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:44:41 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/16 14:49:16 by brouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(char *argv[], t_list **a, t_list **b, t_count *count)
{
	t_list	*tmp;

	if (!a || !*a)
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = *b;
	(*b) = tmp;
	count->pb_count++;
	if (arg_error(argv) == BENCH)
		return ;
	else
		write(1, "pb\n", 3);
}

void	pa(char *argv[], t_list **a, t_list **b, t_count *count)
{
	t_list	*tmp;

	if (!b || !*b)
		return ;
	tmp = (*b);
	(*b) = (*b)->next;
	tmp->next = *a;
	(*a) = tmp;
	count->pa_count++;
	if (arg_error(argv) == BENCH)
		return ;
	else
		write(1, "pa\n", 3);
}
