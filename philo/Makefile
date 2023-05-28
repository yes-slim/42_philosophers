# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/28 17:49:56 by yes-slim          #+#    #+#              #
#    Updated: 2023/05/28 18:33:42 by yes-slim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -I includes -c -fsanitize=thread -g3
NAME = philo
NAME_B = philo_bonus
DEL = rm -f

HELPERS = ft_get_path check_files ft_error childs bonus_childs
LIBFT = ft_split functions ft_strdup ft_strncmp
GNL = get_next_line get_next_line_utils

SRCS =	$(addsuffix .c, $(addprefix , $())) \

OBJ = $(SRCS:.c=.o)

%.o : %.c
	@cc $(CFLAGS) $< -o $@

all : $(NAME)

bonus : $(NAME_B)

$(NAME) : $(OBJ) philo.c
	@ar -rc philo.a $(OBJ)
	@cc philo.c philo.a -o $(NAME)
	@echo "\033[0;35m Your \033[0;33mphilo \033[0;35mprogram is created \033[0m"

$(NAME_B) : $(OBJ) philo_bonus.c
	@ar -rc philo.a $(OBJ)
	@cc philo_bonus.c philo.a -I includes -o $(NAME_B)
	@echo "\033[0;35m Your \033[0;33mphilo_bonus \033[0;35mprogram is created \033[0m"

clean :
	@$(DEL) $(OBJ) pipex.a
	@echo "\033[0;32mCleaning ....\033[0m"

fclean : clean
	@$(DEL) $(OBJ) $(NAME) $(NAME_B)

re : fclean all

.PHONY : all clean fclean re bonus