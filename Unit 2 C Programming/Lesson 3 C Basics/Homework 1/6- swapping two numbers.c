
/*
 ============================================================================
 Name        : Example 6
 Author      : Mohamed Hazem
 Description : Swapping two Numbers Given by the User
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float a, b, temp;

	printf("Enter Value of a: ");
	fflush(stdout);
	scanf("%f", &a);

	printf("Enter Value of b: ");
	fflush(stdout);
	scanf("%f", &b);

	temp = a;
	a = b;
	b = temp;

	printf("After Swapping the Value of a is %.2f: ", a);
	printf("\nAfter Swapping the Value of b is %.2f: ", b);


	return EXIT_SUCCESS;
}
