/*
 ============================================================================
 Name        : Example 4
 Author      : Mohamed Hazem
 Description : Checking Positive or Negative or Zero
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float num;

	printf("Enter Three Numbers: ");
	fflush(stdout);
	scanf("%f", &num);

	if (num > 0){
		printf("%.2f is a Positive Number", num);
	} else if (num < 0){
		printf("%.2f is a Negative Number", num);
	}else{
		printf("You Entered a 0");
	}


	return EXIT_SUCCESS;
}
