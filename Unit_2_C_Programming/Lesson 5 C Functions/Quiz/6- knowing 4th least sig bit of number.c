/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : 5 C Functions
 Name        : Example 6
 Description : Knowing the 4th least significant bit of a number
 ======================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get4thBit(int num) {
    return (num >> 3) & 1; // Right-shift the number by 3 bits and perform a bitwise AND with 1 to get the 4th least significant bit
}

int main() {
    int num;

    printf("Enter a number: ");
    fflush(stdout);
    scanf("%d", &num);

    int result = get4thBit(num);

    printf("The 4th least significant bit of %d is %d\n", num, result);
    fflush(stdout);


    return 0;
}