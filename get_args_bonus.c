/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:52:38 by obouizga          #+#    #+#             */
/*   Updated: 2022/08/11 10:18:38 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_b_arg	get_args_bonus(int ac, char **av, char **env)
{
	t_b_arg	args_b;
	int		i;

	i = 0;
	args_b.n_cmd = ac - 3;
	args_b.in_f = open(av[1], O_RDONLY);
	args_b.out_f = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	args_b.cmds = get_commands(ac - 3, av + 2, env);
	return (args_b);
}
