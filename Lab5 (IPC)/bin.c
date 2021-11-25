#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fout;
	int num = 0;
	fout = fopen("my_binary_file.bin", "wb+");
	printf("Enter 4 numbers of your choice: \n");
	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &num);
		fwrite(&num, sizeof(int), 1, fout);
	}
	printf("Writing done!\n");
	fclose(fout);
	printf("Reading the binary file now\n");
	fout = fopen("my_binary_file.bin", "rb");
	for (int i = 0; i < 4; i++)
	{
		fread(&num, sizeof(int), 1, fout);
		printf("%d\n", num);
	}
	fclose(fout);
}