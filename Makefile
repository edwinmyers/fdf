# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nparker <nparker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/14 12:31:10 by nparker           #+#    #+#              #
#    Updated: 2019/03/14 13:10:42 by nparker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
NAME		=	fdf
FLAGS		=	-Wall -Wextra -Werror

LIB_DIR		=	libft
LIBLINK		=	-L $(LIB_DIR) -lft
LIB 		=	$(LIB_DIR)/libft.a

INCLUDES	= 	-I ./

OBJ_DIR		=	objs
SRC_DIR		=	srcs
SRC			=	fdf.c\
				init.c\
				draw.c\
				gradient.c\
				iso_transform.c\
				keys.c\
				layers.c\
				p_vec.c\
				random.c\
				read.c\
				rotate.c\
				validate.c\
				zoom.c\
				menu.c\

OBJ			= $(SRC:.c=.o)
SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))


all: directory $(NAME)

$(NAME): $(OBJ_DIR) $(LIB) $(OBJS)
	@$(CC) $(FLAGS) -o $@ $(OBJS) -L minilibx -lmlx -framework OpenGL -framework AppKit $(LIBLINK)
	@./fdf test_maps/42.fdf

$(LIB):
	@make -C $(LIB_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(FLAGS) -c $^ -o $@ $(INCLUDES)

directory: $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJS)
	@make -C $(LIB_DIR) clean
	@rm -rf $(OBJ_DIR)
fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: clean all re fclean directory
