/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:03:06 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/26 17:39:14 by brouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	**list;
	t_count	*count;
	t_dis	*init_dis;
	t_free not_free;

	list = malloc(sizeof(t_list *));
	count = malloc(sizeof(t_count));
	if (!count)
		return (0);
	init_dis = malloc(sizeof(t_dis));
	if (!init_dis)
		return (0);
	*list = NULL;
	not_free = parsing(argc, argv, list);
	free_malloc_main(list, count, init_dis, not_free);
	init_count(count);
	init_disorder(list, init_dis);
	strat_select(argv, list, count);
	if (arg_error(argv) == COUNT_ONLY)
		ft_printf("%d\n", count_ops(count));
	bench(argv, count, init_dis, list);
	free(count);
	free(init_dis);
	free_list(list);
	free(list);
	return (0);
}
