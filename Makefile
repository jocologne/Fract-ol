#Alvo
NAME = fractol

# Libft
LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

#Print
PRINT_PATH = ft_printf/
PRINT_NAME = libftprintf.a
PRINT = $(PRINT_PATH)$(PRINT_NAME)

#MiniLibx
LIBX_PATH = minilibx-linux/
LIBX_NAME = libmlx_Linux.a
LIBX = $(LIBX_PATH)$(LIBX_NAME)

#Compilação
CC = cc
FLAGS = -Wall -Werror -Wextra
LIBFLAGS = -lXext -lX11 -lm

#Headers
HDR = -I./ -I./libft -I./ft_printf -I./minilibx-linux

#Clean
RM = rm -f

#Sources and Objects
SRC = main.c\
		init.c\
		events.c\
		render.c\
		math_utils.c
OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(PRINT) $(LIBX) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)  > /dev/null 2>/dev/null
	@echo "libft compiled"

$(PRINT):
	@$(MAKE) -C $(PRINT_PATH)  > /dev/null 2>/dev/null
	@echo "ft_printf compiled"

$(LIBX):
	@$(MAKE) -C $(LIBX_PATH) > /dev/null 2>/dev/null
	@echo "minilibx compiled"

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIBX) $(PRINT) $(HDR) $(LIBFLAGS)

%.o: %.c $(HDR)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) *.o
	@$(MAKE) clean -C $(LIBX_PATH) > /dev/null 2>/dev/null

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_PATH) > /dev/null 2>/dev/null
	@$(MAKE) fclean -C $(PRINT_PATH) > /dev/null 2>/dev/null

re: fclean all