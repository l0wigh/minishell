# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugrene <hugrene@student.42mulhouse.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 15:59:57 by hugrene           #+#    #+#              #
#    Updated: 2022/10/06 20:42:26 by thomathi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	minishell

CC			:=	clang
# ifdef LDFLAGS
FLAGS		:=	$(LDFLAGS) -lreadline -Llibft -lft
LDFLAGS = -L /goinfre/$(USER)/.brew/Cellar/readline/8.1.2/lib/
CPPFLAGS = -I/goinfre/$(USER)/.brew/Cellar/readline/8.1.2/include
# else
# 	FLAGS		:=	-Llibft -lft -lreadline
# endif
CFLAGS		:=	-Wall -Wextra -Werror -g3
#FLAGS		+=	-g -fsanitize=address

DIR_SRCS	:=	srcs
DIR_OBJS	:=	.objs
DIR_INCS	:=	include

LST_SRCS	:=	exec/cd_utils.c \
				exec/cd2.c \
				exec/cd.c \
				exec/echo.c \
				exec/env.c \
				exec/exec.c \
				exec/exec_verif.c \
				exec/exec_utils.c \
				exec/exec_utils2.c \
				exec/exec_infiles.c \
				exec/exit.c \
				exec/export.c \
				exec/init_mem.c \
				exec/main.c \
				exec/path.c \
				exec/pwd.c \
				exec/unset.c \
				exec/utils.c \
				parsing/check.c \
				parsing/cmdlst.c \
				parsing/env.c \
				parsing/free.c \
				parsing/outfiles.c \
				parsing/lst.c \
				parsing/parsing.c \
				parsing/quotes.c \
				parsing/quotes_utils.c \
				parsing/utils.c \
				ft_utils.c \
				utils.c
LST_OBJS	:=	$(LST_SRCS:.c=.o)
LST_INCS	:=	minishell.h

SRCS		:=	$(addprefix $(DIR_SRCS)/, $(LST_SRCS))
OBJS		:=	$(addprefix $(DIR_OBJS)/, $(LST_OBJS))
INCS		:=	$(addprefix $(DIR_INCS)/, $(LST_INCS))

ERASE		:=	\033[2K\r
BLUE		:=	\033[34m
YELLOW		:=	\033[33m
GREEN		:=	\033[32m
END			:=	\033[0m

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c $(INCS) Makefile libft/libft.a
	mkdir -p $(DIR_OBJS) $(DIR_OBJS)/parsing $(DIR_OBJS)/exec
# ifdef CPPFLAGS
	$(CC) -I $(DIR_INCS) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
# else
# 	$(CC) -I $(DIR_INCS) $(CFLAGS) -c $< -o $@
# endif
	printf "$(ERASE)$(BLUE) > Compilation :$(END) $<"

all:		libft $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) $(FLAGS) $(CFLAGS) $(LDFLAGS) -o $@
	printf "$(ERASE)$(GREEN)$@ made\n$(END)"

libft:
	make -C libft

clean:
	printf "$(YELLOW)$(DIR_OBJS) removed$(END)\n"
	rm -rdf $(DIR_OBJS)
	printf "libft : "
	make clean -C libft

fclean:		clean
	printf "$(YELLOW)$(NAME) removed$(END)\n"
	rm -rf $(NAME) checker
	printf "libft : "
	make fclean -C libft

re:			fclean all

.PHONY:		all libft clean fclean re
.SILENT:
