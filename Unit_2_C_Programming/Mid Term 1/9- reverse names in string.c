/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : MidTerm Exam
 Name        : Example 9
 Description : Reverse words in string
 ======================================================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void reverse_names(char *str) {
    int len = strlen(str);
    char temp;
    // Reverse the entire string
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    // Reverse each word in the string
    int start = 0;
    for (int i = 0; i <= len; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            for (int j = start, k = i - 1; j < k; j++, k--) {
                temp = str[j];
                str[j] = str[k];
                str[k] = temp;
            }
            start = i + 1;}}}

int main() {
    char str[] = "mohamed gamal";
    printf("String Before: %s\n", str);
    reverse_names(str);
    printf("String After: %s", str);
    return 0;
}
