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
	char *oldpath = args[1];
	char *newpath = "newpath.txt";
	struct stat file_stat;
	printf("Before linking new link\n");
	system("ls");
	int return_value = stat(oldpath, &file_stat);
	if (return_value != 0)
	{
		perror("stat");
		return 1;
	}
	printf("Number of links before linking : %ld\n", file_stat.st_nlink);
	link(oldpath, newpath);
	printf("After linking new link\n");
	system("ls");
	int return_value_2 = stat(newpath, &file_stat);
	if (return_value_2 != 0)
	{
		perror("stat");
		return 1;
	}
	printf("Number of links after linking : %ld\nThe new path is : %s\n", file_stat.st_nlink, newpath);
	unlink(oldpath);
	printf("After unlinking old link\n");
	system("ls");
	int return_value_3 = stat(newpath, &file_stat);
	if (return_value_3 != 0)
	{
		perror("stat");
		return 1;
	}
	printf("Number of links after unlinking : %ld\n", file_stat.st_nlink);
	return 0;
}
