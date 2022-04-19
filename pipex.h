/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:48:30 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/17 17:11:54 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# define WRITE_END 1
# define READ_END 0

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	**get_paths(char *path_line);
void	check_access_exec(char *av, char **env);
void	read_infile(int infile);
void	read_from_pipe(int *fds);
void	write_to_outfile(int outfile);
void	write_to_pipe(int *fds);
void	open_files(int *io_fds, char *file1, char *file2);
void	run_first_cmd(int *fds, int io_fds, char *cmd, char **env);
void	run_second_cmd(int *fds, int io_fds, char *cmd, char **env);
char	*ft_strdup(const char *s1);

#endif