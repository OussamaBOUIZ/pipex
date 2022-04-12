/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access_exec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:58:14 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/12 23:01:27 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_access_exec(char **paths, char **av, char **env)
{
	int		i;
	char	**args;
	char	*cmd_p;
	
	args = ft_split(av[2], ' ');
	i = 0;
	while (i < 6)
	{
		cmd_p = ft_strjoin(paths[i++], av[2]);
		if (!access(cmd_p, X_OK))
		{
			execve(cmd_p, args, env);
			free(cmd_p);
		}
		free(cmd_p);
	}
}
