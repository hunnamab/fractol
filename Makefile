# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/21 15:05:19 by hunnamab          #+#    #+#              #
#    Updated: 2020/03/13 18:28:58 by hunnamab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FLAGS = -Wall -Wextra
#-lmlx -lX11 -lXext -lm for linux
#-lmlx -framework OpenGL -framework AppKit for mac
LIBRARY = libft/libft.a
HEADER = fractol.h
SRC = fractol.c settings.c key_mouse_control.c fract_types.c colors.c errors.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(OBJ): %.o: %.c
		gcc -c $(FLAGS) -I libft/ -o $@ $<

$(LIBRARY):
		@make -C libft/

$(NAME): $(LIBRARY) $(OBJ)
		@gcc $(OBJ) $(LIBRARY) -o $(NAME) -I $(HEADER) -lmlx -framework OpenGL -framework AppKit -L.

clean:
	@rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all
