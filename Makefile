# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 16:04:53 by ababouel          #+#    #+#              #
#    Updated: 2022/09/26 02:45:26 by ababouel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m

CC = cc 
CFLAGS = -Wall -Werror -Wextra -g 
BDIR = build
FILES = main draw/draw events/events tools/tools
NAME = cub3d
HEADERS = inc/draw.h inc/parsing.h inc/raycast.h inc/events.h inc/tools.h
INC = -I ./inc
OBJ = $(addprefix $(BDIR)/, $(FILES:=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $^  ./lib/libmlx.a -framework OpenGL -framework AppKit -o $@ 
	@printf "$(GREEN)Done !"

$(BDIR)/%.o : %.c $(HEADERS)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $<   -o $@ -I ./inc
	 
clean:
	rm -rf $(BDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : re all clean fclean