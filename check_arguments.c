/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:35:29 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/19 11:58:29 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
// ./pipex file1 cmd1 cmd2 file2
// 	[0]     [1]   [2]  [3]  [4]

int check_arguments(int ac, char **av, char **env)
{
	check_infile(av);
	check_commands(ac, av, env);
	return (0);
}