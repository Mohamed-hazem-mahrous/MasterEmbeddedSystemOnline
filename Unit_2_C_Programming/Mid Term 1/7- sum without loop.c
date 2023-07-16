/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : MidTerm Exam
 Name        : Example 7
 Description : Sum from 1 to 100 without loop
 ======================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int sum_1_100(int first, int end) {
	int sumn = (first + end) * (end/2);

    return sumn;
}

int main() {
	int first = 1, end = 100;

	printf("Sum Numbers from %d to %d is: %d", first, end, sum_1_100(first, end));

    return 0;
}
