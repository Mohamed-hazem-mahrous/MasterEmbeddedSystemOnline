/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : 5 C Functions
 Name        : Example 3
 Description : Reverse String Using Recursion
 ======================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char text[100], text2[100];

void reverse_string(int len, int i){
	while(i < len){
		text2[i] = text[len - 1 - i];
		i++;
		reverse_string(len, i);
	}
}


int main()
{
    int length;

    printf("Enter a String: ");
    fflush(stdout);
    gets(text);

    length = strlen(text);

    reverse_string(length, 0);

    text2[length] = 0;

    printf("Reversed String is: %s", text2);
    fflush(stdout);

    return EXIT_SUCCESS;
}
