/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_infile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:14:35 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/14 01:16:20 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	read_infile(char *file_path)
{
	int		infile;

	infile = open(file_path, O_RDONLY);
	dup2(infile, STDIN_FILENO);
}
