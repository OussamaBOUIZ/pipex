/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:52:15 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/24 17:28:43 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd	*get_cmd(char *s, char **env)
{
	t_cmd	*cmd;
	char	**paths;
	int		i;

	cmd = malloc(sizeof(t_cmd *));
	if (!cmd)
		return (NULL);
	if (set_script(s, cmd))
		return (cmd);
	i = -1;
	cmd->cmd_op = ft_split(s, ' ');
	paths = get_paths(env);
	while (++i < 6)
	{
		if (s[0] == '/')
			cmd->cmd_path = ft_strdup(s);
		else
			cmd->cmd_path = ft_strjoin_s(paths[i], cmd->cmd_op[0]);
		if (!access(cmd->cmd_path, X_OK))
			return (cmd);
		free(cmd->cmd_path);
	}
	free(cmd->cmd_op);
	return (NULL);
}
