/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:40:51 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/21 17:52:50 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	setup_first_cmd(int i, int infile, int **fds_table)
{
	read_from_infile(infile);
	write_to_pipe(fds_table[0]);
}

void	setup_last_cmd(int i, int outfile, int **fds_table)
{
	read_from_pipe(fds_table[i]);
	write_to_outfile(outfile);
}

void	setup_pipes(int n, int **fds_table, int *pids_arr, int *in_out_f)
{
	int	i;

	i = 0;
	while (i < n && !pids_arr[i])
	{
		if (!i)
			setup_first_cmd(i, in_out_f[0], fds_table);
		read_from_pipe(fds_table[i - 1]);
		write_to_pipe(fds_table[i]);
		i++;
		if (i == n && !pids_arr[i])
			setup_last_cmd(i, in_out_f[1], fds_table);
	}
}
