/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_second_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:12:40 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/17 14:13:55 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_second_cmd(int *fds, int io_fds, char *cmd, char **env)
{
	read_from_pipe(fds);
	write_to_outfile(io_fds);
	check_access_exec(cmd, env);
}
