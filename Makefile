# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 22:31:58 by obouizga          #+#    #+#              #
#    Updated: 2022/04/26 05:50:29 by obouizga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = pipex

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

CC = cc

FUNCTIONS =  ft_putchar_fd.c ft_putstr_fd.c ft_split.c ft_strjoin_s.c ft_strlen.c get_paths.c \
			read_from_pipe.c read_from_infile.c write_to_outfile.c write_to_pipe.c open_files.c \
			ft_strdup.c set_script.c get_cmd.c get_args.c ft_strncmp.c check_arguments.c check_slash.c\
			
MANDATORY_FUNCTIONS = ${FUNCTIONS} pipex.c

OBJECTS = $(MANDATORY_FUNCTIONS:.c=.o)

all : $(NAME)

$(NAME) :	$(OBJECTS)
			$(CC) -fsanitize=address $(CFLAGS) $(OBJECTS)  -o $(NAME) 
			@echo "PIPEX CREATED"

clean :
			$(RM)	$(OBJECTS)
	
fclean : clean
			$(RM) $(NAME)

re : fclean all bonus