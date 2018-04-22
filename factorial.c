#include <stdio.h>

int factorial(int num)
{
	if (!num)
		return 1;
	else
		return (num * factorial(num - 1)); //recurssion
}

int main(int argc, char *argv[])
{
	int ans;
	printf("\n-----------------------------------\n");
	printf("THIS PROGRAM WILL DO THE FACTORIAL");
	printf("\n-----------------------------------\n");
	printf("\nFactorial Of: ");
	scanf("%d", &ans);
	if (ans >= 1)
		printf("\nAns:- %d\n\n", factorial(ans));
	else
		printf("\nChoose the number greater than one or equal to one.\n\n");

	return 0;
}
