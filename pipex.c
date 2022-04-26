/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:52:40 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/26 12:24:55 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
// ./pipex infile "ls -l" "wc -l" outfile
//	[0]    [1]      [2]    [3]    [4]

int	main(int ac, char **av, char **env)
{
	t_arg	args;
	int		fds[2];
	int		pids[2];

	args = get_args(ac, av, env);
	check_args(args);
	pipe(fds);
	pids[0] = fork();
	pids[1] = fork();
	if (!pids[0])
	{
		read_from_infile(args.in_f);
		write_to_pipe(fds);
		execve(args.cmd_1->cmd_path, args.cmd_1->cmd_op, env);
	}
	if (!pids[1])
	{
		read_from_pipe(fds);
		write_to_outfile(args.out_f);
		execve(args.cmd_2->cmd_path, args.cmd_2->cmd_op, env);
	}
	wait_all();
	return (0);
}
