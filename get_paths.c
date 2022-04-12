/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:43:14 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/12 22:53:15 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_paths(char *path_line)
{
	char	**unsplit_paths;
	char	**paths;

	unsplit_paths = ft_split(path_line, '=');
	paths = ft_split(unsplit_paths[1], ':');
	return (paths);
}
