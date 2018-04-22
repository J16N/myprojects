/* This program reverses the any given string.
 * There is no story behind this :(
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	// variables declaration
	char *arr, i = 0, ind = 0;
	arr = calloc(1, sizeof(char));
	// dynamic memory allocation, exit out
	while (*(arr + ind) != '\n'){
		scanf("%c", (arr + i));
		ind = i; // recording size
		i++;
		arr = realloc(arr, (i + 1) * sizeof(char));
	}
	for (i = ind; i > -1; i--)
		printf("%c", *(arr + i));
	
	// always return the memory when the work is finished :)
	free(arr);
	printf("\n");
	return 0;
}
