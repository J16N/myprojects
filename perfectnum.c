#include <stdio.h>

int imperfect(int num)
{
	int sum=0;
	int divisor=(num-1);
	while (divisor>0){
		if (num%divisor==0){
			sum+=divisor;
			divisor--;
		}else{
			divisor--;
		}
	}
	if (sum==num){
		return 0;
	}
}
			
int main(int argc, char *argv[])
{
	int beg, end;
	printf("\nEnter the starting number: ");
	scanf("%d", &beg);
	printf("\nEnter the ending number: ");
	scanf("%d", &end);
	
	if (beg<0 || end<0){
		printf("\nChoose the range from positive infinity.");
	}else if (beg=='\n' || end=='\n'){
		printf("Input for all the fields is mandatory.");
	}else{
		printf("\nSo the perfect numbers between %d and %d are as follows: ", beg, end);
		for (int i=0; beg<(end+1); beg++){
			if (imperfect(beg)==0){
					printf("\n%d) %d", (i+1), beg);
					i++;
			}
		}
	}
	return 0;
}