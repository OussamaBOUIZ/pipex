/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:30:35 by obouizga          #+#    #+#             */
/*   Updated: 2022/09/17 16:49:34 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    close_fail(int fd)
{
        dprintf(2, "Error: Close failed : %d\n", fd);
        exit(EXIT_FAILURE);
}

void    dup2_fail(int fd)
{
        dprintf(2, "Error: dup2 failed: %d\n errno : %d\n", fd, errno);
        exit(EXIT_FAILURE);
}

void    execve_fail(void)
{
        dprintf(2, "Error: Execve failed\n");
        exit(EXIT_FAILURE);
}

void    fork_fail(void)
{
        dprintf(2, "Error : fork failed \n");
        exit(EXIT_FAILURE);
}


void    malloc_fail(void)
{
        dprintf(2, "Malloc failed\n");
        exit(EXIT_FAILURE);
}

void    pipe_fail(void)
{
        dprintf(2, "Error: pipe fail\n");
        exit(EXIT_FAILURE);
}

void	_errno(void)
{
	dprintf(2, "errno : %i\n", errno);
	exit(0);
}