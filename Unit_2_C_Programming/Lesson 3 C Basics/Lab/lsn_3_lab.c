/*
 ======================================================================================================================
 Name        : Lesson 3 Lab
 Author      : Mohamed Hazem
 Description : counter
 ======================================================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	for (int i = 0; i < 10; i++){
		for(int j = i ; j < 10; j++){
			printf("%d ", j);
		}
		printf("\n");}

	return EXIT_SUCCESS;
}


