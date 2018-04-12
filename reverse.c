/*
0 1 2 3 4
9 8 7 6 5
10 11 12 13 14
19 18 17 16 15
BY MR. RABBIT */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	// variables declaration
	int *arr, i = 0, j = 1, size = 0;
	arr = calloc(1, sizeof(int));
	// dynamic memory allocation, exit out
	// of the loop by inputting something (except
	// numbers) so that scanf() returns 0
	while (scanf("%d", (arr + i))){
		size = i + 1; // recording size
		i++;
		arr = realloc(arr, (i + 1) * sizeof(int));
	}
	// set i to 0 so that we can use it to print arrays.
	i = 0;
	printf("\nSize: %d\n", size); // size of array
	for (j = 1; j <= (size / 5); j++) {
		// print the correct order in odd number of row
		// and reverse order in even number of row
		if (!(j % 2)) {
			printf("\n");
			for (i = (j * 5) - 1; i > ((j - 1) * 5) - 1; i--)
				printf("%d ", *(arr + i));
		} else {
			printf("\n");
			for (i = ((j - 1) * 5); i < j * 5; i++)
				printf("%d ", *(arr + i));
		}
	}
	printf("\n");
	return 0;
}