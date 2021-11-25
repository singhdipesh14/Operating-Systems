#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <locale.h>
#include <langinfo.h>
#include <stdint.h>
char const *sperm(__mode_t mode)
{
	static char local_buff[16] = {0};
	int i = 0;
	// user permissions
	if ((mode & S_IRUSR) == S_IRUSR)
		local_buff[i] = 'r';
	else
		local_buff[i] = '-';
	i++;
	if ((mode & S_IWUSR) == S_IWUSR)
		local_buff[i] = 'w';
	else
		local_buff[i] = '-';
	i++;
	if ((mode & S_IXUSR) == S_IXUSR)
		local_buff[i] = 'x';
	else
		local_buff[i] = '-';
	i++;
	// group permissions
	if ((mode & S_IRGRP) == S_IRGRP)
		local_buff[i] = 'r';
	else
		local_buff[i] = '-';
	i++;
	if ((mode & S_IWGRP) == S_IWGRP)
		local_buff[i] = 'w';
	else
		local_buff[i] = '-';
	i++;
	if ((mode & S_IXGRP) == S_IXGRP)
		local_buff[i] = 'x';
	else
		local_buff[i] = '-';
	i++;
	// other permissions
	if ((mode & S_IROTH) == S_IROTH)
		local_buff[i] = 'r';
	else
		local_buff[i] = '-';
	i++;
	if ((mode & S_IWOTH) == S_IWOTH)
		local_buff[i] = 'w';
	else
		local_buff[i] = '-';
	i++;
	if ((mode & S_IXOTH) == S_IXOTH)
		local_buff[i] = 'x';
	else
		local_buff[i] = '-';
	return local_buff;
}
int main(int argc, char *argv[])
{
	DIR *mydir;
	struct dirent *myfile;
	struct stat mystat;
	if (argc == 1)
		mydir = opendir(".");
	else
		mydir = opendir(argv[1]);
	while ((myfile = readdir(mydir)) != NULL)
	{
		bzero(&mystat, sizeof(mystat));
		stat(myfile->d_name, &mystat);
		printf("%10.10s", sperm(mystat.st_mode));
		printf("\t%d", mystat.st_uid);
		printf("\t%ld\t", mystat.st_size);
		printf("%s\t", ctime(&mystat.st_mtime));
		printf("%s\n", myfile->d_name);
	}
	closedir(mydir);
}
