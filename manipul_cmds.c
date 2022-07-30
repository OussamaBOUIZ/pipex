/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipul_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:37:41 by obouizga          #+#    #+#             */
/*   Updated: 2022/07/30 15:55:36 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_first_cmd(int infile, int *fds, t_b_arg args_b, char **env)
{
	ft_putstr_fd("first_cmd\n", 2);
	read_from_infile(infile);
	write_to_pipe(fds);
	if (execve(args_b.cmds[0]->cmd_path, args_b.cmds[0]->cmd_op, env) == -1)
		execve_fail();
}

void	run_mid_cmd(int **fds_tbl, int i, t_b_arg args_b, char **env)
{
	ft_putstr_fd("mid_cmd\n", 2);
	read_from_pipe(fds_tbl[i - 1]);
	write_to_pipe(fds_tbl[i]);
	if (execve(args_b.cmds[i]->cmd_path, args_b.cmds[i]->cmd_op, env) == -1)
		execve_fail();
}

void	run_last_cmd(int outfile, int *fds, t_b_arg args_b, char **env)
{
	int	i;

	ft_putstr_fd("last_cmd\n", 2);
	i = args_b.n - 1;
	read_from_pipe(fds);
	write_to_outfile(outfile);
	if (execve(args_b.cmds[i]->cmd_path, args_b.cmds[i]->cmd_op, env) == -1)
		execve_fail();
}
