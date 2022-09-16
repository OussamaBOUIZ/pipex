/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_link_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 08:57:46 by obouizga          #+#    #+#             */
/*   Updated: 2022/09/16 18:35:49 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	creat_link_exec(int *fildes, t_b_arg args_b, char **env)
{
	int	i;
	int	pip_n;

	pip_n = args_b.n_cmd - 1;
	i = 0;
	while (i < pip_n)
	{
		pipe(fildes);
		if (!ft_fork())
		{
			if (!i)
				first_cmd(args_b.in_f, fildes, args_b, env);
			else if (i == pip_n)
				last_cmd(args_b.out_f, fildes, args_b, env);
			else
				mid_cmd(fildes, i, args_b, env);
		}
		else if (i && i != pip_n)
			read_from_pipe(fildes);
		i++;
	}
}