/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:58:04 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/26 12:16:51 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd	**get_commands(int ac, char **av, char **env)
{
	int		i;
	t_cmd	**commands;

	commands = malloc(sizeof(t_cmd *) * (ac - 3));
	i = 2;
	while (i < ac - 1)
	{
		commands[i] = get_cmd(av[i], env);
		if (!commands[i])
		{
			free(commands);
			retunr (NULL);
		}
		i++;
	}

	return (commands);
}
