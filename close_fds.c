/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:51:19 by obouizga          #+#    #+#             */
/*   Updated: 2022/08/11 11:29:45 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fds(int **fds_table, int pipes_n, int j)
{
	int	i;

	i = -1;
	while (++i < pipes_n)
 	{
		if (i != j)
		{
			close(fds_table[i][0]);
			close(fds_table[i][1]);
		}
	}	
}