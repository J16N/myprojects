#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void clear_stream(FILE *in)
{
	int ch;
	clearerr(in);
	do
		ch = getc(in);
	while (ch != '\n' && ch != EOF);
	clearerr(in);
}

int nodigit(int num)
{
	if (num > 0) {
		int count = 0;
		while (num > 0) {
			num /= 10;
			count++;
		}
		return count;
	} else {
		int count = 1;
		while (abs(num) > 0) {
			num /= 10;
			count++;
		}
		return count;
	}
}

int maxnum(int row, int col, 
	int array[row][col])
{
	int i = 0, j = 0;
	int num = array[0][0];
	int negnum = array[0][0];
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (num < array[i][j])
				num = array[i][j];
		}
	}
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (negnum > array[i][j])
				negnum = array[i][j];
		}
	}
	if (nodigit(num) > nodigit(negnum))
		return num;
	else
		return negnum;
}

int main(int argc, char *argv[])
{
	int row, col, i = 0, j = 0, peek;

	printf("\n-----------------------"
		"-----------------------------");
	printf("\n THIS PROGRAM WILL GOING "
		"TO PERFORM MATRIX ADDITION\n");
	printf("-------------------------"
		"---------------------------\n");
	printf("\n MATRICES ROWS: ");
	while (scanf("%d", &row) != 1 || 
		((peek = getchar()) != EOF && 
			!isspace(peek))) {
		clear_stream(stdin);
		printf(" Invalid integer. "
			"Please try again.\n MATRICES ROWS: ");
		fflush(stdout);
	}
	if (peek != EOF)
		clearerr(stdin); ungetc(peek, stdin);
	clear_stream(stdin);

	printf(" MATRICES COLUMNS: ");
	while (scanf("%d", &col) != 1 || 
		((peek = getchar()) != EOF && 
			!isspace(peek))) {
		clear_stream(stdin);
		printf(" Invalid integer. "
			"Please try again.\n MATRICES COLUMNS: ");
		fflush(stdout);
	}
	if (peek != EOF)
		clearerr(stdin); ungetc(peek, stdin);
	clear_stream(stdin);


	int myarray1[row][col], myarray2[row][col], 
	result[row][col];
	printf("\n Make sure to add %d number "
		"of items in both the \n", row * col);
	printf(" matrices. Items more than that "
		"will automatically \n");
	printf(" be dismissed. Type the numbers, "
		"row wise instead \n");
	printf(" of column wise to get the "
		"desired matrix. Make \n");
	printf(" sure to add space while "
		"typing different numbers \n");
	printf(" in the matrices.\n");
	

	printf("\n MATRIX-1: ");
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			while (scanf("%d", &myarray1[i][j]) != 1 || 
				((peek = getchar()) != EOF && 
					!isspace(peek))) {
				clear_stream(stdin);
				printf(" Invalid integer. "
						"Please try again.\n MATRIX-1: ");
				fflush(stdout);
			}
			if (peek != EOF)
				clearerr(stdin); ungetc(peek, stdin);
		}
	}
	clear_stream(stdin);
	printf(" MATRIX-2: ");
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			while (scanf("%d", &myarray2[i][j]) != 1 || 
				((peek = getchar()) != EOF && 
					!isspace(peek))) {
				clear_stream(stdin);
				printf(" Invalid integer. "
						"Please try again.\n MATRIX-2: ");
				fflush(stdout);
			}
			if (peek != EOF)
				clearerr(stdin); ungetc(peek, stdin);
		}
	}
	clear_stream(stdin);


	printf("\n The Matrices are:");
	for (i = 0; i < row; i++) {
		printf("\n |");
		for (j = 0; j < col; j++)
			printf("%*d ",
				 nodigit(maxnum(row, col, myarray1)),
				  myarray1[i][j]);
		printf("\b|     |");
		for (j = 0; j < col; j++)
			printf("%*d ",
				 nodigit(maxnum(row, col, myarray2)),
				  myarray2[i][j]);
		printf("\b|");
	}
	printf("\n\n");


	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++)
			result[i][j] = myarray1[i][j] + 
				myarray2[i][j];
	}


	printf(" Adding the matrices we get: ");
	for(i = 0; i < row; i++) {
		printf("\n |");
		for (j = 0; j < col; j++)
			printf("(%*d+%*d) ",
				 nodigit(maxnum(row, col, myarray1)),
				  myarray1[i][j], 
				 nodigit(maxnum(row, col, myarray2)),
				  myarray2[i][j]);
		printf("\b| -----------> |");
		for(j = 0; j < col; j++)
			printf("%*d ",
			 nodigit(maxnum(row, col, result)),
			  result[i][j]);
		printf("\b|");
	}
	printf("\n\n---------------------"
		"-------------------------------\n\n");

	return 0;
}