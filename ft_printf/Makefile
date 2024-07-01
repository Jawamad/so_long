CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = ft_printf.c libftmpf.c putnbr.c

OBJ = $(SRC:.c=.o)
AR = ar rc

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(AR) -o $@ $^

clean : 
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all

.phony: all clean fclean re
