#include "pipex.h"

int main(int ac, char **av)
{
	(void)ac;
	int fd = open(av[1], O_RDWR);
	printf("fd : %d\n", fd);
	if (fd == -1)
		perror(0);
	return (0);
}
