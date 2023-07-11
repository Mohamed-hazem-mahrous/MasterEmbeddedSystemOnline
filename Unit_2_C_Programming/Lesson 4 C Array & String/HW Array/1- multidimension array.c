/*
 ======================================================================================================================
 Name        : Example 1
 Author      : Mohamed Hazem
 Description : Find the Sum of Two Matrix of order 2*2 Using the Multidimensional Array
 ======================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	float mat1[2][2], mat2[2][2];
	int i, j;


    // Getting the First Matrix
	printf("Enter the Elements of 1st matrix: \n");
	fflush(stdout), fflush(stdin);

	for(i = 0; i < 2; i++){
		for(j = 0; j < 2; j++){
			printf("Enter a %d %d: ", i+1, j+1);
			fflush(stdout), fflush(stdin);
			scanf("%f", &mat1[i][j]);
		}

	}



    // Getting The Second Matrix
	printf("Enter the Elements of 2st matrix: \n");
	fflush(stdout), fflush(stdin);

	for(i = 0; i < 2; i++){
		for(j = 0; j < 2; j++){
			printf("Enter b %d %d: ", i+1, j+1);
			fflush(stdout), fflush(stdin);
			scanf("%f", &mat2[i][j]);
		}

	}




    // Summing the Two Matrix
	for(i = 0; i < 2; i++){
		for(j = 0; j < 2; j++){
			mat1[i][j] += mat2[i][j];
		}

	}




    // Printing the Result
	printf("The Sum is: \n");
	fflush(stdout), fflush(stdin);
	for(i = 0; i < 2; i++){
		for(j = 0; j < 2; j++){
			printf("%.1f     ", mat1[i][j]);
			fflush(stdout), fflush(stdin);
		}
		printf("\n");
	}

	return EXIT_SUCCESS;
}

