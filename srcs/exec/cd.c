/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugrene <hugrene@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:50:28 by hugrene           #+#    #+#             */
/*   Updated: 2022/10/06 20:35:44 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <stdio.h>

char	**ft_cd_home(char **cmd, t_mem *mem)
{
	char	**new_cmd;
	int		i;

	if (cmd[1] && cmd[1][0] == '~')
	{
		i = ft_strlen(cmd[1]);
		if (i == 1)
			cmd[1] = ft_strdup(getenv("HOME"));
		else
		{
			new_cmd = ft_split(cmd[1], '/');
			cmd[1] = ft_strjoin(getenv("HOME"), "/");
			i = 0;
			while (new_cmd[++i])
			{
				cmd[1] = ft_strjoin(cmd[1], new_cmd[i]);
				cmd[1] = ft_strjoin(cmd[1], "/");
			}
		}
	}
	if (chdir(cmd[1]) == -1)
		ft_printf("cd: no such file or directory\n");
	else
		mem->my_env = change_pwd_absolute(cmd[1], mem->my_env);
	return (mem->my_env);
}

char	**change_pwd_absolute(char *path, char **my_env)
{
	int		i;
	int		pwd_index;
	char	**temp;
	char	*new_pwd;

	i = 0;
	temp = (char **)malloc(sizeof(char *) * (tab_2d_len(my_env) + 1));
	if (!temp)
		return (NULL);
	pwd_index = my_env_index_elem(my_env, "PWD");
	new_pwd = ft_strjoin("PWD=", path);
	while (my_env[i])
	{
		if (i == pwd_index)
			temp[i] = ft_strdup(new_pwd);
		else
			temp[i] = ft_strdup(my_env[i]);
		i++;
	}
	temp[i] = NULL;
	free(new_pwd);
	return (temp);
}

char	**change_pwd_relativ(char *path, char **my_env)
{
	char	**temp;
	char	**temp2;
	char	*pwd;
	int		i;

	i = 0;
	pwd = my_getenv(my_env, "PWD");
	temp = ft_split(path, '/');
	temp2 = ft_split(pwd, '/');
	while (temp[i])
	{
		if (ft_strcmp(temp[i], "..") == 0)
			temp2 = supp_last_elem_tab2d(temp2);
		else if (ft_strcmp(temp[i], ".") != 0)
			temp2 = append_tab_2d(temp2, temp[i]);
		i++;
	}
	my_env = change_pwd(temp2, my_env);
	free_tab_2d(temp);
	free_tab_2d(temp2);
	free(pwd);
	return (my_env);
}

void	ft_cd(char **cmd, t_mem *mem)
{
	char	*path;

	if (cmd[1] == NULL)
		mem->my_env = change_pwd_home(mem->my_env);
	else if (ft_strcmp(cmd[1], "/") == 0)
	{
		if (ft_strlen(cmd[1]) == 1)
			path = ft_strdup(cmd[1]);
		else
			path = ft_strjoin(path, cmd[1]);
		if (chdir(path) == -1)
			ft_printf("cd: no such file or directory\n");
		else
			mem->my_env = change_pwd_absolute(path, mem->my_env);
	}
	else if (ft_strcmp(ft_split(cmd[1], '/')[0], "~") == 0)
		mem->my_env = ft_cd_home(cmd, mem);
	else
	{
		if (chdir(cmd[1]) == -1)
			ft_printf("cd: no such file or directory\n");
		else
			mem->my_env = change_pwd_relativ(cmd[1], mem->my_env);
	}
}
