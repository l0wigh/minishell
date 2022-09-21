/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugrene <hugrene@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:41:48 by hugrene           #+#    #+#             */
/*   Updated: 2022/09/08 16:41:49 by hugrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*call;
	size_t	cur;

	call = malloc(count * size);
	if (!call)
		return (0);
	cur = -1;
	while (++cur < size * count)
		call[cur] = 0;
	return (call);
}
