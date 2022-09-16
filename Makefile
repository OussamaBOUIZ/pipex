# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 22:31:58 by obouizga          #+#    #+#              #
#    Updated: 2022/08/11 10:17:30 by obouizga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = pipex
B_NAME = ppx

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

CC = cc

FUNCTIONS =  ft_putchar_fd.c ft_putstr_fd.c ft_split.c ft_strjoin_s.c ft_strlen.c get_paths.c \
			write_read.c malloc_fail.c ft_strdup.c get_cmd.c get_args.c get_args_bonus.c ft_strncmp.c \
			check_args.c check_slash.c wait_all.c get_commands.c check_args_bonus.c creat_link_exec.c \
			creat_fds_table.c manipul_cmds.c dup2_fail.c close_fail.c fork_fail.c execve_fail.c \
			close_fds.c proc_utils.c errno.c
			
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