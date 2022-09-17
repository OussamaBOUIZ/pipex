/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:53:53 by obouizga          #+#    #+#             */
/*   Updated: 2022/09/17 15:54:11 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	check_slash(char *s)
{
	while (*s)
		if (*(s++) == '/')
			return (1);
	return (0);
}


void	check_args_bonus(t_b_arg args_b)
{
	int	i;

	i = -1;
	if (args_b.in_f == -1)
	{
		perror(0);
		exit(EXIT_FAILURE);
	}
	while (++i < args_b.n_cmd)
	{
		if (!args_b.cmds[i])
		{
			ft_putstr_fd("COMMAND NOT FOUND\n", 2);
			exit(EXIT_FAILURE);
		}
	}
	// printf("VALID ARGUMENTS DUDE\n");
}
