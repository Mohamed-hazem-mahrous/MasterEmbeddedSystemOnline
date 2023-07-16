/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : MidTerm Exam
 Name        : Example 4
 Description : Reverse Number
 ======================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int reverse_number(int num) {
    int reversed = 0;
    while (num != 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return reversed;
}
int main() {
    int num = 2457;
    printf("Original number: %d\n", num);
    int reversed = reverse_number(num);
    printf("Reversed number: %d\n", reversed);
    return 0;
}

