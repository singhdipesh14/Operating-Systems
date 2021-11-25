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
		printf("Executing child process of main program\n");
		printf("_____\n");
		execlp("./q1", "q1", NULL);
		exit(0);
	default:
		wait(&status);
		printf("_____\nExecuting parent process of main program\nChild status returned : %d\nExiting parent of main program ...\n", status);
	}
	return 0;
}
