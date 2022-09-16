/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pna.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 07:25:18 by obouizga          #+#    #+#             */
/*   Updated: 2022/09/16 14:40:10 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO making the get_arg_bonus func checking also 

#include "pipex.h"


void	pipex(int ac, char **av, char **env)
{
	int		fildes[2];
	t_b_arg	args_b;
	int		pipes_n;

	pipes_n = ac - 4;
	args_b = get_args_bonus(ac, av, env);
	check_args_bonus(args_b);
	creat_link_exec(fildes, args_b, env);
}