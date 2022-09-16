/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:03:50 by obouizga          #+#    #+#             */
/*   Updated: 2022/09/16 19:20:13 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	read_from_infile(int infile)
{
	if (dup2(infile, STDIN_FILENO) == -1)
		dup2_fail(infile);
}

void	write_to_pipe(int *fds)
{
	if (dup2(fds[WRITE_END], STDOUT_FILENO) == -1)
		dup2_fail(fds[WRITE_END]);
	if (close(fds[READ_END]) == -1)
		close_fail();
}

void	read_from_pipe(int *fds)
{
	if (dup2(fds[READ_END], STDIN_FILENO) == -1)
		dup2_fail(fds[READ_END]);
	if (close(fds[WRITE_END]) == -1)
		close_fail();
}

void	write_to_outfile(int outfile)
{
	if (dup2(outfile, STDOUT_FILENO) == -1)
		dup2_fail(outfile);
	dprintf(2, "write to : %d\n", outfile);
}

