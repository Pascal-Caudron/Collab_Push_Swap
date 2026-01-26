/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:02:43 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/26 17:41:14 by brouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_isdigit(char *c)
{
	int	index;

	index = 0;
	if (!c[index])
		return (index);
	if (c[index] == '-')
	{
		index++;
	}
	while (c[index])
	{
		if (c[index] < '0' || c[index] > '9')
			return (0);
		index++;
	}
	return (1);
}

void	error_arg(t_list **a_list)
{
	// t_free not_free;
	write(2, "Error\n", 7);
	free_list(a_list);
	// not_free = FREE;
	exit(2);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*pointer;
	size_t	total;
	size_t	index;

	index = 0;
	total = nmemb * size;
	if (nmemb > __SIZE_MAX__ / size)
		return (NULL);
	pointer = (char *)malloc(total * sizeof(char));
	if (!pointer)
		return (NULL);
	if (pointer == 0)
		return (0);
	while (index < total)
	{
		pointer[index] = '\0';
		index++;
	}
	return ((void *)pointer);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (dst == NULL || src == NULL)
		return (0);
	if (size == 0)
	{
		while (src[len])
		{
			len++;
		}
		return (len);
	}
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
