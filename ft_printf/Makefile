NAME:= libftprintf.a
CC:= cc
CFLAGS:= -Wall -Wextra -Werror
HDR:= ftprintf.h

SRC_FILES:=	ft_printf.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_putnum.c \
				ft_puthexa.c
				
OBJ_FILES:= $(SRC_FILES:.c=.o)

%.o: %.c $(HDR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES)
	@ar rcs $@ $^

all: $(NAME)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
