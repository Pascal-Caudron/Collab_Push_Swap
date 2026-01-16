/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_select.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:45:04 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/16 16:44:18 by brouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_radix(char *argv[], t_list **a_list, t_count *count)
{
	if (sorted(a_list) == 0)
	{
		exit(2);
		free_list(a_list);
	}
	radix_sort(argv, a_list, count);
}

void	complex_sort(char *argv[], t_list **a_list, t_count *count)
{
	int	size;

	size = ft_lstsize(*a_list);
	if (size == 3)
		sort3(argv, a_list, count);
	else
		init_radix(argv, a_list, count);
}

void	medium_sort(char *argv[], t_list **a_list, t_count *count)
{
	int	size;

	if (sorted(a_list) == 0)
		exit(2);
	size = ft_lstsize(*a_list);
	if (size == 3)
		sort3(argv, a_list, count);
	else
		bucket_sort(argv, a_list, count);
}

void	adaptive(char *argv[], t_list **list, t_count *count)
{
	float	dis;

	dis = disorder(list);
	if (dis < 0.2)
		simple_sort(argv, list, count);
	else if (dis >= 0.2 && dis < 0.5)
		medium_sort(argv, list, count);
	else if (dis >= 0.5)
		complex_sort(argv, list, count);
}

void	strat_select(char *argv[], t_list **list, t_count *count)
{
	t_flag	flag;
	t_flag	isbench;

	isbench = arg_error(argv);
	if (isbench == BENCH)
		flag = second_flag(argv, list);
	else
		flag = arg_error(argv);
	if (flag == ADAPTIVE || flag == NO_FLAG)
		adaptive(argv, list, count);
	else if (flag == SIMPLE)
		simple_sort(argv, list, count);
	else if (flag == MEDIUM)
		medium_sort(argv, list, count);
	else if (flag == COMPLEX)
		complex_sort(argv, list, count);
}
