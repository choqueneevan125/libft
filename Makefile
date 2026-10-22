CC = cc
AR = ar
FLAGS = -Wall -Wextra -Werror
SRC = $(wildcard ft_*.c)
NAME = libft.a
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rcs $@ $^

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: all fclean clean re

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all