/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : Lesson 6
 Name        : Example 1
 Description : Storing information in a structure
 ======================================================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct SStudent{
	char s_name[50];
	int s_roll;
	float s_mark;

};


int main() {

	struct SStudent student;

	printf("Enter Information of The Student\n");

	printf("Enter Name: ");
	fflush(stdout);
	gets(student.s_name);

	printf("Enter Roll Number: ");
	fflush(stdout);
	scanf("%d",&student.s_roll);

	printf("Enter Marks: ");
	fflush(stdout);
	scanf("%f",&student.s_mark);

	printf("\nDisplaying Information of The Student");
	fflush(stdout);

	printf("\nName: %s", student.s_name);
	printf("\nRoll: %d", student.s_roll);
	printf("\nMarks: %.2f", student.s_mark);



    return 0;
}
