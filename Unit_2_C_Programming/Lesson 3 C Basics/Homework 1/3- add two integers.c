
/*
 ============================================================================
 Name        : Example 3
 Author      : Mohamed Hazem
 Description : Adding Two Integers Entered by the User
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num1, num2, SumNum;
	
	printf("Enter Two Integer numbers: ");
	fflush(stdout);
	
	scanf("%d", &num1);
	scanf("%d", &num2);
	
	SumNum = num1 + num2;
	
	printf("The Summation is : %d", SumNum);
	return EXIT_SUCCESS;
}
