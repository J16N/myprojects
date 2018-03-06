#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char str1[1000], str2[1000];
	printf("\n----------------------\n");
	printf("  STRING COMPARISON");
	printf("\n----------------------\n");
	printf("\nString-1: "); scanf("%s", str1);
	printf("String-2: "); scanf("%s", str2);
	if (strcmp(str1, str2)) {
		if (strlen(str1) == strlen(str2)) {
			printf("\nThere are %zu characters "
				"in both the string.\n", strlen(str1));
			printf("\n -----    -----");
			printf("\n STR-1    STR-2");
			printf("\n -----    -----");
			for (int i = 0; i < strlen(str1); i++) {
				if (str1[i] == str2[i]) {
					printf("\n  '%c'  =   '%c'", 
						str1[i], str2[i]);
				} else {
					printf("\n  '%c' !=   '%c'", 
						str1[i], str2[i]);
				}
			}
		} else {
			printf("\nThere are %zu characters "
				"in String-1,", strlen(str1));
			printf("\nand %zu characters "
				"in String-2.", strlen(str2));
		}
		printf("\n\nStrings are not equal\n\n");
	} else {
		if (strlen(str1) == strlen(str2)) {
			printf("\nThere are %zu characters "
				"in both the string.\n",
			 strlen(str1));
			printf("\n -----    -----");
			printf("\n STR-1    STR-2");
			printf("\n -----    -----");
			for (int i = 0; i < strlen(str1); i++) {
				printf("\n  '%c'  =   '%c'", 
					str1[i], str2[i]);
			}
		} else {
			printf("\nThere are %zu "
				"characters in String-1,", 
				strlen(str1));
			printf("\nand %zu "
				"characters in String-2.", 
				strlen(str2));
		}
		printf("\n\nStrings are equal\n\n");
	}
	return 0;
}