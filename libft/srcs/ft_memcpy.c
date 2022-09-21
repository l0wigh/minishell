/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugrene <hugrene@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:36:33 by hugrene           #+#    #+#             */
/*   Updated: 2022/09/08 16:36:35 by hugrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	cur;
	char	*dst_data;
	char	*src_data;

	if (!src && !dst)
		return (NULL);
	cur = 0;
	dst_data = (char *)dst;
	src_data = (char *)src;
	while (cur < n)
	{
		dst_data[cur] = src_data[cur];
		cur++;
	}
	return (dst_data);
}
