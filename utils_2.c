/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:01:07 by obouizga          #+#    #+#             */
/*   Updated: 2022/09/17 16:13:11 by obouizga         ###   ########.fr       */
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

pid_t	ft_fork(void)
{
	pid_t	id;

	id = fork();
	if (id == -1)
		fork_fail();
	return (id);
}
void	display_arr(pid_t *pids, int n)
{
	for (int i = 0; i < n; i++)
		printf("[%d]\n", pids[i]);
}

void	wait_all(void)
{
	while (wait(NULL) != -1)
		continue ;
}
