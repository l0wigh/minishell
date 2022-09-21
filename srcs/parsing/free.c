/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugrene <hugrene@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:32:27 by hugrene           #+#    #+#             */
/*   Updated: 2022/09/12 14:15:03 by hugrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	Free a command list
*/
int	cmdlst_clear(t_cmdlst **lst)
{
	t_cmdlst	*next;

	while (*lst)
	{
		next = (*lst)->next;
		free((*lst)->command);
		strarr_free((*lst)->args);
		outlst_clear(&(*lst)->outfiles);
		strarr_free((*lst)->infiles);
		strarr_free((*lst)->heredocs);
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
	return (0);
}

/*
	Free an outlist (mostly used by cmdlst_clear)
*/
int	outlst_clear(t_outlst **lst)
{
	t_outlst	*next;

	while (*lst)
	{
		next = (*lst)->next;
		free((*lst)->filename);
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
	return (0);
}

/*
	Free only the n-first elements of an str array
*/
int	free_array_n(char **array, int n)
{
	while (n--)
		free(array[n]);
	free(array);
	return (0);
}

/*
	Free a t_list
*/
int	lst_clear(t_list **lst)
{
	t_list	*next;

	while (*lst)
	{
		next = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
	return (0);
}

/*
	Free an str array
*/
int	strarr_free(char **array)
{
	int	cur;

	cur = -1;
	if (array)
	{
		while (array[++cur])
			free(array[cur]);
		free(array);
	}
	return (0);
}
