/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access_exec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:58:14 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/19 13:17:42 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_command(char *av, char *path)
{
	char	*cmd;

	if (av[0] == '/')
		cmd = ft_strdup(av);
	else
		cmd = ft_strjoin(path, av);
	return (cmd);
}

// void	check_access_exec(char *av, char **env)
// {
// 	int		i;
// 	char	**args;
// 	char	*cmd_p;
// 	char	**paths;

// 	args = ft_split(av, ' ');
// 	paths = get_paths(env[6]);
// 	i = 0;
// 	while (paths[i])
// 	{
// 		cmd_p = get_command(av, paths[i++]);
// 		if (!access(cmd_p, X_OK))
// 		{
// 			execve(cmd_p, args, env);
// 			free(cmd_p);
// 		}
// 		free(cmd_p);
// 	}
// }

int	check_access(char *s, char **env)
{
	int		i;
	char	**args;
	char	*cmd_p;
	char	**paths;

	args = ft_split(s, ' ');
	paths = get_paths(env[6]);
	i = 0;
	while (paths[i])
	{
		cmd_p = ft_strjoin(paths[i++], s);
		if (!access(cmd_p, X_OK))
			return (1);
	}
	return (0);
}
