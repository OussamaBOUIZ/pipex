#include "pipex.h"

void	dup2_fail(int fd)
{
	printf("Error: dup2 failed: %d\n", fd);
	exit(EXIT_FAILURE);
}