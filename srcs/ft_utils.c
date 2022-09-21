/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugrene <hugrene@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:29:49 by hugrene           #+#    #+#             */
/*   Updated: 2022/09/12 14:15:51 by hugrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
	Return 0 when the whole s1 is the same as the start of s2
*/
int	strcmp_len(char *s1, char *s2)
{
	return (ft_strncmp(s1, s2, ft_strlen(s1)));
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/*
	Same as ft_strlcat but without the l
*/
int	ft_strcat(char *dst, char *src)
{
	int	cur;

	cur = 0;
	while (src[cur])
	{
		dst[cur] = src[cur];
		cur++;
	}
	return (cur);
}

/*
	Same as ft_strdup, but with a size params to limit
	the length of the future string.
*/
char	*ft_strldup(const char *s1, int size)
{
	int		s1_len;
	char	*dup;

	s1_len = ft_strlen(s1);
	if (s1_len > size)
		s1_len = size;
	dup = (char *)malloc((s1_len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	dup[s1_len] = 0;
	while (--s1_len >= 0)
		dup[s1_len] = s1[s1_len];
	return (dup);
}
