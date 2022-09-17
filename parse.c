/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:48:52 by obouizga          #+#    #+#             */
/*   Updated: 2022/09/17 16:04:04 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


t_arg	get_args(int ac, char **av, char **env)
{
	t_arg	args;

	if (ac != 5)
		exit(EXIT_SUCCESS);
	args.in_f = open(av[1], O_RDONLY);
	args.out_f = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	args.cmd_1 = get_cmd(av[2], env);
	args.cmd_2 = get_cmd(av[3], env);
	return (args);
}


t_b_arg	get_args_bonus(int ac, char **av, char **env)
{
	t_b_arg	args_b;
	int		i;

	i = 0;
	args_b.n_cmd = ac - 3;
	args_b.in_f = open(av[1], O_RDONLY);
	args_b.out_f = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	args_b.cmds = get_commands(ac - 3, av + 2, env);
	return (args_b);
}


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


t_cmd	**get_commands(int n, char **av, char **env)
{
	int		i;
	t_cmd	**commands;

	commands = malloc(sizeof(t_cmd *) * (n));
	if (!commands)
		malloc_fail();
	i = 0;
	while (i < n)
	{
		commands[i] = get_cmd(av[i], env);
		if (!commands[i])
		{
			free(commands);
			return (NULL);
		}
		i++;
	}
	return (commands);
}


char	**get_paths(char **env)
{
	int		i;
	char	**paths;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp("PATH=", env[i], 5))
			break ;
		i++;
	}
	paths = ft_split(&env[i][5], ':');
	return (paths);
}