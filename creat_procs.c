/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_procs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:02:45 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/26 08:54:14 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	creat_procs(int n, int *pids_arr, int **fds_table)
// {
// 	int	i;

// 	i = 1;
// 	pids_arr[0] = fork();
// 	while (i < n && check_main_process(pids_arr, i))
// 	{
// 		pipe(fds_table[i - 1]);
// 		pids_arr[i] = fork();
// 		i++;
// 	}
// }

void	creat_link_procs(int n, int **fds_table, int *io_fds);
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (!fork())
		{
			if (!i)
				run_first_cmd(fds_table[i], io_fds, )
		}
		i++;
	}
}
