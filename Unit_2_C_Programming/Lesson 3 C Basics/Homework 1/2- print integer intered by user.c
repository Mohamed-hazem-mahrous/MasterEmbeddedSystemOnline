/*
 ============================================================================
 Name        : Example 2
 Author      : Mohamed Hazem
 Description : Print an Integer Entered by the User
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int tstnum;

	printf("Enter Integer number: ");
	fflush(stdout);

	scanf("%d", &tstnum);
    
	printf("Your Number is : %d", tstnum);
	return EXIT_SUCCESS;
}
