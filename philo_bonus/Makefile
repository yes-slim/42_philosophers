# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/28 17:49:56 by yes-slim          #+#    #+#              #
#    Updated: 2023/05/28 18:43:32 by yes-slim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -I includes -c -fsanitize=thread -g3
NAME = philo_bonus
DEL = rm -f

SRCS =	$(addsuffix .c, $(addprefix , $())) \

OBJ = $(SRCS:.c=.o)

%.o : %.c
	@cc $(CFLAGS) $< -o $@

all : $(NAME)


$(NAME) : $(OBJ) philo_bonus.c
	@ar -rc philo_bonus.a $(OBJ)
	@cc philo_bonus.c philo.a -o $(NAME)
	@echo "\033[0;35m Your \033[0;33m$(NAME) \033[0;35mprogram is created \033[0m"

clean :
	@$(DEL) $(OBJ) philo_bonus.a
	@echo "\033[0;32mCleaning ....\033[0m"

fclean : clean
	@$(DEL) $(OBJ) $(NAME)

re : fclean all

.PHONY : all clean fclean re