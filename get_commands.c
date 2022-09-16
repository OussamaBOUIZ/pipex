/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:58:04 by obouizga          #+#    #+#             */
/*   Updated: 2022/08/11 10:19:14 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd	**get_commands(int n, char **av, char **env)
{
	int		i;
	t_cmd	**commands;

	commands = malloc(sizeof(t_cmd *) * (n));
	if (!commands)
		malloc_fail();
	i = 0;
	while (i < n)
	{
		commands[i] = get_cmd(av[i], env);
		if (!commands[i])
		{
			free(commands);
			return (NULL);
		}
		i++;
	}
	return (commands);
}
