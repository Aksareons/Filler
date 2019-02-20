# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/20 06:29:23 by voksenui          #+#    #+#              #
#    Updated: 2019/02/20 08:05:08 by voksenui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = voksenui.filler

LIB		=	ft_printf/

LIB_HDR	=	$(LIB)hdr/

SRC		=	filler.c \
			alg_filler.c \
			write_piece.c \

OBJ		=	$(SRC:.c=.o)
LFLAGS	=	-lftprintf -L $(LIB)
IFLAGS	=	-I $(LIB_HDR) -I ./
CFLAGS	=	-Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB)
	gcc -o $(NAME) $(CFLAGS) $(LFLAGS) $(OBJ)



clean:
	rm -f $(OBJ)
	make clean -C $(LIB)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ)
	make fclean -C $(LIB)

re: fclean all

.PHONY: all clean fclean re