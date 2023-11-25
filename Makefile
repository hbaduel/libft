# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbaduel <hbaduel@student.42perpignan.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 16:37:32 by hbaduel           #+#    #+#              #
#    Updated: 2023/11/25 11:09:25 by hbaduel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/ft_isalpha.c src/ft_isdigit.c src/ft_isalnum.c src/ft_isascii.c src/ft_isprint.c \
src/ft_strlen.c src/ft_memset.c src/ft_bzero.c src/ft_memcpy.c src/ft_memmove.c src/ft_strlcpy.c \
src/ft_strlcat.c src/ft_toupper.c src/ft_tolower.c src/ft_strchr.c src/ft_calloc.c src/ft_strdup.c \
src/ft_strrchr.c src/ft_strncmp.c src/ft_memchr.c src/ft_memcmp.c src/ft_strnstr.c src/ft_atoi.c \
src/ft_putchar_fd.c src/ft_putstr_fd.c src/ft_putendl_fd.c src/ft_putnbr_fd.c src/ft_strmapi.c \
src/ft_strjoin.c src/ft_strtrim.c src/ft_striteri.c src/ft_substr.c src/ft_split.c src/ft_itoa.c

OBJS = ${SRCS:.c=.o}

BONUS = src_bonus/ft_lstadd_back.c src_bonus/ft_lstadd_front.c src_bonus/ft_lstclear.c \
src_bonus/ft_lstdelone.c src_bonus/ft_lstiter.c src_bonus/ft_lstlast.c src_bonus/ft_lstmap.c \
src_bonus/ft_lstnew.c src_bonus/ft_lstsize.c

BONUS_OBJS = ${BONUS:.c=.o}

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

all: ${NAME}

$(NAME): ${OBJS}
		ar rc ${NAME} ${OBJS}

clean:
	${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean $(NAME)

bonus: ${BONUS_OBJS}
	ar rcs ${NAME} ${BONUS_OBJS}

.phony: all clean fclean re
