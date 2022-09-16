/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_link_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:50:57 by obouizga          #+#    #+#             */
/*   Updated: 2022/09/16 07:35:42 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dis_pipe(int n, int **fds)
{
	for (int i = 0; i < n; i++)	
		printf("W : %i | R : %i\n", fds[i][WRITE_END], fds[i][READ_END]);
}

void	creat_link_exec(int **fds_tbl, t_b_arg args_b, char **env)
{
	int		i;
	pid_t	pid;
	int		pipes_n;

	pipes_n = args_b.n_cmd - 1;
	i = 0;
	while (i < pipes_n)
		pipe(fds_tbl[i++]);
	dis_pipe(pipes_n, fds_tbl);
	_errno();
	i = 0;
	while (i < pipes_n)
	{
		pid = ft_fork();
		if (!pid)
		{
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

