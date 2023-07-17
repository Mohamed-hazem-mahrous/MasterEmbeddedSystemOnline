/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : Lesson 6
 Name        : Example 5
 Description : Find Area of Circle Using Macros
 ======================================================================================================================
 */

/*
Output of the Program is 

size of union=32
size of structure = 40
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

union job {		//defining a union
	char name[32];
	float salary;
	int worker_no;
}u;

struct job1 {
	char name[32];
	float salary;
	int worker_no;
}s;

int main() {
	printf("size of union=%d",sizeof(u));
	printf("\nsize of structure = %d", sizeof(s));
	return 0;
}















