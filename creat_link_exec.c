/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_link_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:50:57 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/07 06:14:17 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	creat_link_exec(int pipes_n, int **fds_tbl, t_b_arg args_b, char **env)
{
	int	i;

	i = 0;
	while (i < pipes_n)
		pipe(fds_tbl[i++]);
	while (i < pipes_n + 1)
	{
		if (!fork())
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
