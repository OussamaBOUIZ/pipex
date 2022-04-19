# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 22:31:58 by obouizga          #+#    #+#              #
#    Updated: 2022/04/17 17:12:09 by obouizga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = pipex

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

CC = cc

FUNCTIONS = check_access_exec.c ft_putchar_fd.c ft_putstr_fd.c ft_split.c ft_strjoin.c ft_strlen.c get_paths.c \
			read_from_pipe.c read_infile.c write_to_outfile.c write_to_pipe.c open_files.c run_first_cmd.c \
			run_second_cmd.c ft_strdup.c\
			
MANDATORY_FUNCTIONS = ${FUNCTIONS} pipex.c

OBJECTS = $(MANDATORY_FUNCTIONS:.c=.o)

all : $(NAME)

$(NAME) :	$(OBJECTS)
			$(CC) $(CFLAGS) $(OBJECTS)  -o $(NAME) 
			@echo "PIPEX CREATED"

clean :
			$(RM)	$(OBJECTS)
	
fclean : clean
			$(RM) $(NAME)

re : fclean all bonus