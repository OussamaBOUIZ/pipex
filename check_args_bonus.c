/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:19:14 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/06 11:12:08 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args_bonus(t_b_arg args_b)
{
	int	i;

	i = -1;
	if (args_b.in_f == -1)
	{
		perror(0);
		exit(EXIT_FAILURE);
	}
	while (++i < args_b.n)
	{
		if (!args_b.cmds[i])
		{
			ft_putstr_fd("COMMAND NOT FOUND\n", 2);
			exit(EXIT_FAILURE);
		}
	}
	// printf("VALID ARGUMENTS DUDE\n");
}
