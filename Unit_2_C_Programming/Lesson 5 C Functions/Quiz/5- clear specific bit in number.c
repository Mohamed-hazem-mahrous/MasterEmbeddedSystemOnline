/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : 5 C Functions
 Name        : Example 5
 Description : Clear Specific Bit in Number
 ======================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int clearBit(int num, int bit) {
    if (bit < 0 || bit >= sizeof(int) * 8) {
        return num;
    }
    int mask = ~(1 << bit);
    return num & mask;
}

int main() {
    int num, bit;

    printf("Input number: ");
    fflush(stdout);
    scanf("%d", &num);

    printf("Bit Position: ");
    fflush(stdout);
    scanf("%d", &bit);

    int result = clearBit(num, bit);

    printf("The result is: %d\n", result);
    fflush(stdout);


    return 0;
}