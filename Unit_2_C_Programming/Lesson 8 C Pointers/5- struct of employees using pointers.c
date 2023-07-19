/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : Lesson 8 : C Pointers
 Name        : Example 5
 Description : Struct of Employees using pointers
 ======================================================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct emplyees{
	unsigned char name[50];
	unsigned int ID;
}emp1, emp2, emp3;


int main()
{

	struct emplyees *arr[3];

	arr[0] = &emp1;
	arr[1] = &emp2;
	arr[2] = &emp3;

	strcpy(arr[0]->name, "Alex");
	arr[0]->ID = 1001;

	strcpy(arr[1]->name, "Mohamed");
	arr[1]->ID = 1002;

	strcpy(arr[2]->name, "Hazem");
	arr[2]->ID = 1003;

	for(int i = 0; i<3; i++){
		printf("Employee%d\n", i+1);
		printf("Employee Name : %s\n", arr[i]->name);
		printf("Employee Id: %d\n\n", arr[i]->ID);
	}







	return 0;
}













