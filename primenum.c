/* This program prints all the prime numbers between two given numbers.
 * I made this program just to see whether if the prime numbers are occuring
 * in any pattern or not :) :/
 * You might be now thinking so what's next? "No I didn't find any pattern yet
 * so missed to the Noble Prize :P"
 */

#include<stdio.h>

// check if the number is prime or not
int imprime(int num)
{
	int sum = 0;
	int divisor = (num - 1);
	while (divisor > 0){
		if (!(num % divisor)){
			sum += divisor;
			divisor--;
		} else
			divisor--;
	}
	if (sum == 1)
		return 0;
	else
		return 1;
}

int main(int argc, char *argv[])
{
	int beg, end, i = 0;
	printf("\nEnter the starting number: ");
	scanf("%d", &beg);
	printf("Enter the ending number: ");
	scanf("%d", &end);
	
	// range should be in positive infinity
	if (beg < 0 || end <= 0 || end <= beg)
		printf("\nChoose the range from the increasing order of positive infinity.");
	else {
		printf("\nSo the prime numbers between %d and %d are as follows: ", beg, end);
		for (i = 0 ; beg < (end + 1); beg++) {
			if (!(imprime(beg))) {
				printf("\n%d) %d", (i + 1), beg);
				i++;
			}
		}
		printf("\n");
	}
	
	return 0;
}
