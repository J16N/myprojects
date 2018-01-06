#include<stdio.h>

int imprime(int num)
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
	if (sum==1)
		return 0;
}

int main(int argc, char *argv[])
{
	int beg,end;
	printf("\nEnter the starting number: ");
	scanf("%d",&beg);
	printf("\nEnter the ending number: ");
	scanf("%d",&end);
	if (beg<0||end<=0||end<=beg)
		printf("\nChoose the range from the increasing order of positive infinity.");
	else{
		printf("\nSo the prime numbers between %d and %d are as follows: ",beg,end);
		for (int i=0;beg<(end+1);beg++){
			if (imprime(beg)==0){
				printf("\n%d) %d", (i+1),beg);
				i++;
			}
		}
	}
}
	