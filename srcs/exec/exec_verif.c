/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_verif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:50:47 by thomathi          #+#    #+#             */
/*   Updated: 2022/09/28 18:51:08 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exec_verif(t_cmdlst *lst)
{
	if (ft_strcmp(lst->command, "<<") == 0)
	{
		if (lst->command == NULL)
			return ;
		lst->command = lst->args[0];
	}
	return ;
}
