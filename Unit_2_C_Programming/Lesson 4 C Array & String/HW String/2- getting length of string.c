/*
 ======================================================================================================================
 Name        : Example 2
 Author      : Mohamed Hazem
 Description : Getting length of string
 ======================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char text[100];
    int length = 0;

    printf("Enter a String: ");
    fflush(stdout);
    fgets(text, sizeof(text), stdin);

    while (text[length] != '\0')
	{
		length++;
	}
    length--;

    printf("Length of the String is %d: ", length);
    fflush(stdout);

    return EXIT_SUCCESS;
}
