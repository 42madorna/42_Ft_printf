# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/29 13:44:08 by madorna-          #+#    #+#              #
#    Updated: 2020/09/24 19:43:04 by madorna-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRCS =	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
    ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c\
    ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c\
    ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
    ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c\
    ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
    ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
    ft_putnbr_fd.c ft_putnbr_base.c

SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
	ft_lstmap.c

OBJECTS=$(SRCS:.c=.o)

OBJS_BONUS  = ${SRCS_BONUS:.c=.o}

INCLUDES=./

all: $(NAME)

$(NAME): $(SRCS) libft.h
	gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
	
bonus:	${OBJS} ${OBJS_BONUS}
		ar rcs ${NAME} ${OBJS} ${OBJS_BONUS}

clean:
	rm -f $(OBJECTS) ${OBJS_BONUS}

debug:	CFLAGS += -g3 -fsanitize=address
debug:	re

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:
	clean fclean all re bonus debug

