/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : MidTerm Exam
 Name        : Example 1
 Description : function to take a number and sum all digits
 ======================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum_digit(int num){
	static int new_num=0;
	int rem;
	if(num!=0){
		rem=num%10;
		new_num +=rem;;
		sum_digit(num/10);
	}
	else
		return 0;
	return new_num;
}
int main() {
	int num = 123;
	printf("Sum of %d is: %d", num, sum_digit(num));
	return 0;
}

