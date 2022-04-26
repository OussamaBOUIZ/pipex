/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:28:29 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/26 08:38:34 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files(int *io_fds, char *file1, char *file2)
{
	io_fds[0] = open(file1, O_RDONLY);
	io_fds[1] = open(file2, O_RDWR | O_CREAT | O_TRUNC, 0777);
}
