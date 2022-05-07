/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:52:40 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/07 18:58:24 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
// ./pipex infile "ls -l" "wc -l" outfile
//	[0]    [1]      [2]    [3]    [4]
	// check_args(args);

void	check_infile_cmd(int fd, t_arg args)
{
	if (fd == -1)
	{
		perror("nono");
		exit(1);
	}
	else if (!args.cmd_1)
	{
		ft_putstr_fd("Command Not Found\n", 2);
		exit(1);
	}
}


void	check_cmd_2(t_arg args)
{
	if (!args.cmd_2)
	{
		ft_putstr_fd("Command Not Found\n", 2);
		exit(1);
	}
}

int	main(int ac, char **av, char **env)
{
	t_arg	args;
	int		fds[2];
	int		pids[2];

	args = get_args(ac, av, env);
	pipe(fds);
	pids[0] = fork();
	if (!pids[0])
	{
		check_infile_cmd(args.in_f, args);
		read_from_infile(args.in_f);
		write_to_pipe(fds);
		execve(args.cmd_1->cmd_path, args.cmd_1->cmd_op, env);
	}
	pids[1] = fork();
	if (!pids[1])
	{
		check_cmd_2(args);
		read_from_pipe(fds);
		write_to_outfile(args.out_f);
		execve(args.cmd_2->cmd_path, args.cmd_2->cmd_op, env);
	}
	close_fds(fds);
	wait_all();
	return (0);
}
