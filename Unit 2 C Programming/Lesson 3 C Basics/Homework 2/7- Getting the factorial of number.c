/*
 ============================================================================
 Name        : Example 7
 Author      : Mohamed Hazem
 Description : Getting the Factorial of a Number
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num;
	int sum = 1;

	printf("Enter an Integer: ");
	fflush(stdout);
	scanf("%d", &num);

	if (num < 0){
		printf("Error!!! Factorial of Negative Number Doesn't Exist");
	}
	else if (num > 1){
		for (int i = 1 ; i <= num; i++){
			sum *= i;
		}
		printf("Factorial = %d", sum);
	}
	else{
		printf("Factorial = 1");
	}


	return EXIT_SUCCESS;
}

