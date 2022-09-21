/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugrene <hugrene@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:31:08 by hugrene           #+#    #+#             */
/*   Updated: 2022/09/21 18:03:39 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exit(t_mem *mem, t_cmdlst *lst)
{
	int		i;
	int		x;
	char	**split;

	i = 0;
	x = 0;
	if (lst->args[1])
	{
		split = ft_split(lst->args[1], ' ');
		while (split[i])
			i++;
	}
	while (lst->args[x])
		x++;
	free(split);
	if (i >= 2 || x > 2)
	{
		write(1, "exit: too many arguments\n", 25);
		return ;
	}
	else
	{
		cmdlst_clear(&lst);
		exit(free_mem(mem));
	}
}
