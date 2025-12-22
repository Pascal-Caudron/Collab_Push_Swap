/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:02:37 by brouzaud          #+#    #+#             */
/*   Updated: 2025/12/22 09:07:59 by brouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	length;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (start > length)
		return (ft_calloc(1, 1));
	if (len > ft_strlen(s + start))
	{
		len = ft_strlen(s + start);
	}
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	sub[len] = '\0';
	return (sub);
}

size_t	len_split(char const *s, char c)
{
	size_t	count;
	int		isword;

	count = 0;
	isword = 0;
	while (*s)
	{
		if (*s != c && !isword)
		{
			isword = 1;
			count++;
		}
		else if (*s == c)
		{
			isword = 0;
		}
		s++;
	}
	return (count);
}

char	**free_split(char **split_s, size_t count)
{
	while (count--)
		free(split_s[count]);
	free(split_s);
	return (NULL);
}

char	**delim_split(char const *s, char **split_s, char c)
{
	size_t	index;
	size_t	s_index;
	size_t	delim;

	s_index = 0;
	index = 0;
	while (s[index])
	{
		if (s[index] != c)
		{
			delim = index;
			while (s[index] != c && s[index])
				index++;
			split_s[s_index] = ft_substr(s, delim, index - delim);
			if (!split_s[s_index])
				return (free_split(split_s, s_index));
			s_index++;
		}
		else
			index++;
	}
	split_s[s_index] = NULL;
	return (split_s);
}

char	**ft_split(char const *s, char c)
{
	char	**split_s;
	size_t	s_index;

	if (!s)
		return (NULL);
	s_index = 0;
	s_index = len_split(s, c);
	split_s = malloc((s_index + 1) * sizeof(char *));
	if (!split_s)
		return (NULL);
	split_s = delim_split(s, split_s, c);
	return (split_s);
}
