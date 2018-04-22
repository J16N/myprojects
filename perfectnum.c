/* This program prints all the perfect numbers between two given numbers, ie, in a range :)
 * I made this program when one of my friends approached me at evening in the tuition claiming,
 * "Hey dude, I got a very interesting problem for you. Can you find all the perfect numbers 
 * between two given numbers?" I thought for a while then nodded. "How the fuck can someone find
 * all the perfect numbers between two given numbers if the range is so big?" I returned from the
 * tuition, thought for a while that night and made this shit. I gave it to my friend and later he
 * thanked me for saving his day ;)
 */

#include <stdio.h>

// this method checks if the number is perfect or not :P
int imperfect(int num)
{
	int sum = 0;
	int divisor = (num - 1);
	while (divisor > 0){
		if (num % divisor == 0){
			sum += divisor;
			divisor--;
		}else{
			divisor--;
		}
	}
	if (sum == num){
		return 0;
	}
}
			
int main(int argc, char *argv[])
{
	int beg, end, i = 0;
	printf("\nEnter the starting number: ");
	scanf("%d", &beg);
	printf("\nEnter the ending number: ");
	scanf("%d", &end);
	
	// these if-else is for some really annoying users who just give some random inputs to 
	// your programs and later complained about it -_-
	if (beg  <0 || end < 0) {
		printf("\nChoose the range from positive infinity.");
	} else if (beg == '\n' || end == '\n') {
		printf("Input for all the fields is mandatory.");
	} else {
		printf("\nSo the perfect numbers between %d and %d are as follows: ", beg, end);
		for (i = 0; beg < (end + 1); beg++) {
			if (!(imperfect(beg))) {
					printf("\n%d) %d", (i+1), beg);
					i++;
			}
		}
	}
	return 0;
}
