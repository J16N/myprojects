/* This is the program that prints a triangle with one single for loop :)
 * I essentially wanted to make a pascal triangle but ended by making this.

 * Need to think about things!
 */

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
	int inp,len;
	long long ans=0,ans1;
	printf("Triangle Row: ");
	scanf("%d", &inp);
	len=inp;
	for (int i=0; i<inp; i++, len++){
		ans=pow(10,i)+ans;
		ans1=pow(ans,2);
		printf("%*lld\n", len, ans1); // alignment matters :P
	}
	return 0;
}
