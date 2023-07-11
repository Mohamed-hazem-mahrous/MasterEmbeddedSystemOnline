/*
 ======================================================================================================================
 Name        : Example 3
 Author      : Mohamed Hazem
 Description : Find Transpose of Matrix
 ======================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	float mat[100][100], matt[100][100];
	int r, c, i, j;

	printf("Enter Number of Rows and Columns of the Matrix: ");
	fflush(stdout), fflush(stdin);
	scanf("%d", &r);
	scanf("%d", &c);


	printf("Enter Elements of the Matrix:\n");
	fflush(stdout), fflush(stdin);
	for(i = 0; i < r; i++){
		for(j = 0; j < c; j++){
			printf("Enter element a%d%d: ", i+1, j+1);
			fflush(stdout), fflush(stdin);
			scanf("%f", &mat[i][j]);
		}
	}



	for(i = 0; i < r; i++){
		for(j = 0; j < c; j++){
			matt[j][i] = mat[i][j];
		}
	}



	printf("Entered Matrix: \n");
	fflush(stdout), fflush(stdin);
	for(i = 0; i < r; i++){
		for(j = 0; j < c; j++){
			printf("%.2f  ", mat[i][j]);
			fflush(stdout), fflush(stdin);
		}
		printf("\n");
	}



	printf("Transpose Matrix: \n");
	fflush(stdout), fflush(stdin);
	for(i = 0; i < c; i++){
		for(j = 0; j < r; j++){
			printf("%.2f  ", matt[i][j]);
			fflush(stdout), fflush(stdin);
		}
		printf("\n");
	}

	return EXIT_SUCCESS;
}

