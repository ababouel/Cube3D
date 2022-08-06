# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 16:04:53 by ababouel          #+#    #+#              #
#    Updated: 2022/08/03 17:07:41 by ababouel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m

CC = cc 
CFLAGS = -Wall -Werror -Wextra -g 
BDIR = build
FILES = main
NAME = cub3d
OBJ = $(addprefix $(BDIR)/, $(FILES:=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $^ -lmlx  -framework OpenGL -framework AppKit -o $@ 
	@printf "$(GREEN)Done !"
$(BDIR)/%.o : %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ 
	 
clean:
	rm -rf $(BDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : re all clean fclean