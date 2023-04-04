# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbelarmi <dbelarmi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 20:42:22 by dbelarmi          #+#    #+#              #
#    Updated: 2023/04/04 13:16:44 by dbelarmi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a 

SRCS	= ft_strlen.c ft_isdigit.c ft_atoi.c ft_putchar.c ft_putstr.c 

OBJS	= ${SRCS:.c=.o} 

CC 		= clang
RM		= rm -rf 

CFLAGS	= -Wall -Wextra -Werror 

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 


${NAME}:	${OBJS}
			ar -rcs ${NAME} ${OBJS}


all:		${NAME}

clean: 
			$(RM) ${OBJS}

fclean:		clean
			$(RM) ${NAME} 
			

re:			fclean all

.PHONY:		all fclean clean re
