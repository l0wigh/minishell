/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugrene <hugrene@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:33:10 by hugrene           #+#    #+#             */
/*   Updated: 2022/10/04 20:55:31 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	in_quotes is a var that is equal to 1 when a single quote is openned,
	2 if a double quote is openned or 0 when quotes are closed.
	The function set given in_quotes to 0, 1 or 2 depending on the
	value of given char and the current in_quotes value.
	Return the previous value of in_quotes
*/
int	set_in_quotes(char c, int *in_quotes)
{
	int	cquotes;

	cquotes = *in_quotes;
	if (c == '\'')
	{
		if (cquotes == 0)
			*in_quotes = 1;
		else if (cquotes == 1)
			*in_quotes = 0;
	}
	if (c == '"')
	{
		if (cquotes == 0)
			*in_quotes = 2;
		else if (cquotes == 2)
			*in_quotes = 0;
	}
	return (cquotes);
}

/*
	Calulate and return the len of the given arg when
	it's values (env vars) will be replaced.
	Return -1 on malloc error
*/
int	get_future_arg_len(char *arg, char **env, int last_exit)
{
	int		cur;
	int		in_quotes;
	int		future_len;
	char	*var_val;

	cur = 0;
	in_quotes = 0;
	future_len = 0;
	while (arg[cur])
	{
		if (set_in_quotes(arg[cur], &in_quotes) == in_quotes)
			future_len++;
		if (in_quotes != 1 && arg[cur] == '$')
		{
			var_val = get_env(arg + cur, env, last_exit);
			if (!var_val)
				return (-1);
			future_len += ft_strlen(var_val) - 1;
			free(var_val);
			cur += get_envvar_size(arg + cur) - 1;
		}
		cur++;
	}
	return (future_len);
}

/*
	lex stand for last exit
	Return NULL on malloc error
*/
char	*malloc_new_arg(char *arg, char **env, int lex)
{
	char	*n_arg;
	int		future_len;

	future_len = get_future_arg_len(arg, env, lex);
	if (future_len == -1)
		return (NULL);
	n_arg = ft_calloc(future_len + 1, sizeof(char));
	if (!n_arg)
		return (NULL);
	return (n_arg);
}

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

/*
	Replace the env vars of the given arg and return the
	modified arg.
	lex stand for last exit
	Return NULL on malloc error
*/

char	*replace_in_arg(char *arg, char **env, int lex)
{
	char	*n_arg;
	int		cur;
	int		in_quotes;
	int		n_cur;
	char	*var_val;

	n_arg = malloc_new_arg(arg, env, lex);
	arg = check_double_dollar(arg);
	if (!n_arg)
		return (NULL);
	cur = -1;
	n_cur = 0;
	in_quotes = 0;
	while (arg[++cur])
	{
		if (set_in_quotes(arg[cur], &in_quotes) == in_quotes)
			n_arg[n_cur++] = arg[cur];
		if (in_quotes != 1 && arg[cur] == '$')
		{
			var_val = get_env(arg + cur, env, lex);
			if (!replace_var(var_val, n_arg, &n_cur))
				return (NULL);
			cur += get_envvar_size(arg + cur) - 1;
		}
	}
	return (n_arg);
}

/*
	Replace the env vars of every args in given array using replace_in_arg.
	It malloc a whole new array and duplicate every args (and replace env vars
	when needed), then it free the old arg array and set the args pointer
	to the new array.
	Return 0 on malloc error
*/

int	replace_quotes(char ***args, char **env, int lex)
{
	char	**n_args;
	int		i;

	n_args = ft_calloc(strarr_len(*args) + 1, sizeof(char *));
	if (!n_args)
		return (0);
	i = -1;
	while ((*args)[++i])
	{
		n_args[i] = replace_in_arg((*args)[i], env, lex);
		if (!n_args[i])
			return (0);
	}
	strarr_free(*args);
	*args = n_args;
	return (1);
}
