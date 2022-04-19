/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chekc_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:58:53 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/19 13:18:15 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_commands(int ac, char **av, char **env)
{
	int		i;
	int		j;

	i = 2;
	while (i < ac - 2)
		if (check_access(av[i++], env))
			return (1);
	return (0);
}
