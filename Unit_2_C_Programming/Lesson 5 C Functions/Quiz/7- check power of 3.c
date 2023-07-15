/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : 5 C Functions
 Name        : Example 7
 Description : Check If Number is Power of 3
 ======================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int power3(int n){
	int temp = n;
	while (temp > 1) {
		if (temp % 3 != 0) {
			return 1;
		}
		temp /= 3;
	}
	return 0;
}


int main() {
    int i, num;

    printf("Enter an Integer: ");
    fflush(stdout);
    scanf("%d", &num);

    i = power3(num);
    printf("%d ==> %d\n", num, i);



    return 0;
}
