/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : 5 C Functions
 Name        : Example 4
 Description : Calculate Power of Number Using Recursion
 ======================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int power_recursion(int po, int ba){
	int res = ba;

	while(po - 1){
		res *= ba;

		po--;
		power_recursion(po, ba);
	}
	return res;
}

int main()
{

    int base;
    int power;
    int result;

    printf("Enter a Base Number: ");
    fflush(stdout);
    scanf("%d", &base);

    printf("Enter a Power Number(Positive Integer): ");
	fflush(stdout);
	scanf("%d", &power);

	result = power_recursion(power, base);

	printf("%d ^ %d = %d", base, power, result);




    return EXIT_SUCCESS;
}
