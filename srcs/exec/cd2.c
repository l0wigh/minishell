/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugrene <hugrene@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:54:00 by hugrene           #+#    #+#             */
/*   Updated: 2022/10/06 20:28:29 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**change_pwd(char **temp2, char **my_env)
{
	int		pwd_place;
	char	*new_pwd;
	char	**temp;
	int		i;

	i = 0;
	pwd_place = my_env_index_elem(my_env, "PWD");
	temp = (char **)malloc(sizeof(char *) * (tab_2d_len(my_env) + 1));
	if (!temp)
		return (NULL);
	pwd_place = my_env_index_elem(my_env, "PWD");
	new_pwd = concat_path(temp2, "PWD=");
	while (my_env[i])
	{
		if (i == pwd_place)
			temp[i] = ft_strdup(new_pwd);
		else
			temp[i] = ft_strdup(my_env[i]);
		i++;
	}
	temp[i] = NULL;
	free_tab_2d(my_env);
	free(new_pwd);
	return (temp);
}

char	**change_pwd_home(char **my_env)
{
	char	*new_pwd;
	int		pwd_index;
	char	*home;

	home = my_getenv(my_env, "HOME");
	if (chdir(home) == -1)
		ft_printf("cd: no such file or directory\n");
	else
	{
		pwd_index = my_env_index_elem(my_env, "PWD");
		new_pwd = ft_strjoin("PWD=", home);
		free(my_env[pwd_index]);
		my_env[pwd_index] = ft_strdup(new_pwd);
		free(new_pwd);
	}
	free(home);
	return (my_env);
}
