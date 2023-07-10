/*
 ============================================================================
 Name        : Example 1
 Author      : Mohamed Hazem
 Description : Checking if The Number is Odd or Even
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num1, mod;

	printf("Enter an Integer You Want to Check: ");
	fflush(stdout);
	scanf("%d", &num1);

	mod = num1 % 2;

	if (mod == 1){
		printf("The Number %d is odd", num1);
	}else{
		printf("The Number %d is even", num1);
	}


	return EXIT_SUCCESS;
}
