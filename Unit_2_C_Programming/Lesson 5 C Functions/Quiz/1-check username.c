/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : 5 C Functions
 Name        : Example 1
 Description : Check if input is username or not
 ======================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USERNAME "Mohamed"


int main() {

	char input[50];

	printf("Enter a string: ");
	fflush(stdout);
	gets(input);

	input[strcspn(input, "\n")] = 0;

	if (strcmp(input, USERNAME) == 0) {
		printf("Input string is the same as USERNAME.\n");
	} else {
		printf("Input string is not the same as USERNAME.\n");
	}


    return 0;
}