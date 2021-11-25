#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	int status;
	pid = fork();
	switch (pid)
	{
	case -1:
		printf("Error occured, exiting ...\n");
		exit(-1);
	case 0:
		printf("Executing child process\nExiting child ...\n");
		exit(0);
	default:
		sleep(5);
		printf("Executing parent process\nChild status returned : %d\nExiting parent ...\n", status);
	}
	return 0;
}
