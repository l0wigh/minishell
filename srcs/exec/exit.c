/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugrene <hugrene@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:31:08 by hugrene           #+#    #+#             */
/*   Updated: 2022/09/22 18:33:05 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int		ft_exit_getstatus(char *arg)
{
	int exit_status;
	int i;
	char **tmp;

	exit_status = 0;
	i = -1;
	tmp = ft_split(arg, '"');
	while (tmp[0][++i])
	{
		if (!ft_isdigit(tmp[0][i]))
		{
			ft_putstr_fd("exit\n", 2);
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(tmp[0], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			exit_status = 255;
			free(tmp);
			return (exit_status);
		}
	}
	exit_status = ft_atoi(tmp[0]);
	free(tmp);
	return (exit_status);
}

void	ft_exit(t_mem *mem, t_cmdlst *lst)
{
	int		i;
	int		x;
	int		exit_status;
	char	**split;

	i = -1;
	x = -1;
	exit_status = 0;
	if (lst->args[1])
	{
		split = ft_split(lst->args[1], ' ');
		while (split[++i]);
	}
	while (lst->args[++x]);
	if (i >= 2 || x > 2)
		write(1, "exit: too many arguments\n", 25);
	else
	{
		if (lst->args[1])
			exit_status = ft_exit_getstatus(lst->args[1]);
		cmdlst_clear(&lst);
		exit(free_mem(mem, exit_status));
	}
}
