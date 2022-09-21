/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugrene <hugrene@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:28:59 by hugrene           #+#    #+#             */
/*   Updated: 2022/09/08 17:28:59 by hugrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		cur;
	char	*ret;

	cur = 0;
	ret = 0;
	while (s[cur])
	{
		if (s[cur] == (unsigned char)c)
			ret = (char *)(s + cur);
		cur++;
	}
	if (s[cur] == (unsigned char)c)
		ret = (char *)(s + cur);
	return (ret);
}
