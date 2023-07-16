/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : MidTerm Exam
 Name        : Example 5
 Description : Count number of ones in binary number
 ======================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int sum_ones(int num) {
    int count = 0;
    while (num != 0) {
        if (num % 2 == 1) {
            count++;
        }
        num /= 2;
    }
    return count;
}

int main() {
    int num = 15;
    printf("Number of ones of %d is:  %d", num, sum_ones(num));
    return 0;
}
