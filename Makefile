# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 16:04:53 by ababouel          #+#    #+#              #
#    Updated: 2022/10/23 04:57:06 by ababouel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m

CC = cc 
CFLAGS = -Wall -Werror -Wextra -g 
BDIR = build
FILES = main draw/draw draw/generate_text draw/minimap events/events events/clear_data tools/tools\
	raycast/camera tools/vect_tools tools/debug\
	draw/drawshape raycast/raycast raycast/draw_wall\
	parsing/parsing_tools \
	parsing/parsing \
	parsing/get_next_line \
	parsing/get_next_line_utils \
	parsing/split \
	parsing/ft_atoi \
	parsing/libft_func \
	parsing/parser_check \
	parsing/small_tools
	
NAME = cub3d
HEADERS = inc/data.h inc/parsing.h inc/draw.h  inc/raycast.h inc/events.h inc/tools.h
INC = -I ./inc
OBJ = $(addprefix $(BDIR)/, $(FILES:=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@cd ./lib && make
	@$(CC) $(CFLAGS) $^  ./lib/libmlx.a -framework OpenGL -framework AppKit -o $@ 
	@printf "\n$(GREEN)Done !\n"

$(BDIR)/%.o : %.c $(HEADERS)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $<   -o $@ -I ./inc
	 
clean:
	rm -rf $(BDIR)

fclean: clean
	cd ./lib && make clean
	rm -rf $(NAME)

re: fclean all

.PHONY : re all clean fclean