/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : MidTerm Exam
 Name        : Example 8
 Description : Reverse an Array
 ======================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void rev_arr(int arr[], int size) {
    int rev[100];
    for (int i = 0; i < size; i++) {
        rev[i] = arr[size - 1 - i];
    }

    for (int i = 0; i < size; i++) {
        arr[i] = rev[i];
    }
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    rev_arr(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
