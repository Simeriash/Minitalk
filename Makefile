NAME_CLIENT := client
NAME_SERVER := server

CC := cc
CFLAGS := -Wall -Wextra -Werror -g

HEADER := inc/

LIBFT := src/libft/libft.a

SOURCES_CLIENT := client.c ft_atoi_mt.c

SOURCES_SERVER := server.c

SRC_DIR := src/
SRC_CLIENT := $(addprefix $(SRC_DIR), $(SOURCES_CLIENT))
SRC_SERVER := $(addprefix $(SRC_DIR), $(SOURCES_SERVER))

OBJ_DIR := obj/
OBJ_CLIENT := $(addprefix $(OBJ_DIR), $(SOURCES_CLIENT:.c=.o))
OBJ_SERVER := $(addprefix $(OBJ_DIR), $(SOURCES_SERVER:.c=.o))


.PHONY : all clean fclean re

all : $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT) : $(OBJ_DIR) $(OBJ_CLIENT)
	$(MAKE) -C src/libft
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) -o $@

$(NAME_SERVER) : $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o $@

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

clean :
	rm -rf $(OBJ_CLIENT)
	rm -rf $(OBJ_SERVER)
	rm -rf $(OBJ_DIR)
	$(MAKE) -C src/libft -B clean

fclean : clean
	rm -rf $(NAME_CLIENT)
	rm -rf $(NAME_SERVER)
	$(MAKE) -C src/libft -B fclean

re : fclean all
