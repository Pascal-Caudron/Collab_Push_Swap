/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:02:58 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/26 17:42:01 by brouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	flag_count(char *argv[], int arg_index, t_list **a_list)
{
	t_flag	flag;

	flag = NO_FLAG;
	if (ft_strncmp(argv[1], "--bench", 7) == 0)
	{
		flag = BENCH;
		arg_index++;
	}
	if (flag == BENCH)
	{
		if (ft_strncmp(argv[arg_index], "--adaptive", 11) == 0
			|| ft_strncmp(argv[arg_index], "--count_only", 13) == 0)
			arg_index++;
		if (ft_strncmp(argv[arg_index], "--simple", 9) == 0)
			arg_index++;
		if (ft_strncmp(argv[arg_index], "--medium", 9) == 0)
			arg_index++;
		if (ft_strncmp(argv[arg_index], "--complex", 10) == 0)
			arg_index++;
		if (ft_strncmp(argv[arg_index], "--bench", 8) == 0)
			error_arg(a_list);
	}
	else
		arg_index++;
	return (arg_index);
}

t_flag	arg_error(char *argv[])
{
	t_flag	isflag;

	isflag = NO_FLAG;
	if (ft_strncmp(argv[1], "--adaptive", 11) == 0)
		isflag = ADAPTIVE;
	if (ft_strncmp(argv[1], "--simple", 9) == 0)
		isflag = SIMPLE;
	if (ft_strncmp(argv[1], "--medium", 9) == 0)
		isflag = MEDIUM;
	if (ft_strncmp(argv[1], "--complex", 10) == 0)
		isflag = COMPLEX;
	if (ft_strncmp(argv[1], "--bench", 8) == 0)
		isflag = BENCH;
	if (ft_strncmp(argv[1], "--count_only", 13) == 0)
		isflag = COUNT_ONLY;
	return (isflag);
}

void	parsing_str(int argc, char *argv[], t_list **a, int num)
{
	int		arg_index;
	size_t	index;
	char	**str;
	t_list	*new;

	arg_index = 1;
	if (arg_error(argv))
		arg_index = flag_count(argv, arg_index, a);
	while (arg_index < argc)
	{
		index = 0;
		str = ft_split(argv[arg_index], ' ');
		while (str && str[index])
		{
			if (!ft_isdigit(str[index]))
				error_arg(a);
			num = ft_atoi(str[index], a);
			new = ft_lstnew(num);
			ft_lstadd_back(a, new);
			index++;
		}
		free_split(str, index);
		arg_index++;
	}
}

int	duplicate_parsing(t_list **list)
{
	t_list	*lst;
	t_list	*nxt;

	lst = (*list);
	while (lst)
	{
		nxt = lst->next;
		while (nxt)
		{
			if (lst->data == nxt->data)
			{
				return (0);
			}
			nxt = nxt->next;
		}
		lst = lst->next;
	}
	return (1);
}

t_free	parsing(int argc, char *argv[], t_list **a)
{
	int		num;
	t_free	not_free;

	num = 0;
	not_free = NO_FREE;
	if (argc <= 2)
	{
		not_free = FREE;
		return (not_free);
	}
	parsing_str(argc, argv, a, num);
	if (duplicate_parsing(a) == 0)
		error_arg(a);
	if (sorted(a) == 0)
	{
		free_list(a);
		not_free = FREE;
		return (not_free);
	}
	return (not_free);
}
