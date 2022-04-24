/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:52:40 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/22 16:09:30 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
// ./pipex infile "ls -l" "wc -l" outfile
//	[0]    [1]      [2]    [3]    [4]
int	main(int ac, char **av, char **env)
{
	pid_t	pids[2];
	int		fds[2];
	int		io_fds[2];
	int		status;

	(void) ac;
	io_fds[0] = open(av[1], O_RDONLY);
	io_fds[1] = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	pipe(fds);
	pids[0] = fork();
	pids[1] = fork();
	if (!pids[0])
	{
		read_from_infile(io_fds[0]);
		write_to_pipe(fds);
		check_access_exec(av[2], env);
	}
	if (!pids[1])
	{
		read_from_pipe(fds);
		write_to_outfile(io_fds[1]);
		check_access_exec(av[3], env);
	}
	waitpid(pids[0], &status, 0);
	waitpid(pids[1], &status, 0);
	return (0);
}
