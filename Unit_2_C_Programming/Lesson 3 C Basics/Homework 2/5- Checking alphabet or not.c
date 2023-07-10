/*
 ============================================================================
 Name        : Example 5
 Author      : Mohamed Hazem
 Description : Check if Alphabet or not
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
//	A is 65
//	z is 122
//	so the alphabet is between 65 and 122
	
	char chr;

	printf("Enter a Character: ");
	fflush(stdout);
	scanf("%c", &chr);

	if (chr >= 65 && chr <= 122){
		printf("%c is an Alphabet", chr);
	}else{
		printf("%c is not an Alphabet", chr);
	}

	return EXIT_SUCCESS;
}