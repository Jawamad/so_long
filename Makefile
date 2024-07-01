NAME = so_long
DIR_OBJ = obj/
DIR_SRC = src/
DIR_GNL = gnl/
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
LIBMLX = mlx_linux/libmlx.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror -g -ggdb
RM = rm -rf

SRCS = $(wildcard $(DIR_SRC)*.c) $(wildcard $(DIR_GNL)*.c)
OBJ = $(patsubst $(DIR_SRC)%.c,$(DIR_OBJ)%.o,$(SRCS))

$(NAME): $(OBJ)
	@make -sC ./ft_printf
	@make -sC ./libft
	@make -sC ./mlx_linux
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF) $(LIBMLX) -lXext -lX11
	@echo "\ncompilation completed\n"
$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

$(DIR_OBJ)%.o: $(DIR_SRC)%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@make clean -sC libft
	@make clean -sC ft_printf
	@make clean -sC mlx_linux
	@rm -rf $(DIR_OBJ)
	@echo "\nclean completed\n"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -sC libft
	@make fclean -sC ft_printf
	@echo "\nfclean completed\n"

re: fclean all 