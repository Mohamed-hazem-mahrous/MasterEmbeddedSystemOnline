/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : 5 C Functions
 Name        : Example 1
 Description : Getting Prime Numbers Between Two Intervals
 ======================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int isprime(int num){
    int i;
    if(num <= 1){
        return 0;
    }
    for(i=2; i <= sqrt(num); i++){
        if(num%i==0){
            return 0;
        }
    }
    return 1;
}

void prime_nums(int start, int end){
    int i;
    for(i = start; i <= end; i++){
        if(isprime(i)){
            printf("%d ",i);
        }
    }
}


int main()
{

	int start, end;

    printf("Enter Two Numbers(Intervals): ");
    fflush(stdout);
    scanf("%d", &start);
    scanf("%d", &end);

    printf("Prime numbers between %d and %d are: \n", start, end);
    prime_nums(start, end);


    return EXIT_SUCCESS;
}
