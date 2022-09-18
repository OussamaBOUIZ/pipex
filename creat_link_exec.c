/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_link_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:50:57 by obouizga          #+#    #+#             */
/*   Updated: 2022/09/18 08:54:56 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	creat_link_exec(int *fildes, t_b_arg args_b, char **env)
{
	int	i;

	i = 0;
	while (i < args_b.n_cmd - 1)
	{
		//thxere's no need to create a pipe in the last command
		if (i < args_b.n_cmd - 1) 
			pipe(fildes);
		dprintf(2, "Write end : %d, Read end : %d\n", fildes[WRITE_END], fildes[READ_END]);
		if (!ft_fork())
		{
			if (!i)
				first_cmd(args_b.in_f, fildes, args_b, env);
			else
				mid_cmd(fildes, i, args_b, env);
		}
		else
			read_from_pipe(fildes);
		i++;
	}
	if (!ft_fork())
		last_cmd(args_b.out_f, args_b, env);
}


