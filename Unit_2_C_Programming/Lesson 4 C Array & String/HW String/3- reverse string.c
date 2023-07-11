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
    fgets(text, sizeof(text), stdin);

    length = strlen(text);

    for (i = 0; i < length - 1; i++)
        {
    		text2[i] = text[length - 2 - i];
        }
    text2[i] = 0;

    printf("Reverse String is: %s", text2);
    fflush(stdout);

    return EXIT_SUCCESS;
}
