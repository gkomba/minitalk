# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gildo <gildo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/23 20:21:07 by gkomba            #+#    #+#              #
#    Updated: 2024/07/27 19:16:32 by gkomba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
SRCS_CLIENT = client.c\
	      utils_client.c\

SRCS_SERVER = server.c\
	     utils_server.c\

MAKEFLAGS += -silent

CLIENT_OBJS = ${SRCS_CLIENT:.c=.o}
SERVER_OBJS = ${SRCS_SERVER:.c=.o}
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
PRINTF = ft_printf
LIBFT = libft

all: ${CLIENT} ${SERVER}


${CLIENT}: ${CLIENT_OBJS}
	@make -s -C ${PRINTF}
	@make -s -C ${LIBFT}
	@${CC} ${CFLAGS} -o ${CLIENT} ${CLIENT_OBJS} ${LIBFT}/libft.a ${PRINTF}/libftprintf.a
	@echo "\033[0;32mCLIENT OK!\033[0m"
	@make clean

${SERVER}: ${SERVER_OBJS}
	@make -s -C ${PRINTF}
	@make -s -C ${LIBFT}
	@${CC} ${CFLAGS} -o ${SERVER} ${SERVER_OBJS} ${LIBFT}/libft.a ${PRINTF}/libftprintf.a
	@echo "\033[0;32mSERVER OK!\033[0m"
	@make clean

norm:
	norminette
	norminette -R CheckForbiddenSourceHeader

git: fclean
	git status
	git add .
	git status
	git commit -m "UPDATED"
	git push

clean:
	@make clean -s -C ${PRINTF}
	@make clean -s -C ${LIBFT}
	@${RM} ${CLIENT_OBJS} ${SERVER_OBJS}

fclean: clean
	@make fclean -s -C ${PRINTF}
	@make fclean -s -C ${LIBFT}
	@${RM} ${CLIENT} ${SERVER}

re: fclean all

.PHONY: all clean fclean re
