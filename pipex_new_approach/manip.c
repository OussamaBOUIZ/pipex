/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:37:41 by obouizga          #+#    #+#             */
/*   Updated: 2022/09/16 18:36:04 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

	i = args_b.n_cmd - 1;
	read_from_pipe(fds);
	if (fd > 2)
		write_to_outfile(fd);
	if (execve(args_b.cmds[i]->cmd_path, args_b.cmds[i]->cmd_op, env) == -1)
		execve_fail();
}
