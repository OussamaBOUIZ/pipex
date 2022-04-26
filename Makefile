# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 22:31:58 by obouizga          #+#    #+#              #
#    Updated: 2022/04/26 12:25:14 by obouizga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = pipex
B_NAME = pipex_bonus

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

CC = cc

FUNCTIONS =  ft_putchar_fd.c ft_putstr_fd.c ft_split.c ft_strjoin_s.c ft_strlen.c get_paths.c \
			read_from_pipe.c read_from_infile.c write_to_outfile.c write_to_pipe.c open_files.c \
			ft_strdup.c set_script.c get_cmd.c get_args.c ft_strncmp.c check_args.c check_slash.c\
			
MANDATORY_FUNCTIONS = ${FUNCTIONS} pipex.c
BONUS_FUNCTIONS = ${FUNCTIONS} pipex_bonus.c

OBJECTS = $(MANDATORY_FUNCTIONS:.c=.o)
B_OBJECTS = $(BONUS_FUNCTIONS:.c=.o)

all : $(NAME)

$(NAME) :	$(OBJECTS)
	$(CC) -fsanitize=address $(CFLAGS) $(OBJECTS)  -o $(NAME) 
	echo "PIPEX CREATED"

bonus : $(B_NAME)

$(B_NAME) : $(B_OBJECTS)
	$(CC) $(CFLAGS) $(B_OBJECTS) -o $(B_NAME)
	echo "PIPEX_BONUS CREATED"
	
clean :
			$(RM) $(OBJECTS) $(B_OBJECTS)
	
fclean : clean
			$(RM) $(NAME) $(B_NAME)
			echo "PIPEX AND PIPEX_BONUS DELETED"

re : fclean all bonus