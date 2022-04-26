/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:19:14 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/26 12:29:34 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args_bonus(t_b_arg args_b)
{
	int	i;

	i = 0;
	if (args_b.in_f == -1)
	{
		perror(0);
		exit(EXIT_FAILURE);
	}
	while (!args_b.cmds[i])
}