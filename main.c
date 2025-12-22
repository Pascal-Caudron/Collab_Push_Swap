/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:03:06 by brouzaud          #+#    #+#             */
/*   Updated: 2025/12/22 09:34:00 by brouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*tmp;
	t_list	**list;

	list = malloc(sizeof(t_list *));
	*list = NULL;
	parsing(argc, argv, list);
	tmp = (*list);
	bubble_sort(list, argc, argv);
	while (tmp)
	{
		printf("arg 1 = %d\n", tmp->data);
		tmp = tmp->next;
	}
	return (0);
}
