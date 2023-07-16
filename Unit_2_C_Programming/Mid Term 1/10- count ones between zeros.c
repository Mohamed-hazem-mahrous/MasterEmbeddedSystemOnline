/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : MidTerm Exam
 Name        : Example 10
 Description : Count the max number of ones between two zeros
 ======================================================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int max_ones(int num) {
    int count = 0;
    int max = 0;
    int zeros = 0;
    int found_zero = 0;

    while (num > 0) {
        int bit = num & 1;
        num >>= 1;

        if (bit == 1) {
            count++;
            if (found_zero) {
            	max = (count > max) ? count : max;
            }
        } else {
            count = 0;
            zeros++;
            if (zeros == 1) {
            	found_zero = 1;
            }
        }
    }

    return count;
}

int main() {
    int num1 = 14;
    int num2 = 110;

    printf("Max ones in %d is: %d\n", num1, max_ones(num1));
    printf("Max ones in %d is: %d\n", num2, max_ones(num2));

    return 0;
}
