/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:52:15 by obouizga          #+#    #+#             */
/*   Updated: 2022/08/11 10:32:28 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd	*get_cmd(char *s, char **env)
{
	t_cmd	*cmd;
	char	**paths;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->cmd_op = ft_split(s, ' ');
	paths = get_paths(env);
	while (*paths)
	{
		if (check_slash(s))
			cmd->cmd_path = ft_strdup(cmd->cmd_op[0]);
		else
			cmd->cmd_path = ft_strjoin_s(*(paths++), cmd->cmd_op[0]);
		if (!access(cmd->cmd_path, X_OK | F_OK))
			return (cmd);
		else if (check_slash(s))
		{
			free(cmd->cmd_path);
			return (0);
		}
		free(cmd->cmd_path);
	}
	free(cmd->cmd_op);
	return (NULL);
}
