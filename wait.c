#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>


int main(void)
{
	int pid = fork();
	int i = 0;
	int n = 0;
	int *status = NULL;
	if (!pid)
		n += 10;
	if (pid)
	{
		wait(status);
		printf("status is %d\n", *status);	
	}
	while (i < 10 + n)
		printf("%d ", i++);
	return (0);
}
