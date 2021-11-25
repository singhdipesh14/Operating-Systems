#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argn, char *args[])
{
	if (argn < 2)
	{
		printf("Incorrect arguments, expected 1, got %d\n", argn - 1);
		return 0;
	}
	struct stat file_stat;
	int return_value = stat(args[1], &file_stat);
	if (return_value != 0)
	{
		perror("stat");
		return 1;
	}
	printf("File : %s ---- Inode : %ld\n", args[1], file_stat.st_ino);
	return 0;
}
