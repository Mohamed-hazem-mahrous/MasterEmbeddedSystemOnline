/*
 ============================================================================
 Name        : Example 3
 Author      : Mohamed Hazem
 Description : Getting the Largest Number of 3 Numbers
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float num1, num2, num3, max;

	printf("Enter Three Numbers: ");
	fflush(stdout);
	scanf("%f %f %f", &num1, &num2, &num3);

	max = (num1 > num2 ? num1:num2);


	max = (max > num3 ? max:num3);


	printf("The Largest Number is %.2f", max);

	return EXIT_SUCCESS;
}
