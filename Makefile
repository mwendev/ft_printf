# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/18 13:06:29 by mwen              #+#    #+#              #
#    Updated: 2021/06/19 16:32:41 by mwen             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c \
			src/ft_decimal_to_hexa.c\
			src/ft_flags.c\
			src/ft_putchar.c\
			src/ft_putstrprec.c\
			src/ft_str_tolower.c\
			src/ft_treat_char.c\
			src/ft_treat_hexa.c\
			src/ft_treat_int.c\
			src/ft_treat_percent.c\
			src/ft_treat_pointer.c\
			src/ft_treat_string.c\
			src/ft_treat_types.c\
			src/ft_treat_uint.c\
			src/ft_treat_width.c
OBJS	=	${SRCS:.c=.o}
NAME	=	libftprintf.a
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
LIBFT	=	./libft/libft.a
RM		=	rm -f

all:	$(NAME)

$(NAME):$(OBJS)
		$(MAKE) -C ./libft
		cp $(LIBFT) $(NAME)
		ar rcs $(NAME) $(OBJS)
		$(RM) $(OBJS)

bonus:	$(NAME)

clean:
		$(RM) $(OBJS)
		$(MAKE) clean -C ./libft

fclean:	clean
		$(RM) $(NAME)
		$(MAKE) fclean -C ./libft

re:		fclean all

.PHONY:	all clean fcloean re
