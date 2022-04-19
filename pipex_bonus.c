/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:06:23 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/19 22:44:15 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
	./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
	[0]     [1]   [2]  [3]  [4] ... [n] [n + 1]
	the number of pipes needed for n commands is n - 1
	to get the number of pipes we'll take the total num of args
	and subtract from it 3 (prog infile outfile) so n = args - 3
	then n_pipe = args - 4
	A pipe needs an array of 2 fds
	we'll create an array of int arrays of size 2 {{f1, f2},{f3, f4}, ...,{fn, fm}}
	and then we'll create an int array to hold pids for each fork()
	A function will check if all pids are greater than 0 to make sure we're
	in the calling process
	All fork() calls will have place in the calling process of course
	The fork() comes right after the creation of the pipe
	All pipes will be residing in the main process	  
	How will we pass the output of this process as an input to the next process ??
	pipes(fds)
	The first command reads from infile and the last command writes to outfile
	besides the in-between commands will read from a pipe and write to a pipe
*/

int main(int ac, char **av, char **env)
{
	int	pipes_n;
	int	cmds_n;
	int	**fds_table;
	int	*pids_arr;
	
	//check_arguments(ac, av, env);
	cmds_n = ac - 3;
	pipes_n = cmds_n - 1;
	fds_table = create_fds_table(pipes_n);
	pids_arr = malloc(sizeof(int) * cmds_n);
}
