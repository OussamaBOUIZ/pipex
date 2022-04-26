/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:48:30 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/26 12:25:04 by obouizga         ###   ########.fr       */
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

typedef struct cmd
{
	char	*cmd_path;
	char	**cmd_op;
}			t_cmd;
typedef struct arg
{
	int		in_f;
	int		out_f;
	t_cmd	*cmd_1;
	t_cmd	*cmd_2;
}			t_arg;

typedef struct arg_b
{
	int		n;
	int		in_f;
	int		out_f;
	t_cmd	**cmds;
}			t_b_arg;

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin_s(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	**get_paths(char **env);
t_arg	get_args(int ac, char **av, char **env);
void	check_access_exec(char *av, char **env);
void	read_from_infile(int infile);
void	read_from_pipe(int *fds);
void	write_to_outfile(int outfile);
void	write_to_pipe(int *fds);
void	open_files(int *io_fds, char *file1, char *file2);
int		**create_fds_table(int pipes_n);
char	*ft_strdup(const char *s1);
int		check_main_process(int *pids_arr, int n);
void	setup_pipes(int n, int **fds_table, int *pids_arr, int *in_out_f);
void	creat_procs(int n, int *pids_arr, int **fds_table);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		get_arr_len(char **arr);
int		check_slash(char *s);
int		set_script(char *s, t_cmd *cmd);
void	check_args(t_arg args);
t_cmd	*get_cmd(char *s, char **env);
void	run_first_cmd(int infile, int *fds, t_b_arg args_b, char **env);
void	run_last_cmd(int outfile, int *fds, t_b_arg args_b, char **env);
void	run_mid_cmd(int **fds, int i, t_b_arg args_b, char **env);
void	creat_link_exec(int **fds_tbl, t_b_arg args_b, char **env);
t_b_arg	get_args_bonus(int ac, char **av, char **env);
t_cmd	**get_commands(int ac, char **av, char **env);
void	wait_all(void);

#endif