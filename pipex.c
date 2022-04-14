/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:52:40 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/14 01:20:43 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
// ./pipex infile "ls -l" "wc -l" outfile
//	[0]    [1]      [2]    [3]    [4]
int	main(int ac, char **av, char **env)
{
	char	**paths;
	pid_t	pid;
	int		fds[2];

	(void) ac;
	pipe(fds);
	pid = fork();
	paths = get_paths(env[6]);
	read_infile(av[1]);
	if (!pid)
		check_access_exec(paths, av, env);
	return (0);
}
