/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : 5 C Functions
 Name        : Example 2
 Description : Getting Factorial of a Number
 ======================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int factorial(int num){
    int fac = 1;

    while(num){
    	fac *= num;

		num--;
		factorial(num);
    }
    return fac;
}


int main()
{

	int num, fac;

    printf("Enter Positive Integer: ");
    fflush(stdout);
    scanf("%d", &num);

    fac = factorial(num);
    printf("Factorial of %d is: %d", num, fac);



    return EXIT_SUCCESS;
}
