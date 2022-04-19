#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	execve("/bin/ls", NULL, env);
	printf("Hello world\n");
	return (0);
}
