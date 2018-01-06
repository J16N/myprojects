#include <stdio.h>

int main(int argc, char *argv[])
{
	int inp, ans;
	printf("No. of terms: ");
	scanf("%d", &inp);
	if (inp>=0){
	    for (int i=1; i<(inp+1); i++){
		    ans=ans+(i*i);
	    }
	    printf("So the answer of the series is %d.\n", ans);
	}else{
		printf("No. of terms can never be negetive.\n");
	}
	return 0;
}