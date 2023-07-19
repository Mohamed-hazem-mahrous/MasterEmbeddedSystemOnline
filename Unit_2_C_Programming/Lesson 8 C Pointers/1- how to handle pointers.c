/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : Lesson 8 : C Pointers
 Name        : Example 1
 Description : demonstrate how to handle the pointers in the program.
 ======================================================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main()
{

	int m = 29 ;
	int *ab = &m;

	printf("Address of m : 0x%p\n", &m);
	printf("Value of m : %d\n",m);

	*ab = 29;

	printf("\nAddress of pointer ab : 0x%p\n", ab);
	printf("Content of pointer ab : %d\n",*ab);

	m = 34;

	printf("\nAddress of pointer ab : 0x%p\n", ab);
	printf("Content of pointer ab : %d\n",*ab);

	*ab = 7;

	printf("\nAddress of m : 0x%p\n", &m);
	printf("Value of m : %d\n",m);



	return 0;
}













