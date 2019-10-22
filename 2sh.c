#include<stdio.h>
#include<sys/types.h>
int main()
{
	printf("\nbefore");
	fork();
	printf("\nafter");
	return 0;
}
