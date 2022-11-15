NAME = libftprintf.a
CC = cc
CFLAGS =-Wall -Wextra -Werror
AR = ar -rc
FT_PRINTF_H = ft_printf.h

FILES =	ft_printchar.c\
		ft_putnbr.c\
		ft_putnbrun.c\
		ft_puthexa.c\
		ft_puthexam.c\
		ft_putstr.c\
		ft_putpoint.c\
		ft_printf.c \

				
OBJS =$(FILES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $^

%.o :%.c $(LIBFT_H)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all