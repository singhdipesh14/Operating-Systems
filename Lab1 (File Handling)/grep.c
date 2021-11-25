#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argn, char *args[])
{
	int finp = open(args[2], O_RDONLY);
	if (finp == -1)
	{
		printf("File not found, exiting...");
		return 0;
	}
	char buffer[100], c;
	int line = 0;
	while (read(finp, &c, sizeof(c)) > 0)
	{
		if (c != '\n')
		{
			strncat(buffer, &c, 1);
		}
		else
		{
			line++;
			if (strstr(buffer, args[1]) != NULL)
			{
				printf("%d : %s\n", line, buffer);
			}
			buffer[0] = '\0';
		}
	}
	close(finp);
	return 0;
}
