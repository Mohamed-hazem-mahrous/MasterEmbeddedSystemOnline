/*
 ======================================================================================================================
 Name        : Example 5
 Author      : Mohamed Hazem
 Description : Search Element in Array
 ======================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	float mat[100], e;
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


	printf("Enter the Element to be Searched: ");
	fflush(stdout);
	scanf("%f", &e);



	for(i = 0 ; i < n ; i++){
		if (e == mat[i]){
			printf("Number Found at Location: %d", i + 1);
			break;
		}
	}
	if (i == n){
		printf("Sorry! Your Number Can't be Found");
	}

	return EXIT_SUCCESS;
}