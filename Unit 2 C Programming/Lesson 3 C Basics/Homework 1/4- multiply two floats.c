/*
 ============================================================================
 Name        : Example 4
 Author      : Mohamed Hazem
 Description : Multiply Two Floats Entered by the User
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float num1, num2, mulNum;

	printf("Enter Two numbers: ");
	fflush(stdout);

	scanf("%f", &num1);
	scanf("%f", &num2);

	mulNum = num1 * num2;

	printf("The Summation is : %f", mulNum);
	return EXIT_SUCCESS;
}

