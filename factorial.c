#include <stdio.h>

int main(int argc, char *argv[])
{
	int inp, ans;
	printf("FACTORIAL OF: ");
	scanf("%d", &inp);
	if (inp>=1){
		ans=inp;
		while (inp>1){
			inp--;
			ans*=inp;
		}
		printf("So the factorial is %ld.\n", ans);
	}else{
		printf("Choose the number greater than one.");
	}
	return 0;
}