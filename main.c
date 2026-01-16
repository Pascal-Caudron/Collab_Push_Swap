/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:03:06 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/16 19:14:34 by brouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	// t_list	*tmp;
	t_list	**list;
	t_count	*count;
	t_dis	*init_dis;

	list = malloc(sizeof(t_list *));
	if (!list)
		return (0);
	count = malloc(sizeof(t_count));
	if (!count)
		return (0);
	init_dis = malloc(sizeof(t_dis));
	if (!init_dis)
		return (0);
	*list = NULL;
	parsing(argc, argv, list);
	init_count(count);
	init_disorder(list, init_dis);
	strat_select(argv, list, count);
	bench(argv, count, init_dis, list);
	// tmp = (*list);
	// while (tmp)
	// {
	// 	printf("arg 1 = %d\n", tmp->data);
	// 	tmp = tmp->next;
	// }
	free(count);
	free(init_dis);
	free_list(list);
	free(list);
	return (0);
}
