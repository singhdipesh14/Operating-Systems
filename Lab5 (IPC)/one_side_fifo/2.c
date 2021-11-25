#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <string.h>
#define FIFO_NAME "my_queue"
#define BUFFER_SIZE 10000
int main(int argc, char *argv[])
{
	int pipe_fd, res, open_mode1 = O_WRONLY, open_mode2 = O_RDONLY, n = 0;
	char buffer[BUFFER_SIZE + 1];
	if (access(FIFO_NAME, F_OK) == -1)
	{
		res = mkfifo(FIFO_NAME, 0777);
		if (res != 0)
		{
			fprintf(stderr, "Could not create file%s\n", FIFO_NAME);
			exit(EXIT_FAILURE);
		}
	}
	printf("In program 2 right now and will start communicating with program 1\n");
	while (1)
	{
		pipe_fd = open(FIFO_NAME, open_mode1);
		printf("\nEnter Text to send program 1: ");
		fgets(buffer, BUFFER_SIZE, stdin);
		res = write(pipe_fd, buffer, BUFFER_SIZE);
		close(pipe_fd);
		pipe_fd = open(FIFO_NAME, open_mode2);
		printf("\nText from program 1: ");
		res = read(pipe_fd, buffer, BUFFER_SIZE);
		if (strstr(buffer, "exit") != NULL)
		{
			break;
		}
		printf("%s\n", buffer);
		close(pipe_fd);
	}
	close(pipe_fd);
	printf("Process %d Finished\n", getpid());
	exit(EXIT_SUCCESS);
}