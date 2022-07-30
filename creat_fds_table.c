/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_fds_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 22:22:26 by obouizga          #+#    #+#             */
/*   Updated: 2022/07/30 07:31:18 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**create_fds_table(int pipes_n)
{
	int	**fds_table;
	int	i;

	fds_table = malloc(sizeof(int *) * (pipes_n));
	i = 0;
	while (i < pipes_n)
		fds_table[i++] = malloc(sizeof(int) * 2);
	return (fds_table);
}
// infile.txt "grep ^a" "sort -r" "head -10" "uniq -c" wc  outfile.txt
