/*
 ============================================================================
 Name        : Example 2
 Author      : Mohamed Hazem
 Description : Checking if The Character is Vowel or Consonant
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char alpha;

	printf("Enter an Alphabet: ");
	fflush(stdout);
	scanf("%c", &alpha);


	switch(alpha)
	{
	case 'a':
	case 'A':{
		printf("%c is a Vowel", alpha);
	}
	break;

	case 'e':
	case 'E':{
		printf("%c is a Vowel", alpha);
	}
	break;

	case 'i':
	case 'I':{
		printf("%c is a Vowel", alpha);
	}
	break;

	case 'o':
	case 'O':{
		printf("%c is a Vowel", alpha);
	}
	break;

	case 'u':
	case 'U':{
		printf("%c is a Vowel", alpha);
	}
	break;
	default:
		printf("%c is a Consonant", alpha);
	}



	return EXIT_SUCCESS;
}
