/*
 ============================================================================
 Name        : Example 6
 Author      : Mohamed Hazem
 Description : Calculate Sum of Natural Number
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num;
	int sum = 0;

	printf("Enter an Integer: ");
	fflush(stdout);
	scanf("%d", &num);

	for (int i = 0 ; i <= num; i++){
		sum += i;
	}

	printf("Sum = %d", sum);

	return EXIT_SUCCESS;
}

