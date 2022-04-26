/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fds_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 22:22:26 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/19 22:32:07 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**create_fds_table(int pipes_n)
{
	int	**fds_table;
	int	i;

	fds_table = malloc(sizeof(int *) * (pipes_n + 1));
	i = 0;
	while (i < pipes_n)
		fds_table[i++] = malloc(sizeof(int) * 2);
	fds_table[i] = 0;
	return (fds_table);
}
