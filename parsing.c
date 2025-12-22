/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:02:58 by brouzaud          #+#    #+#             */
/*   Updated: 2025/12/22 09:07:45 by brouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_flag	arg_error(int argc, char *argv[])
{
	t_flag	isflag;

	if (argc <= 1)
		error_arg();
	isflag = NO_FLAG;
	if (ft_strncmp(argv[1], "--adaptive", 8) == 0)
		isflag = ADAPTIVE;
	if (ft_strncmp(argv[1], "--simple", 8) == 0)
		isflag = SIMPLE;
	if (ft_strncmp(argv[1], "--medium", 8) == 0)
		isflag = MEDIUM;
	if (ft_strncmp(argv[1], "--complex", 9) == 0)
		isflag = COMPLEX;
	if (ft_strncmp(argv[1], "--bench", 7) == 0)
		isflag = BENCH;
	return (isflag);
}

void	parsing_str(int argc, char *argv[], t_list **a, int num)
{
	int		arg_index;
	int		index;
	char	**str;
	t_list	*new;
	t_flag	isflag;

	arg_index = 1;
	isflag = arg_error(argc, argv);
	if (isflag)
		arg_index++;
	while (arg_index < argc)
	{
		index = 0;
		str = ft_split(argv[arg_index], ' ');
		while (str[index])
		{
			if (ft_isdigit(str[index]) == 0)
				error_arg();
			num = ft_atoi(str[index]);
			new = ft_lstnew(num);
			ft_lstadd_back(a, new);
			index++;
		}
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

void	parsing(int argc, char *argv[], t_list **a)
{
	int	num;

	num = 0;
	parsing_str(argc, argv, a, num);
	if (duplicate_parsing(a) == 0)
		error_arg();
}
