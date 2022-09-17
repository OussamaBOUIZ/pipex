# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 22:31:58 by obouizga          #+#    #+#              #
#    Updated: 2022/09/17 16:24:05 by obouizga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = pipex
B_NAME = ppx

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

CC = cc

FUNCTIONS =  check_args.c ft_puts.c manipul_cmds.c sys_err.c utils_2.c creat_link_exec.c \
			ft_split.c parse.c utils.c write_read.c
			
MANDATORY_FUNCTIONS = ${FUNCTIONS} pipex.c
BONUS_FUNCTIONS = ${FUNCTIONS} ppx.c

OBJECTS = $(MANDATORY_FUNCTIONS:.c=.o)
B_OBJECTS = $(BONUS_FUNCTIONS:.c=.o)

all : $(NAME)

$(NAME) :	$(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS)  -o $(NAME) 
	@echo "PIPEX CREATED"

bonus : $(B_NAME)

$(B_NAME) : $(B_OBJECTS)
	@$(CC) $(CFLAGS) $(B_OBJECTS) -o $(B_NAME)
	@echo "BONUS CREATED"
	
clean :
	@$(RM) $(OBJECTS) $(B_OBJECTS)
	
fclean : clean
	@$(RM) $(NAME) $(B_NAME)
	@echo "PIPEX AND BONUS DELETED"

re : fclean all bonus