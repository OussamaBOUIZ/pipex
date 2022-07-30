/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:03:50 by obouizga          #+#    #+#             */
/*   Updated: 2022/07/30 06:44:20 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	write_to_pipe(int *fds)
{
	if (dup2(fds[WRITE_END], STDOUT_FILENO) == -1)
		dup2_fail();
	if (close(fds[READ_END]) == -1)
		close_fail();
}


void	write_to_outfile(int outfile)
{
	if (dup2(outfile, STDOUT_FILENO) == -1)
		dup2_fail();
}


void	read_from_pipe(int *fds)
{
	if (dup2(fds[READ_END], STDIN_FILENO) == -1)
		dup2_fail();
	if (close(fds[WRITE_END]) == -1)
		close_fail();
}


void	read_from_infile(int infile)
{
	if (dup2(infile, STDIN_FILENO) == -1)
		dup2_fail();
}
