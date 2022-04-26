#include "pipex.h"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	printf("Actually there's no child proc to wait for here\n");
	printf("the returned value of wait() is %d\n", wait(0));
	return (0);
}