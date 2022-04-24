/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_script.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 10:07:06 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/24 15:01:05 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	set_script(char *s, t_cmd *cmd)
{
	if (check_slash(s))
	{	
		cmd->cmd_path = ft_strdup(s);
		cmd->cmd_op = 0;
		return (1);
	}
	return (0);
}
