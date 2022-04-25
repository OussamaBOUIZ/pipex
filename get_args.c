/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:32:45 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/25 13:21:58 by obouizga         ###   ########.fr       */
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

int main(int ac, char **av, char **env)
{
	t_arg  args = get_args(ac, av, env);
	// printf("%d\n", args.in_f);
	// printf("%d\n", args.out_f);
	// printf("%s\n", args.cmd_1->cmd_path);
	// printf("%s\n", args.cmd_2->cmd_path);
	// printf("%s\n", args.cmd_2->cmd_path);
	check_arguments(args);
	// (void)ac;
	// if (access(av[1], X_OK))
	// 	printf("non valid path\n");
	// else
	// 	printf("valid path\n");
	return (0);
}