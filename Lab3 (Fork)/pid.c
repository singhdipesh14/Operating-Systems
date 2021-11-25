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
		printf("Executing child process\nProcess ID : %d\nParent Process ID : %d\nChild Process ID : %d\nExiting child ...\n", getpid(), getppid(), pid);
		exit(0);
	default:
		wait(&status);
		printf("Executing parent process\nChild status returned : %d\nProcess ID : %d\nParent Process ID : %d\nChild Process ID : %d\nExiting parent ...\n", status, getpid(), getppid(), pid);
	}
	return 0;
}
