/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugrene <hugrene@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:40:59 by hugrene           #+#    #+#             */
/*   Updated: 2022/09/08 16:40:59 by hugrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	cur;

	if (!s || !f)
		return ;
	cur = 0;
	while (s[cur])
	{
		(*f)(cur, &s[cur]);
		cur++;
	}
}
