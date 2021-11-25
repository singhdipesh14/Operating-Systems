
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(int argn, char *args[])
{
	int integer_value = 45;
	float float_value = 3.14;
	char string_value[] = "Hello World";
	char character_value = 'C';
	printf("Integer = %d\nFloat = %f\nString = %s\nHexadecimal = %x\nExponential = %e\n", integer_value, float_value, string_value, integer_value, float_value);
	errno = EPERM;
	printf("Access Error : %m\n");
	return 0;
}
