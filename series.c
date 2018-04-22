/* This program adds all the values of 1^2 + 2^2 + 3^2 + 4^2 + ... + upto n terms
 * Here n is the input given by the user
 * Sadly but there is no such story behind this :(
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
	int n, ans;
	printf("No. of terms: ");
	scanf("%d", &n);
	if (n < 0)
		printf("Number of terms can never be negetive.");
	else {
		ans = ((n * (n + 1) * ((2 * n) + 1)) / 6);
		printf("So the addition is %d.\n", ans);
	}
	
	return 0;
}
