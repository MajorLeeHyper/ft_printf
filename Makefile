# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/24 13:21:38 by dnelson           #+#    #+#              #
#    Updated: 2017/07/24 14:31:08 by dnelson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = ft_strlen.c \
		ft_atoi.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_strcpy.c \
		ft_strnew.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_putnbr.c \
		ft_putendl.c \
		ft_strncat.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_isprint.c \
		ft_isascii.c \
		ft_itoa.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_strstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_digits.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strjoin.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_strrev.c \
		ft_isprime.c \
		ft_putstrarr.c \
		ft_swap.c \
		get_next_line.c \
		ft_getnbr.c \
		ft_strlenc.c \
		ft_absolute_v.c \
		ft_strchr_count.c

SRCS = ft_printf.c \

OBJS = $(addprefix $(OBJDIR),$(SRC:.c=.o))
OBJS += $(addprefix $(OBJDIR), $(LIBFT:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFTDIR = ./libft/srcs/
LIBINC = -I./libft/includes
LIBLINK = -L./libft -lft

SRCDIR = ./srcs/
INCDIR = ./includes/
OBJDIR = ./objs/

all: obj libft $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo "ft_printf Compilation Complete"

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c | obj
	@$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $^

$(OBJDIR)%.o: $(LIBFTDIR)%.c | obj
	@$(CC) $(CFLAGS) $(LIBINC) -o $@ -c $^

clean:
	@rm -rf $(OBJDIR)
	@echo "Object Files Removed"

fclean: clean
	@rm -f $(NAME)
	@echo "ft_printf Library File Removed"

re: fclean all

.PHONY: all clean fclean re
