# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 11:39:14 by abarchil          #+#    #+#              #
#    Updated: 2022/02/14 21:04:46 by abarchil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC_FILE = mandatory/main.c src/ft_putstr_fd.c src/ft_putchar_fd.c src/ft_isdigit.c src/ft_atoi.c \
	mandatory/philo_init.c 

OBJ_FILE = $(SRC_FILE:.c=.o)

NAME = philo

BONUS = philo_bonus

CC = gcc

RED = \033[0;31m

RESET = \033[0m

CYAN = \033[0;36m

YELLOW = \033[0;33m

CFLAGS = -Wall -Werror -Wextra

all : $(NAME) philosophers.h

	@echo "$(RED) \
		██████╗ ██╗  ██╗██╗██╗      █████╗  ██████╗ █████╗ ██████╗ ██╗  ██╗███████╗██████╗  ██████╗\n\
		██╔══██╗██║  ██║██║██║     ██╔══██╗██╔════╝██╔══██╗██╔══██╗██║  ██║██╔════╝██╔══██╗██╔════╝\n\
		██████╔╝███████║██║██║     ██║  ██║╚█████╗ ██║  ██║██████╔╝███████║█████╗  ██████╔╝╚█████╗ \n\
		██╔═══╝ ██╔══██║██║██║     ██║  ██║ ╚═══██╗██║  ██║██╔═══╝ ██╔══██║██╔══╝  ██╔══██╗ ╚═══██╗\n\
		██║     ██║  ██║██║███████╗╚█████╔╝██████╔╝╚█████╔╝██║     ██║  ██║███████╗██║  ██║██████╔╝\n\
		╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚════╝ ╚═════╝  ╚════╝ ╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═════╝  $(RESET)"

%.o:%.c
	@echo "$(CYAN)                          <----------- COMPILING $< ----------->$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ_FILE)
	@$(CC) $(CFLAGS) $(OBJ_FILE)  -lpthread -o $(NAME)
clean :
	@echo "$(YELLOW)                        <----------- REMOVING OBJECT FILES ----------->$(RESET)"
	@rm -rf $(OBJ_FILE)
fclean : clean
	@echo "$(YELLOW)                        <----------- REMOVING MINISHELL ----------->$(RESET)"
	@rm -rf $(NAME) $(BONUS)
bonus:	$(BONUS) philosophers.h
$(BONUS) : $(OBJ_FILE)
	@$(CC) $(CFLAGS) $(OBJ_FILE)  -lpthread -o $(BONUS)
re : fclean all

.PHONY : clean fclean re