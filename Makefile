NAME = explorer
LIB_DIR = ../core/library

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIB_DIR) -include f_colors.h

all: lib $(NAME)

lib:
	@$(MAKE) -C $(LIB_DIR)

$(NAME): main.c $(LIB_DIR)/libcore.a
	$(CC) $(CFLAGS) main.c -L$(LIB_DIR) -lcore -o $(NAME)

clean:
	@$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all lib clean fclean re
