#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "linkedlist.h"

int main(void) {

	char temp_text[40];

	Student_List Stud_List;

	while(1){
		printf("==============================");
		printf("\n\t Choose one of the Following Options");
		printf("\n 0: Initialize List");
		printf("\n 1: Add Student");
		printf("\n 2: Delete Student");
		printf("\n 3: Is The List Empty");
		printf("\n 4: Get Top Node");
		printf("\n 5: Get Middle Node");
		printf("\n 6: Get Nth Node");
		printf("\n 7: Get Nth Node from the back");
		printf("\n 8: Get the List Length");
		printf("\n 9: View All Students");
		printf("\n 10: Delete All Students");
		printf("\n Enter Option Number : ");
		fflush(stdout);
		gets(temp_text);
		fflush(stdin);

		switch(atoi(temp_text))
		{
		case 0:
			LIST_INIT(&Stud_List);
			break;

		case 1:
			ADD_STUDENT(&Stud_List);
			break;

		case 2:
			DELETE_STUDENT(&Stud_List);
			break;

		case 3:
			IS_LIST_EMPTY(&Stud_List);
			break;

		case 4:
			GET_TOP_NODE(&Stud_List);
			break;

		case 5:
			GET_MIDDLE_NODE(&Stud_List);
			break;

		case 6:
			GET_Nth_NODE(&Stud_List);
			break;

		case 7:
			GET_Nth_NODE_FROM_BACK(&Stud_List);
			break;

		case 8:
			GET_LENGTH(&Stud_List);
			break;


		case 9:
			PRINT_LIST(&Stud_List);
			break;

		case 10:
			CLEAR_LIST(&Stud_List);
			break;

		default:
			printf("\nWrong Option");
			break;
		}
	}







	return EXIT_SUCCESS;
}
