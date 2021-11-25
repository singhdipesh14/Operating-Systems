#include <stdio.h>

int main(int argn, char *args[])
{
	FILE *finp = fopen(args[1], "r"), *fout = fopen(args[2], "w+");
	if (finp == NULL || fout == NULL)
	{
		printf("FIle not found, exiting ... ");
		return 0;
	}
	char c = 0;
	while (c != EOF)
	{
		c = fgetc(finp);
		fputc(c, fout);
	}
	fclose(finp);
	fclose(fout);
	printf("Done\n");
	return 0;
}
