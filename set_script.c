/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_script.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 10:07:06 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/25 09:12:07 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	set_script(char *s, t_cmd *cmd)
{
	int	n;

	n = access(s, X_OK);
	printf("access returns %i\n", n);
	if (check_slash(s))
	{	
		if (!access(s, X_OK))
		{
			cmd->cmd_path = ft_strdup(s);
			cmd->cmd_op = 0;
			return (1);
		}
		else
		{
			printf("cmd fukck");
			free(cmd);
			cmd = 0;
			printf(" %p\n", cmd);
			return (1);
		}
	}
	return (0);
}
