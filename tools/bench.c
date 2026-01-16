/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:44:52 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/16 18:24:35 by brouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	strategy(char *argv[], t_list **a_list)
{
	t_flag	flag;
	t_flag	isbench;

	isbench = arg_error(argv);
	if (isbench == BENCH)
		flag = second_flag(argv, a_list);
	else
		flag = arg_error(argv);
	if (flag == ADAPTIVE)
		ft_printf("[bench] strategy:  Adaptive / O(n√n)\n");
	if (flag == SIMPLE)
		ft_printf("[bench] strategy: Simple / O(n2)\n");
	if (flag == COMPLEX)
		ft_printf("[bench] strategy: Complex / O(n log n)\n");
	if (flag == MEDIUM)
		ft_printf("[bench] strategy: Medium / O(n√n)\n");
	return ;
}

int	count_ops(t_count *count)
{
	count->total_count = (count->ra_count + count->rb_count + count->rr_count
			+ count->sa_count + count->sb_count + count->ss_count
			+ count->rra_count + count->rrb_count + count->rrr_count
			+ count->pb_count + count->pa_count);
	return (count->total_count);
}

void	bench(char *argv[], t_count *count, t_dis *init_dis, t_list **a_list)
{
	t_flag	flag;

	flag = arg_error(argv);
	if (flag == BENCH)
	{
		ft_printf("[bench] disorder: %f%%\n", init_dis->dis * 100);
		strategy(argv, a_list);
		ft_printf("[bench] total_ops: %d\n", count_ops(count));
		ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
			count->sa_count, count->sb_count, count->ss_count, count->pa_count,
			count->pb_count);
		ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
			count->ra_count, count->rb_count, count->rr_count, count->rra_count,
			count->rrb_count, count->rrr_count);
	}
}
