/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : 5 C Functions
 Name        : Example 2
 Description : Swapping Two Arrays with Different Length
 ======================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int A[100], B[100], sizeA, sizeB;

void swapArrays(int A[], int B[], int sizeA, int sizeB) {
    int i, C[100];

    for (i = 0; i < sizeA || i < sizeB ; i++) {
        C[i] = A[i];
    }

    for (i = 0; i <= sizeB ; i++) {
    	if(i<sizeB){
    		A[i] = B[i];
    	}else{
    		A[i] = 0;
    	}

    }

    for (i = 0; i < sizeA || i < sizeB ; i++) {
    	if(i < sizeA){
    		B[i] = C[i];
    	}else{
    		B[i] = 0;
    	}
    }

}

int main() {
    int i, temp;

    printf("Enter the size of array A: ");
    fflush(stdout);
    scanf("%d", &sizeA);

    printf("Enter the elements of array A:\n");
    fflush(stdout);
    for (i = 0; i < sizeA; i++) {
        scanf("%d", &A[i]);
    }

    printf("Enter the size of array B: ");
    fflush(stdout);
    scanf("%d", &sizeB);

    printf("Enter the elements of array B:\n");
    fflush(stdout);
    for (i = 0; i < sizeB; i++) {
        scanf("%d", &B[i]);
    }

    swapArrays(A, B, sizeA, sizeB);

    temp = sizeA;
    sizeA = sizeB;
    sizeB = temp;

    printf("Array A after swapping:\n");
    fflush(stdout);
    for (i = 0; i < sizeA; i++) {
        printf("%d ", A[i]);
        fflush(stdout);
    }

    printf("\nArray B after swapping:\n");
    fflush(stdout);
    for (i = 0; i < sizeB; i++) {
        printf("%d ", B[i]);
        fflush(stdout);
    }

    return 0;
}
