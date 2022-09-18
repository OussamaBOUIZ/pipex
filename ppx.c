/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:06:23 by obouizga          #+#    #+#             */
/*   Updated: 2022/09/18 08:56:33 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int ac, char **av, char **env)
{
	int		fildes[2];
	t_b_arg	args_b;

	args_b = get_args_bonus(ac, av, env);
	check_args_bonus(args_b);
	creat_link_exec(fildes, args_b, env);
}

int	main(int ac, char **av, char **env)
{
	pipex(ac, av, env);
	return (0);
}
