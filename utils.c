/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:02:43 by brouzaud          #+#    #+#             */
/*   Updated: 2025/12/22 09:08:02 by brouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (c[index] == '-')
	{
		index++;
	}
	if (c[index] >= 48 && c[index] <= 57)
		return (1);
	else
		return (0);
}

void	error_arg(void)
{
	write(1, &"Error\n", 6);
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
