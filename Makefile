# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/09/20 01:31:31 by lloyet       #+#   ##    ##    #+#        #
#    Updated: 2018/10/08 03:37:57 by lloyet      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fdf

# COMPILER#

CC	= clang
CFLAGS = #-Wall -Wextra -Werror

# DIR#

SRCDIR = ./src/
INCDIR = ./inc/
OBJDIR = ./obj/
LIBDIR = ./lib/

SRC =	main.c \
		parser.c \
		init.c \
		hook.c \
		get_next_line.c \
		draw.c \
		vector.c \
		img.c \
		world.c \
		cam.c \
		colors.c

OBJ	= $(addprefix $(OBJDIR), $(SRC:.c=.o))

# FT_LIBRARY#

FT = $(addprefix $(LIBDIR), libft)
LIBFT = $(addprefix $(FT), libft.a)
LIBINC = -I $(FT)
LIBLINK	= -L $(FT) -l ft

# MLX_LIBRARY#

MLX = $(addprefix $(LIBDIR), minilibx_macos)
LIBMLX = $(addprefix $(MLX), libmlx.a)
MLXINC = -I $(MLX)
MLXLINK	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re

all: $(OBJDIR) $(LIBFT) $(LIBMLX) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(MLXLINK) $(LIBLINK) -lm -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(CFLAGS) $(LIBINC) $(MLXINC) -I $(INCDIR) -c $< -o $@

$(OBJDIR):
	mkdir -p $@

$(LIBFT):
	make -C $(FT)

$(LIBMLX):
	make -C $(MLX)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) clean

re: fclean all
