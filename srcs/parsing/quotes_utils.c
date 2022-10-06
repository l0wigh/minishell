/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:41:16 by thomathi          #+#    #+#             */
/*   Updated: 2022/10/06 20:42:11 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*check_double_dollar(char *arg)
{
	int		i;
	int		pid_len;
	char	*new_arg;
	char	*pid;

	i = -1;
	pid_len = 0;
	if (arg[i + 1] == '$' && arg[i + 2] == '$')
	{
		pid_len = ft_strlen(ft_itoa(getpid()));
		new_arg = malloc(sizeof(char) * (ft_strlen(arg) + pid_len - 2));
		pid = ft_itoa(getpid());
		while (pid[++i])
			new_arg[i] = pid[i];
		i = 1;
		while (arg[++i])
			new_arg[i + pid_len - 2] = arg[i];
	}
	else
		return (arg);
	return (new_arg);
}
