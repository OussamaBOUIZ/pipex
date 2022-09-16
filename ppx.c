/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:06:23 by obouizga          #+#    #+#             */
/*   Updated: 2022/09/16 07:45:05 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int		**fds_tbl;
	t_b_arg	args_b;
	int		pipes_n;

	pipes_n = ac - 4;
	args_b = get_args_bonus(ac, av, env);
	check_args_bonus(args_b);
	fds_tbl = create_fds_table(pipes_n);
	creat_link_exec(fds_tbl, args_b, env);
	// * wait_all(); this was responsible for the hanging 
	return (0);
}
