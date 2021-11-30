# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/24 10:58:50 by dmercadi          #+#    #+#              #
#    Updated: 2021/03/24 16:07:34 by dmercadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_char.c ft_mem.c ft_mem2.c ft_put.c ft_split.c ft_str.c ft_str2.c ft_str3.c ft_strtrim.c ft_tomutate.c

BONUS_SRCS = ft_lst1_bonus.c ft_lst2_bonus.c

OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

FLAGS = -Wall -Werror -Wextra

CC = gcc

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} ${BONUS_OBJS}
	ar rc ${NAME} ${BONUS_OBJS} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS} ${BONUS_OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean ${NAME}

bonus: ${OBJS} ${BONUS_OBJS}
	ar rc ${NAME} ${BONUS_OBJS} ${OBJS}

.PHONY: all clean fclean re
