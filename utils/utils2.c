/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:45:27 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/16 15:27:20 by brouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_flag	second_flag(char *argv[], t_list **a_list)
{
	t_flag	flag;
	t_flag	bench_flag;

	bench_flag = arg_error(argv);
	if (bench_flag == BENCH)
	{
		flag = NO_FLAG;
		if (ft_strncmp(argv[2], "--adaptive", 10) == 0)
			flag = ADAPTIVE;
		if (ft_strncmp(argv[2], "--simple", 8) == 0)
			flag = SIMPLE;
		if (ft_strncmp(argv[2], "--medium", 8) == 0)
			flag = MEDIUM;
		if (ft_strncmp(argv[2], "--complex", 9) == 0)
			flag = COMPLEX;
		if (ft_strncmp(argv[2], "--bench", 7) == 0)
			error_arg(a_list);
	}
	return (flag);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}

void	init_count(t_count *count)
{
	count->sa_count = 0;
	count->ra_count = 0;
	count->rra_count = 0;
	count->rrr_count = 0;
	count->rb_count = 0;
	count->rr_count = 0;
	count->pb_count = 0;
	count->pa_count = 0;
	count->sb_count = 0;
	count->ss_count = 0;
	count->rrb_count = 0;
	count->total_count = 0;
}

int	ft_lstsize(t_list *lst)
{
	int	index;

	index = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		index++;
	}
	return (index);
}

int	sorted(t_list **list)
{
	t_list	*tmp;

	tmp = (*list);
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
		{
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
