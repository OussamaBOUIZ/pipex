#include "pipex.h"	

void	dup2_fail(int fd)
{
	printf("Error: dup2 failed: %d\n errno : %d\n", fd, errno);
	exit(EXIT_FAILURE);
}