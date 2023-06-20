# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/28 17:49:56 by yes-slim          #+#    #+#              #
#    Updated: 2023/06/20 11:39:44 by yes-slim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#========================variables============================#
HEADER  = -I includes
THREAD  = -pthread -fsanitize=thread	
CFLAGS  = -Wall -Werror -Wextra $(HEADER) -c $(THREAD)
NAME    = philo
DEL     = rm -f
#=================files=======================================#
HELPERS = ft_error parsing helpers init routine
SRCS    = $(addsuffix .c, $(addprefix helpers/, $(HELPERS)))
OBJ     = $(SRCS:.c=.o)
#=========================compile=============================#
%.o : %.c
	@echo $(grey)$(italic)"	~Compiling $<"$(reset)
	@cc $(CFLAGS) $< -o $@
#==========================rules==============================#
all : $(NAME)

$(NAME) : $(OBJ) philo.c
	@ar -rc philo.a $(OBJ)
	@cc philo.c philo.a $(HEADER) $(THREAD) -o $(NAME)
	@echo $(cyan)$(underline)"philo is ready to run" $(reset)

clean :
	@$(DEL) $(OBJ) philo.a
	@echo $(green)$(italic)$(bold)"	~Deleting files..."$(reset)

fclean : clean
	@$(DEL) $(NAME)
	@echo $(green)$(italic)$(bold)"	~Deleting philo..."$(reset)

re : fclean all

.PHONY : all clean fclean re
#===========================colors============================#
black  = "\033[0;30m"
red    = "\033[0;31m"
green  = "\033[0;32m"
yellow = "\033[0;33m"
blue   = "\033[0;34m"
purple = "\033[0;35m"
cyan   = "\033[0;36m"
grey   = "\033[0;90m"
reset  = "\033[0m"
#============================font=============================#
bold      = "\033[1m"
italic    = "\033[3m"
underline = "\033[4m"
inverse   = "\033[7m"
#=============================================================#