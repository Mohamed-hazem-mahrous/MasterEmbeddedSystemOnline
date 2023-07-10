/*
 ============================================================================
 Name        : Example 5
 Author      : Mohamed Hazem
 Description : Getting the ASCII Code of Character Entered By the User
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char chr;

	printf("Enter The Character: ");
	fflush(stdout);

	scanf("%c", &chr);

	printf("ASCII of %c : %d", chr, chr);
	return EXIT_SUCCESS;
}

