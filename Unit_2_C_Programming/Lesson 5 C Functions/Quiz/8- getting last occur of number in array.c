/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : 5 C Functions
 Name        : Example 8
 Description : Getting the Last Occurance of Number in Array
 ======================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lastOccur(int arr[], int size, int num){
	int place = -1;
	for (int i = 0; i < size; i++){
		if (num == arr[i]){
			place = i;
		}
	}
	return place;
}



int main() {
    int arr[100], size, i, number, place;

    printf("Enter the size of the array: ");
    fflush(stdout);
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    fflush(stdout);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the Number to Search for: ");
    fflush(stdout);
    scanf("%d", &number);

    place = lastOccur(arr, size, number);

    if(place == -1){
        printf("The Number %d Can't be Found at the Array",number);
        fflush(stdout);
    }else{
        printf("The Number %d is at: %d",number, place);
        fflush(stdout);
    }

    return 0;
}

