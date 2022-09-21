/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugrene <hugrene@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:32:41 by hugrene           #+#    #+#             */
/*   Updated: 2022/09/12 14:14:54 by hugrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	Create a new lst element with the given str
	and append it at the end of the given list
	Return 0 on malloc error
*/
int	lst_append(t_list **lst, char *str)
{
	t_list	*new;

	new = ft_lstnew(str);
	if (!new)
		return (lst_clear(&new));
	ft_lstadd_back(lst, new);
	return (1);
}

/*
	Return the len of an str array (that is 0-terminated)
*/
int	strarr_len(char **array)
{
	int	cur;

	cur = 0;
	if (array)
		while (array[cur])
			cur++;
	return (cur);
}

/*
	Append the given str to the end of the given array
	It malloc an entire new array, duplicates the existing elements
	and duplicate the given string. Then it free the original
	array and replace it's pointer to the new array's one
	Return 0 on malloc error
*/
int	strarr_append(char ***array, char *str)
{
	char	**new;
	int		new_len;
	int		cur;

	new_len = strarr_len(*array) + 1;
	new = malloc(sizeof(char *) * (new_len + 1));
	if (!new)
		return (0);
	cur = 0;
	while ((*array) && (*array)[cur])
	{
		new[cur] = ft_strdup((*array)[cur]);
		if (!new[cur])
			return (free_array_n(new, cur));
		cur++;
	}
	new[cur] = ft_strdup(str);
	if (!new[cur])
		return (free_array_n(new, cur));
	cur++;
	new[cur] = 0;
	strarr_free(*array);
	*array = new;
	return (1);
}
