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

NAME = minitalk
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

SRCS_CLIENT = srcs/client.c\
				srcs/utils_client.c\

SRCS_SERVER = srcs/server.c\
				srcs/utils_server.c\

SRCS_CLIENT_BONUS = bonus/client_bonus.c\
					bonus/utils_client_bonus.c\

SRCS_SERVER_BONUS = bonus/server_bonus.c\
					bonus/utils_server_bonus.c\

MAKEFLAGS += -silent

CLIENT_OBJS = ${SRCS_CLIENT:.c=.o}
SERVER_OBJS = ${SRCS_SERVER:.c=.o}
CLIENT_BONUS_OBJS = ${SRCS_CLIENT_BONUS:.c=.o}
SERVER_BONUS_OBJS = ${SRCS_SERVER_BONUS:.c=.o}
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
PRINTF = ft_printf
LIBFT = libft

all: ${NAME}
${NAME}: ${CLIENT} ${SERVER}

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

b: ${CLIENT_BONUS} ${SERVER_BONUS}

${CLIENT_BONUS}: ${CLIENT_BONUS_OBJS}
	@make -s -C ${PRINTF}
	@make -s -C ${LIBFT}
	@${CC} ${CFLAGS} -o ${CLIENT_BONUS} ${CLIENT_BONUS_OBJS} ${LIBFT}/libft.a ${PRINTF}/libftprintf.a
	@echo "\033[0;32mCLIENT_BONUS OK!\033[0m"
	@make clean_b

${SERVER_BONUS}: ${SERVER_BONUS_OBJS}
	@make -s -C ${PRINTF}
	@make -s -C ${LIBFT}
	@${CC} ${CFLAGS} -o ${SERVER_BONUS} ${SERVER_BONUS_OBJS} ${LIBFT}/libft.a ${PRINTF}/libftprintf.a
	@echo "\033[0;32mSERVER_BONUS OK!\033[0m"
	@make clean_b

norm:
	norminette
	norminette -R CheckForbiddenSourceHeader

git: fclean fclean_b
	git status
	git add .
	git status
	git commit -m "UPDATED"
	git push

clean:
	@make clean -s -C ${PRINTF}
	@make clean -s -C ${LIBFT}
	@${RM} ${CLIENT_OBJS} ${SERVER_OBJS}

clean_b:
	@make clean -s -C ${PRINTF}
	@make clean -s -C ${LIBFT}
	@${RM} ${CLIENT_BOUNS_OBJS} ${SERVER_BONUS_OBJS}

fclean: clean
	@make fclean -s -C ${PRINTF}
	@make fclean -s -C ${LIBFT}
	@${RM} ${CLIENT} ${SERVER}

fclean_b: clean_b
	@make fclean -s -C ${PRINTF}
	@make fclean -s -C ${LIBFT}
	@${RM} ${CLIENT_BONUS} ${SERVER_BONUS}

re: fclean all

re_b: fclean_b b

.PHONY: all b clean clean_b fclean fclean_b re re_b