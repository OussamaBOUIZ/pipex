/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_link_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:50:57 by obouizga          #+#    #+#             */
/*   Updated: 2022/08/01 19:05:15 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	creat_link_exec(int pipes_n, int **fds_tbl, t_b_arg args_b, char **env)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < pipes_n)
		pipe(fds_tbl[i++]);
	i = -1;
	while (++i < pipes_n)
		printf("%i | %i\n", fds_tbl[i][0], fds_tbl[i][1]);
	// exit(0);
	i = 0;
	while (i < pipes_n + 1)
	{
		pid = fork();
		if (pid == -1)
			fork_fail();
		if (!pid)
		{
			close_fds(fds_tbl, pipes_n, i);
			if (!i)
				run_first_cmd(args_b.in_f, fds_tbl[i], args_b, env);
			else if (i == pipes_n)
				run_last_cmd(args_b.out_f, fds_tbl[i - 1], args_b, env);
			else
				run_mid_cmd(fds_tbl, i, args_b, env);
		}
		i++;
	}
}
