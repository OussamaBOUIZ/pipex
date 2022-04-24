/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 08:42:47 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/23 08:45:45 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(char *cmd, char **env)
{
	char	**paths;
	int		i;

	i = 0;
	paths = get_paths(env[6]);
	while (paths[i])
	{
		
	}
}
