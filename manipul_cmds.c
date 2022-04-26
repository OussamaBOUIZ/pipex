/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipul_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:37:41 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/26 10:45:22 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_first_cmd(int infile, int *fds, t_b_arg args_b, char **env)
{
	read_from_infile(infile);
	write_to_pipe(fds);
	execve(args_b.cmds[0]->cmd_path, args_b.cmds[0]->cmd_op, env);
}

void	run_last_cmd(int outfile, int *fds, t_b_arg args_b, char **env)
{
	read_from_pipe(fds);
	write_to_outfile(outfile);
	execve(args_b.cmds[args_b.n]->cmd_path, args_b.cmds[args_b.n]->cmd_op, env);
}

void	run_mid_cmd(int **fds, int i, t_b_arg args_b, char **env)
{
	read_from_pipe(fds[i - 1]);
	write_to_pipe(fds[i]);
	execve(args_b.cmds[i]->cmd_path, args_b.cmds[i]->cmd_op, env);
}
