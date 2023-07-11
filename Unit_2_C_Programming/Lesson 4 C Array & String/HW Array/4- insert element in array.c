/*
 ======================================================================================================================
 Name        : Example 4
 Author      : Mohamed Hazem
 Description : Insert Element in Array
 ======================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	float mat[100], mat2[100], e;
	int n, l, i;

	printf("Enter no of Elements: ");
	fflush(stdout);
	scanf("%d", &n);


	printf("Enter the Elements: \n");
	for(i = 0 ; i < n ; i++){
		printf("%d. Enter the Element: ", i+1);
		fflush(stdout);
		scanf("%f", &mat[i]);
	}


	printf("Enter the Element to be Inserted: ");
	fflush(stdout);
	scanf("%f", &e);


	printf("Enter the Location: ");
	fflush(stdout);
	scanf("%d", &l);


	for (i = 0; i < n + 1; i++){
		if (i < l - 1){
			mat2[i] = mat[i];
		}
		else if (i == l - 1){
			mat2[i] = e;
		}
		else{
			mat2[i] = mat[i - 1];
		}
	}



	for(i = 0 ; i < n + 1 ; i++){
		printf("%.1f ", mat2[i]);
		fflush(stdout);
	}
	return EXIT_SUCCESS;
}