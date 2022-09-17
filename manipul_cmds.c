/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipul_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:37:41 by obouizga          #+#    #+#             */
/*   Updated: 2022/09/17 19:36:35 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//ORIGINAL
/*
void	run_first_cmd(int infile, int *fds, t_b_arg args_b, char **env)
{
	read_from_infile(infile);
	write_to_pipe(fds);
	// dprintf(2, "cmd : %s, errno : %d\n", args_b.cmds[0]->cmd_path, errno);
	if (execve(args_b.cmds[0]->cmd_path, args_b.cmds[0]->cmd_op, env) == -1)
		execve_fail();
}

void	run_mid_cmd(int **fds_tbl, int i, t_b_arg args_b, char **env)
{
	read_from_pipe(fds_tbl[i - 1]);
	write_to_pipe(fds_tbl[i]);
	close_fds(fds_tbl, args_b.n_cmd - 1, i);
	// dprintf(2, "cmd : %s, errno : %d\n", args_b.cmds[i]->cmd_path, errno);
	if (execve(args_b.cmds[i]->cmd_path, args_b.cmds[i]->cmd_op, env) == -1)
		execve_fail();
}

void	run_last_cmd(int outfile, int *fds, t_b_arg args_b, char **env)
{
	int	i;

	(void)outfile;
	i = args_b.n_cmd - 1;
	read_from_pipe(fds);
	write_to_outfile(outfile);
	// dprintf(2, "cmd : %s, errno : %d\n", args_b.cmds[i]->cmd_path, errno);
	if (execve(args_b.cmds[i]->cmd_path, args_b.cmds[i]->cmd_op, env) == -1)
		execve_fail();
}

//dup2(int fildes, int fildes2);
//int fstat(int fileds, struct stat *buff);

*/
//TESTING
void	first_cmd(int fd, int *fildes, t_b_arg args_b, char **env)
{
	if (fd)
		read_from_infile(fd);
	write_to_pipe(fildes);
	if (execve(args_b.cmds[0]->cmd_path, args_b.cmds[0]->cmd_op, env) == -1)
		execve_fail();
}

void	mid_cmd(int *fildes, int i, t_b_arg args_b, char **env)
{
	write_to_pipe(fildes);
	if (execve(args_b.cmds[i]->cmd_path, args_b.cmds[i]->cmd_op, env) == -1)
		execve_fail();
}

void	last_cmd(int fd, int *fds, t_b_arg args_b, char **env)
{
	int	i;

	(void)fds;
	i = args_b.n_cmd - 1;
	if (fd > 2)
		write_to_outfile(fd);
	if (execve(args_b.cmds[i]->cmd_path, args_b.cmds[i]->cmd_op, env) == -1)
		execve_fail();
}
