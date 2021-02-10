NAME=			libftprintf.a

SRCS=			ft_printf.c ft_parse.c ft_convert.c ft_convert_int.c \
				ft_printf_utils.c ft_printf_utils2.c ft_printf_utils3.c \
				ft_printf_utils4.c ft_printf_utils5.c

OBJS=			$(SRCS:.c=.o)

HEADER=			includes

CC=				gcc
#CC=			clang

CFLAGS=			-Wall -Wextra -Werror

RM= 			rm -f


all:			$(NAME)

$(NAME):		$(OBJS)
					@ar -rcs $(NAME) $(OBJS)

bonus:			$(NAME)

%.o: %.c
					@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

clean:
					@$(RM) $(OBJS)

fclean:			clean
					@$(RM) $(NAME)

re:				fclean all

.PHONY:			all fclean clean re
