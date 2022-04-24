#include "pipex.h"

int main(int ac, char **av)
{
	(void)ac;
	int fd = open(av[1], O_RDONLY);

	if (fd == -1)
		perror(av[1]);
	return (0);
}