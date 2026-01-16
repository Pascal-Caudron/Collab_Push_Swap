/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:03:01 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/16 15:24:41 by brouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = content;
	node->next = NULL;
	return (node);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *node)
{
	if (lst != NULL)
	{
		if (*lst != NULL)
			ft_lstlast(*lst)->next = node;
		else
			*lst = node;
	}
}

int	ft_atoi(const char *nptr, t_list **a_list)
{
	size_t	index;
	int		sign;
	long	power;

	index = 0;
	sign = 1;
	power = 0;
	while ((nptr[index] >= '\t' && nptr[index] <= '\r') || (nptr[index] == ' '))
		index++;
	if (nptr[index] == '+' || nptr[index] == '-')
	{
		if (nptr[index] == '-')
			sign = -sign;
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		power = (power * 10) + (nptr[index++] - '0');
	}
	if (power * sign > INT_MAX || power * sign < INT_MIN)
		error_arg(a_list);
	return (power * sign);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*t1;
	const unsigned char	*t2;

	if (!s1 || !s2)
		return (0);
	t1 = (const unsigned char *)s1;
	t2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*t1 != *t2)
			return (*t1 - *t2);
		t1++;
		t2++;
	}
	return (0);
}
