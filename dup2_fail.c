#include "pipex.h"

void	dup2_fail(void)
{
	printf("Error: dup2 failed\n");
	exit(EXIT_FAILURE);
}