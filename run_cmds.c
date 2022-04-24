/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 07:11:55 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/23 08:42:28 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_cmds(int n, int *pids_arr, char **av, char **env)
{
	int 	i;
	char	*cmd;
	
	i = 0;
	while (i < n)
	{
		cmd = 
		if (!pids_arr[i])
		{
			execute_cmd(av[i + 3], env);
		}
		i++;
	}
}
