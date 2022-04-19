#include "pipex.h"

int main(void)

{
	int pid = fork();
	int status;

	if (!pid)
		execve("list.sh", NULL, NULL);
	waitpid(pid, &status, 0);
	return (0);
}