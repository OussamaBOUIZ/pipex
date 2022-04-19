/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chekc_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:58:53 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/19 12:35:27 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_commands(int ac, char **av, char **env)
{
	int		i;
	int		j;

	i = 1;
	while (i < ac - 2)
		check_access(av[i++], env);
	return (0);
}
