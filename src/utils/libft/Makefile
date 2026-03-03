# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/09 13:22:47 by dsagong           #+#    #+#              #
#    Updated: 2025/12/11 09:57:28 by dsagong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_tolower.c ft_toupper.c \
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strcmp.c\
	ft_strncmp.c ft_strnstr.c ft_strdup.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_my_strcpy.c ft_my_isupper.c ft_my_islower.c ft_my_strndup.c

BONUS_SRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
OBJ = $(OBJS)

ifeq ($(BONUS_ON),1)
OBJ += $(BONUS_OBJS)
endif

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

bonus: 
	make BONUS_ON=1 all

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
