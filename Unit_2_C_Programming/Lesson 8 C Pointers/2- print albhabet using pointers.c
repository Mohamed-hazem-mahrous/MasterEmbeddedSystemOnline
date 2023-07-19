/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : Lesson 8 : C Pointers
 Name        : Example 2
 Description : Print all alphabets using pointers
 ======================================================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main()
{

	char alpha[26];
	int i;
	char *ptr ;

	ptr = alpha ;

	for (i = 0; i < 26; ++i)
	{
		*ptr = i +'A';
		ptr++;
	}

	ptr = alpha;

	printf("The Alphabets are : \n");

	for (i = 0; i < 26; ++i)
	{
		printf("%c\n", *ptr);
		ptr++;
	}


	return 0;
}













