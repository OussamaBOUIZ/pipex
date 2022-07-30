/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:58:04 by obouizga          #+#    #+#             */
/*   Updated: 2022/07/24 12:46:38 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd	**get_commands(int ac, char **av, char **env)
{
	int		i;
	t_cmd	**commands;

	commands = malloc(sizeof(t_cmd *) * (ac - 3));
	if (!commands)
		malloc_fail();
	i = 0;
	while (i < ac - 3)
	{
		commands[i] = get_cmd(av[i + 2], env);
		if (!commands[i])
		{
			free(commands);
			return (NULL);
		}
		i++;
	}
	return (commands);
}
