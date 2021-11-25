#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *add_odd(void *args)
{
	int *arr = (int *)args;
	int n = arr[0];
	int *res = (int *)malloc(sizeof(int));
	*res = 0;
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] & 1)
			*res += arr[i];
	}
	return (void *)res;
}

void *add_even(void *args)
{
	int *arr = (int *)args;
	int n = arr[0];
	int *res = (int *)malloc(sizeof(int));
	*res = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!(arr[i] & 1))
			*res += arr[i];
	}
	return (void *)res;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Not enough arguments!\n");
		exit(EXIT_FAILURE);
	}
	int n = argc - 1;
	int *arr = (int *)calloc(n + 1, sizeof(int)), *res_even, *res_odd;
	arr[0] = n;
	for (int i = 0; i < n; i++)
	{
		arr[i + 1] = atoi(argv[i + 1]);
	}
	pthread_t thread_odd, thread_even;
	pthread_create(&thread_odd, 0, &add_odd, (void *)arr);
	pthread_create(&thread_even, 0, &add_even, (void *)arr);
	pthread_join(thread_odd, (void **)&res_odd);
	pthread_join(thread_even, (void **)&res_even);
	printf("The sum of odd is : %d\n", *res_odd);
	printf("The sum of even is : %d\n", *res_even);
	return 0;
}
