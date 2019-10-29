# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbragard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/19 10:27:21 by qbragard          #+#    #+#              #
#    Updated: 2019/05/14 13:22:29 by qbragard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = libftprintf.a

FT_PRINTF_PATH = srcs/
FT_PRINTF_NAME = ft_parser.c \
ft_parser_complement.c \
ft_printf.c \
ft_flag.c \
ft_printf_integer_base.c \
ft_printf_integer.c \
ft_printf_float_numbers.c


LIBFT_PATH = libft/
LIBFT_NAME = ft_memset.c ft_isdigit.c ft_itoa_pf.c ft_putchar.c \
	ft_putstr.c ft_strtrim_space.c ft_strdel.c ft_strdup.c ft_atoi.c \
	ft_strjoin.c ft_strlen.c ft_strncmp.c ft_strnequ.c ft_strnew.c \
	ft_tolower.c ft_intlen.c ft_itoa_base_pf.c ft_max.c ft_abs.c \
	ft_strjoin_rfree.c ft_strclr.c ft_strcpy.c

FT_PRINTF_OBJS_PATH = objs/
LIBFT_OBJS_PATH = libft/objs/

FT_PRINTF_OBJS_NAME = $(FT_PRINTF_NAME:.c=.o)
LIBFT_OBJS_NAME = $(LIBFT_NAME:.c=.o)

FT_PRINTF = $(addprefix $(FT_PRINTF_PATH),$(FT_PRINTF_NAME))
LIBFT = $(addprefix $(LIBFT_PATH),$(LIBFT_NAME))
FT_PRINTF_OBJS = $(addprefix $(FT_PRINTF_OBJS_PATH),$(FT_PRINTF_OBJS_NAME))
LIBFT_OBJS = $(addprefix $(LIBFT_OBJS_PATH),$(LIBFT_OBJS_NAME))

CC = gcc
CFLAGS = -Wall -Werror -Wextra
IFLAG = -I ./includes

$(FT_PRINTF_OBJS_PATH)%.o: $(FT_PRINTF_PATH)%.c includes/ft_printf.h
	@mkdir $(FT_PRINTF_OBJS_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(IFLAG) -o $@ -c $<
	@echo "Compiling $<\r\c"

$(LIBFT_OBJS_PATH)%.o: $(LIBFT_PATH)%.c includes/libft.h
	@mkdir $(LIBFT_OBJS_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(IFLAG) -o $@ -c $<
	@echo "Compiling $<\r\c"

all: $(NAME)

$(NAME): $(FT_PRINTF_OBJS) $(LIBFT_OBJS)
	@ar rc $(NAME) $(FT_PRINTF_OBJS) $(LIBFT_OBJS)
	@ranlib $(NAME)
	@echo "\033[2K\c"
	@echo "\033[1;34mft_printf\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"


clean:
	@rm -rf $(FT_PRINTF_OBJS_PATH) $(LIBFT_OBJS_PATH)
	@echo "\033[1;34mft_printf\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;34mft_printf\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all

.PHONY: all clean fclean re
