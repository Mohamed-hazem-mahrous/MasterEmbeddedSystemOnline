/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : Lesson 8 : C Pointers
 Name        : Example 4
 Description : Print all alphabets using pointers
 ======================================================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main()
{

	int arr[15];
	int *ptr = arr;
	int size;

	printf("Input the number of elements to store in the array (max 15) :");
	fflush(stdout);
	scanf("%d", &size);


	printf("Input %d number of elements in the array :\n", size);
	for(int i = 0; i < size; i++){
		printf("Element - %d : ", i + 1);
		fflush(stdout);
		ptr = arr+i;
		scanf("%d", ptr);
	}


	printf("\nThe elements of array in reverse order are :\n");
	for(int i = size - 1; i >= 0; i--){
		ptr = arr + i;
		printf("Element - %d : %d\n", i + 1, *ptr);
	}




	return 0;
}













