/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:55:39 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/17 09:40:06 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	write_to_pipe(int *fds)
{
	dup2(fds[WRITE_END], STDOUT_FILENO);
	close(fds[READ_END]);
}
