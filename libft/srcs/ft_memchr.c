/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugrene <hugrene@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:23:43 by hugrene           #+#    #+#             */
/*   Updated: 2022/09/08 17:23:44 by hugrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				cur;
	unsigned char const	*data;

	cur = 0;
	data = (unsigned char const *)s;
	while (cur < n)
	{
		if (data[cur] == (unsigned char)c)
			return ((void *)(data + cur));
		cur++;
	}
	return (NULL);
}
