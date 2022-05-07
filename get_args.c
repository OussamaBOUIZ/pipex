/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:32:45 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/07 18:38:49 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_arg	get_args(int ac, char **av, char **env)
{
	t_arg	args;

	if (ac != 5)
		exit(EXIT_SUCCESS);
	args.in_f = open(av[1], O_RDONLY);
	args.out_f = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	args.cmd_1 = get_cmd(av[2], env);
	args.cmd_2 = get_cmd(av[3], env);
	return (args);
}
