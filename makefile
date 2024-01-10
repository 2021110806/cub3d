# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 16:36:53 by minjeon2          #+#    #+#              #
#    Updated: 2024/01/10 16:43:21 by minjeon2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MANDATORY_DIR = mandatory
BONUS_DIR = bonus
NAME = cub3d

.PHONY : clean fclean re all bonus

main:
	rm -f $(NAME)
	make -C $(MANDATORY_DIR) all
	cp $(MANDATORY_DIR)/$(NAME) ./

bonus:
	rm -f $(NAME)
	make -C $(BONUS_DIR) all
	cp $(BONUS_DIR)/$(NAME) ./

clean:
	make -C $(MANDATORY_DIR) fclean
	make -C $(BONUS_DIR) fclean

fclean:
	$(MAKE) clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

all: 
	$(MAKE) main
