/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:06:23 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/26 08:54:41 by obouizga         ###   ########.fr       */
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

	To allow those processes to communicate between each other will use
	the created pipes:
		READ_FROM_PIPE then WRITE_TO_PIPE
	For the case of the first command it'll go like this:
	 COMMAND 1: should read from the infile and write to the first pipe (write_to_pipe(fds_table[0]))
	 meanwhile COMMAND 2 would also read from the first pipe (read_from_pipe(fds_table[0])) but otherwise
	 write to the second pipe (write_to_pipe(fds_table[1])) and so on ... at the same time the last command 
	 will read from the last pipe (read_from_pipe(fds_table[pipes_n - 1])) and then write to the outfile
	 	// So we conclude that if the command isn't the first cmd nor the last, it should do this:
		 -> read from the prev pipe : read_from_pipe(fds_table[id - 1])
		 -> write to the next pipe : write_to_pipe(fds_table[id])
		 PS: id indicates the positioin of the command.
	How will we find out in which process we are ??
	i = 0 1st child process : pid_table[0] == 0
	i = 1 2nd child process : pid_table[1] == 0
	i = 2 3rd child process : pid_table[2] == 0
	.   .  .    .     .     : .   . .
	.   .  .    .     .     : .   . .
	.   .  .    .     .     : .   . .
	i = n nth child process : pid_table[n] == 0

int main(int ac, char **av, char **env)
{
	int	pipes_n;
	int	cmds_n;
	int	**fds_table;
	int	*pids_arr;
	int	*in_out_f;

	cmds_n = ac - 3;
	pipes_n = cmds_n - 1;
	fds_table = create_fds_table(pipes_n);
	pids_arr = malloc(sizeof(int) * cmds_n);
	creat_procs(cmds_n, pids_arr, fds_table);
	setup_pipes(pipes_n, fds_table, pids_arr, in_out_f);
	run_cmds(cmds_n, av, env);
	return (0);
}
		
*/

int	main(int ac, char **av, char **env)
{
	int		**fds_table;
	t_b_arg	args;
	int		pipes_n;
	int		cmds_n;
	
	cmds_n = ac - 3;
	pipes_n = cmds_n - 1;
	args = get_args_bonus(ac, av, env);
	check_arguments_bonus(args);
	fds_table = create_fds_table(pipes_n);
	creat_link_procs();
}
