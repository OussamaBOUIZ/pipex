/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_first_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:12:02 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/26 09:51:08 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_first_cmd(int *fds, int io_fds, char *cmd, char **env)
{
	read_from_infile(io_fds);
	write_to_pipe(fds);
	check_access_exec(cmd, env);
}
