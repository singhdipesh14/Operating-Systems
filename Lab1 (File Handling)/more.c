#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argn, char *args[])
{
	if (argn < 3)
	{
		printf("Please Enter Correct arguments");
		return 0;
	}
	char files[100][100], line[100], c, temp;
	int cnt = 0, lines;
	for (int i = 1, j = 0; i < argn; i++, j++)
	{
		strcpy(files[j], args[i]);
		printf("%s\n", files[j]);
	}
	for (int i = 0; i < argn - 1; i++)
	{
		lines = 0;
		int finp = open(files[i], O_RDONLY);
		if (finp == -1)
		{
			printf("File not found, exiting ...");
			return 0;
		}
		while (read(finp, &c, 1) != 0)
		{
			if (c != '\n')
				line[cnt++] = c;
			else
			{
				line[cnt] = '\0';
				lines++;
				cnt = 0;
				if (lines == 20)
				{
					scanf("%c", &temp);
					printf("---\n\n");
				}
				printf("Line %d: %s\n", lines, line);
			}
		}
		close(finp);
	}

	return 0;
}
