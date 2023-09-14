#include "buffer.h"

FIFO_Queue_st QUEUE_UART, QUEUE_TEST;
struct Sstudent UART_BUF[QUEUE_LEN];

int main(void) {
	struct Sstudent UART_BUF_TEST[QUEUE_LEN];
	QUEUE_INIT(&QUEUE_TEST, UART_BUF_TEST, QUEUE_LEN);

	int choise, while_loop = 1;

	printf("Welcome to the Student Management System");
	while(while_loop){
		printf("\n\nChoose The Task You Want to Perform\n");
		printf("1: Add Student Details Manually\n");
		printf("2: Add Student Details From the Saved Data\n");
		printf("3: Find Student Details By ID\n");
		printf("4: Find Student Details By First Name\n");
		printf("5: Find Student Details By Course ID\n");
		printf("6: Find the Total Number of Students\n");
		printf("7: Delete Students Details Using The ID\n");
		printf("8: Update Students Details Using The ID\n");
		printf("9: Show All Informations\n");
		printf("10: To Exit\n");
		printf("\nEnter Your Choise to perform the task: ");
		fflush(stdout);
		scanf("%d", &choise);
		fflush(stdin);

		switch(choise){
		case 1:
			ADD_STUDENT_MANUALY(&QUEUE_TEST);
			break;
		case 2:
			ADD_STUDENT_FROM_FILE(&QUEUE_TEST);
			break;
		case 3:
			GET_STUDENT_BY_ROLL(&QUEUE_TEST);
			break;
		case 4:
			GET_STUDENT_BY_FNAME(&QUEUE_TEST);
			break;
		case 5:
			GET_STUDENT_BY_COURSE(&QUEUE_TEST);
			break;
		case 6:
			GET_LENGTH(&QUEUE_TEST);
			break;
		case 7:
			DELETE_STUDENT(&QUEUE_TEST);
			break;
		case 8:
			UPDATE_STUDENT(&QUEUE_TEST);
			break;
		case 9:
			PRINT_LIST(&QUEUE_TEST);
			break;
		case 10:
			while_loop = 0;
			break;
		default:
			printf("\nWrong Option");
			break;
		}
	}
	return EXIT_SUCCESS;
}
