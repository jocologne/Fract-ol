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

#Compilação
CC = cc
FLAGS = -Wall -Werror -Wextra

#Header
HDR = fractol.h

#Clean
RM = rm -f

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(PRINT):
	$(MAKE) -C $(PRINT_PATH)

$(NAME) : main.o $(LIBFT) $(PRINT)
	$(CC) $(FLAGS) -o $(NAME) $^

%.o: %.c $(LIBFT) $(PRINT) $(HDR)
	@$(CC) $(FLAGS) -c $<

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_PATH)
	$(MAKE) fclean -C $(PRINT_PATH)

re: fclean all