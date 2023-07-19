/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : Lesson 8 : C Pointers
 Name        : Example 3
 Description : Reverse String using pointers
 ======================================================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main()
{

	char str[100];
	char *ptr = str;
	char *rev_ptr;
	int size;
	char temp;

	printf("Enter String :");
	fflush(stdout);
	gets(str);

	size = strlen(str);

	rev_ptr = str + size - 1;

	for(int i = 0; i < size / 2; i++){
		temp = *ptr;
		*ptr = *rev_ptr;
		*rev_ptr = temp;

		ptr++;
		rev_ptr--;
	}

	printf("Reverse String is : %s ", str);



	return 0;
}













