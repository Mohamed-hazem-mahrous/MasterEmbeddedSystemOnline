/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : 5 C Functions
 Name        : Example 3
 Description : Reverse an Array
 ======================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int* reverseArray(int arr[], int size) {
    static int reversed[100];
    int i;

    for (i = 0; i < size; i++) {
        reversed[i] = arr[size - i - 1];
    }
    return reversed;
}


int main() {
    int arr[100], size, i;
    int* reversed;

    printf("Enter the size of the array: ");
    fflush(stdout);
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    fflush(stdout);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    reversed = reverseArray(arr, size);

    printf("The reversed array is:\n");
    fflush(stdout);
    for (i = 0; i < size; i++) {
        printf("%d ", reversed[i]);
        fflush(stdout);
    }

    return 0;
}