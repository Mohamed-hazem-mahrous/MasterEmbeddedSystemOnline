/*
 ======================================================================================================================
 Name        : Example 3
 Author      : Mohamed Hazem
 Description : Reverse a string
 ======================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char text[100], text2[100];
    int length, i;

    printf("Enter a String: ");
    fflush(stdout);
    gets(text);

    length = strlen(text);

    for (i = 0; i < length; i++)
        {
    		text2[i] = text[length - 1 - i];
        }
    text2[length] = 0;

    printf("Reverse String is: %s", text2);
    fflush(stdout);

    return EXIT_SUCCESS;
}
