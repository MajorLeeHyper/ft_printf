# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/24 13:21:38 by dnelson           #+#    #+#              #
#    Updated: 2017/07/26 16:01:46 by dnelson          ###   ########.fr        #
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
		ft_strchr_count.c \
		ft_strchr_replace.c \
		ft_compare_int.c

SRCS = ft_printf.c \
	   ft_convert_chars.c \
	   ft_escape_conversion.c \
	   ft_find_precision.c \
	   ft_find_w_ignore_p.c \
	   ft_find_width.c \
	   ft_flag_checker.c \
	   ft_flag_validate.c \
	   ft_float_conversion.c \
	   ft_int_len.c \
	   ft_long_conversion.c \
	   ft_negative.c \
	   ft_num_conversion.c \
	   ft_parse_precision.c \
	   ft_parse_w_ignore_p.c \
	   ft_parse_width.c \
	   ft_parse_width_only.c \
	   ft_pointer_conversion.c \
	   ft_precision_int_value.c \
	   ft_print_flag.c \
	   ft_print_prefix.c \
	   ft_print_width.c \
	   ft_print_width_only.c \
	   ft_putwchar.c \
	   ft_putwstr.c \
	   ft_revstr_intlen.c \
	   ft_set_prefix.c \
	   ft_set_zero_values.c \
	   ft_skip_wild_arg_prec.c \
	   ft_str_conversion.c \
	   ft_str_intlen.c \
	   ft_uint_len.c \
	   ft_unterminated.c \
	   ft_width_only.c \
	   ft_wstr_conversion.c \
	   ft_widthlen_prefix.c \
	   ft_zero.c \
	   pf_itoa_base.c

OBJS = $(addprefix $(OBJDIR),$(SRCS:.c=.o))
OBJS += $(addprefix $(OBJDIR), $(LIBFT:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFTDIR = ./libft/srcs/
LIBINC = -I./libft/includes
LIBLINK = -L./libft -lft

SRCDIR = ./srcs/
INCDIR = ./includes/
OBJDIR = ./objs/

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo "ft_printf Compilation Complete"

objs:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c | objs
	@$(CC) $(CFLAGS) -I $(INCDIR) $(LIBINC) -o $@ -c $^

$(OBJDIR)%.o: $(LIBFTDIR)%.c | objs
	@$(CC) $(CFLAGS) $(LIBINC) -o $@ -c $^

clean:
	@rm -rf $(OBJDIR)
	@echo "Object Files Removed"

fclean: clean
	@rm -f $(NAME)
	@echo "ft_printf Library File Removed"

re: fclean all

.PHONY: all clean fclean re
