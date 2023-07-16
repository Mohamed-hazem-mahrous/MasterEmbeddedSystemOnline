/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : MidTerm Exam
 Name        : Example 6
 Description : Find Unique Number in Array
 ======================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int find_unique(int arr[], int size) {
    int unique = 0;
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j])
                count++;
        }
        if (count == 1) {
            unique = arr[i];
            break;}}
    return unique;
}

int main() {
    int a[7] = {4, 2, 5, 2, 5, 7, 4};
    int size = sizeof(a) / sizeof(a[0]);
    printf("Unique number in the array: %d\n", find_unique(a, size));

    int b[3] = {4, 2, 4};
    size = sizeof(b) / sizeof(b[0]);
    printf("Unique number in the array: %d\n", find_unique(b, size));

    return 0;
}
