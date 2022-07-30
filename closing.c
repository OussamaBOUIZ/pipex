/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 08:30:21 by obouizga          #+#    #+#             */
/*   Updated: 2022/07/30 16:14:19 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fds( int *fds)
{
	if (close(fds[WRITE_END]) == -1)
		close_fail();
	if (close(fds[READ_END]) == -1)
		close_fail();
}

