/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:35:29 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/24 17:25:56 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_arguments(t_arg args)
{
	if (args.in_f == -1)
	{
		perror(0);
		exit(EXIT_FAILURE);
	}
	else if (!args.cmd_1 || !args.cmd_2)
	{
		ft_putstr_fd("COMMAND NOT FOUND\n", 2);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

