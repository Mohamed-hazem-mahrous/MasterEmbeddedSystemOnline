/*
 ======================================================================================================================
 Name        : Example 1
 Author      : Mohamed Hazem
 Description : Getting frequency of a character
 ======================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char text[100], c;
    int freq = 0, i, length = 0;

    printf("Enter a String: ");
    fflush(stdout);
    fgets(text, sizeof(text), stdin);

    printf("Enter Character to find frequency: ");
    fflush(stdout);
    scanf("%c", &c);

    length = strlen(text);

    for (i = 0; i < length; i++)
    {
        if (text[i] == c)
        {
        	freq++;
        }
    }
    printf("Frequency of %c is %d: ", c, freq);
    fflush(stdout);

    return EXIT_SUCCESS;
}
