/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugrene <hugrene@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:34:09 by hugrene           #+#    #+#             */
/*   Updated: 2022/09/08 16:34:10 by hugrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# define GNL_CLEAR 1
# define GNL_KEEP 0

typedef struct s_prev_list
{
	char				*prev;
	int					fd;
	struct s_prev_list	*next;
}	t_prev_list;

long	charchr(const char *s, char c);
char	*gnl_strjoin(char *s1, char const *s2);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
void	shiftstr(char **str, size_t start);
#endif
