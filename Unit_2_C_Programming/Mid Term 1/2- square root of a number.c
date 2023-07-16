/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : MidTerm Exam
 Name        : Example 2
 Description : function to take an integer number and calculate it's square root
 ======================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float square_root(int num){
	return sqrt(num);
}


int main() {
	int num = 10;
	printf("Square Root of %d is: %.3lf", num, square_root(num));
	return 0;
}

