/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_procs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:02:45 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/21 18:04:21 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	creat_procs(int n, int *pids_arr, int **fds_table)
{
	int	i;

	i = 0;
	while (i < n && check_main_process(pids_arr, i))
	{
		pipe(fds_table[i]);
		pids_arr[i] = fork();
		i++;
	}
}
