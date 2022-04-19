/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:17:09 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/17 09:41:49 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	read_from_pipe(int *fds)
{
	dup2(fds[READ_END], STDIN_FILENO);
	close(fds[WRITE_END]);
}
