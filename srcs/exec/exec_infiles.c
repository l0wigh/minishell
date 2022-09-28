/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_infiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugrene <hugrene@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:51:27 by hugrene           #+#    #+#             */
/*   Updated: 2022/09/28 18:29:08 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	if there is a << in command
	open a tmpfile
	new prompt, write buf in it
*/

void	handle_heredocs(t_mem *mem, t_cmdlst *lst)
{
	int		fd;
	char	*buf;

	fd = open(mem->tmpfile, O_TRUNC | O_CREAT | O_WRONLY, 0777);
	if (fd == -1)
		return ;
	buf = readline("📄 >> ");
	while (1)
	{
		if (!buf)
			break ;
		if (ft_strcmp(buf, lst->heredocs[0]) == 0)
			break ;
		write(fd, buf, ft_strlen(buf));
		write(fd, "\n", 1);
		buf = readline("📄 >> ");
	}
	if (buf)
		free(buf);
	close(fd);
	mem->exec_loop->fdin = open(mem->tmpfile, O_RDONLY, 0777);
	dup2(mem->exec_loop->fdin, STDIN_FILENO);
	close(mem->exec_loop->fdin);
}

/*
	set up infiles (< et <<)
*/

void	setup_infiles(t_cmdlst *lst, t_mem *mem)
{
	if (lst->infiles)
		mem->exec_loop->fdin = open(lst->infiles[0], O_RDONLY);
	if (lst->heredocs)
	{
		reset_exec(mem);
		init_exec(mem, lst);
		handle_heredocs(mem, lst);
	}
}

/*
	if there was a << in command
	delete tmpfile
*/

void	delete_tpmfile(t_mem *mem)
{
	char	**argv;
	pid_t	pid;

	argv = malloc(sizeof(char *) * 3);
	argv[0] = "/bin/rm";
	argv[1] = mem->tmpfile;
	argv[2] = NULL;
	pid = fork();
	if (pid == 0)
		execve("/bin/rm", argv, NULL);
}
