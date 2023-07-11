/*
 ======================================================================================================================
 Name        : Example 2
 Author      : Mohamed Hazem
 Description : Calculating The Average Using an Array
 ======================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	float mat1[100];
	int i, n;
	float avg;

	printf("Enter the Number of Data:");
	fflush(stdout), fflush(stdin);
	scanf("%d", &n);

	if (n > 100) {
		printf("Error!!! The Number Is Too Large\nPlease Write Number Lower Than 100:");
		fflush(stdout), fflush(stdin);
	}
	else {
		for(i = 0; i < n; i++){
			printf("%d. Enter number: ", i+1);
			fflush(stdout), fflush(stdin);
			scanf("%f", &mat1[i]);
		}

		for(i = 0; i < n; i++){
			avg += mat1[i];
		}

		avg /= n;

		printf("Average is %.2f", avg);
		fflush(stdout), fflush(stdin);

	}
	return EXIT_SUCCESS;
}

