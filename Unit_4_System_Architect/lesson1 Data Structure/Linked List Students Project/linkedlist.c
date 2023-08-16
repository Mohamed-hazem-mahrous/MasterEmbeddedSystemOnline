#include "linkedlist.h"



// initializing the linked list
Student_List_EN LIST_INIT(Student_List* list){
	if(!list)
		return LIST_NULL;

	list->PFirstStudent = NULL;
	list->PLastStudent = NULL;
	list->count = 0;

	printf("\n======List Init Is Done======\n\n");
	return LIST_No_Error;
}





// getting the new records of the students
void FILL_RECORD(struct Sstudent* PNewStudent){
	char temp_text[40];

	printf("\nEnter the ID : ");
	fflush(stdout);
	gets(temp_text);
	fflush(stdin);
	PNewStudent->ID = atoi(temp_text);

	printf("Enter the Name : ");
	fflush(stdout);
	gets(PNewStudent->name);
	fflush(stdin);

	printf("Enter the Height : ");
	fflush(stdout);
	gets(temp_text);
	fflush(stdin);
	PNewStudent->height = atof(temp_text);
}










// Add New Student to the linked list
Student_List_EN ADD_STUDENT(Student_List* list){
	if(!list)
		return LIST_NULL;

	struct Sstudent*  PNewStudent;

	if(list->PFirstStudent == NULL){
		PNewStudent = (struct Sstudent*)malloc(sizeof(struct Sstudent));
		list->PFirstStudent = PNewStudent;
		list->PLastStudent = PNewStudent;
	}
	else{
		PNewStudent = (struct Sstudent*)malloc(sizeof(struct Sstudent));
		list->PLastStudent->PNextStudent = PNewStudent;
		list->PLastStudent = PNewStudent;
		PNewStudent->PNextStudent = NULL;
	}

	FILL_RECORD(PNewStudent);
	list->count++;
	printf("\n====== Student %s Have Been Added to the List ======\n\n", PNewStudent->name);

	return LIST_No_Error;
}







// Delete Student from the linked list
Student_List_EN DELETE_STUDENT(Student_List* list){
	char temp_text[40];
	int selected_id;

	printf("\nEnter the student ID to be deleted : ");
	fflush(stdout);
	gets(temp_text);
	fflush(stdin);
	selected_id = atoi(temp_text);

	if(list->PFirstStudent){
		struct Sstudent* pPrevStudent = NULL;
		struct Sstudent* pSelectedStudent = list->PFirstStudent;

		while(pSelectedStudent){
			if(pSelectedStudent->ID == selected_id)
			{
				if(pPrevStudent)
				{
					pPrevStudent->PNextStudent = pSelectedStudent->PNextStudent;
				}
				else
				{
					list->PFirstStudent = pSelectedStudent->PNextStudent;
				}
				free(pSelectedStudent);
				printf("\nThe Student Have Been Deleted\n");
				return LIST_No_Error;
			}

			pPrevStudent = pSelectedStudent;
			pSelectedStudent = pSelectedStudent->PNextStudent;
		}
	}
	printf("\nCan't Find student ID\n");
	return LIST_STUDENT_NOT_FOUND;
}







// checking if the list is empty or not
Student_List_EN IS_LIST_EMPTY(Student_List* list){
	if(list->PFirstStudent == NULL)
	{
		printf("\nList is Empty\n");
		return LIST_NULL;
	}
	printf("\nList is not Empty\n");
	return LIST_NOT_EMPTY;
}





// getting the top node informations
struct Sstudent* GET_TOP_NODE(Student_List* list){
	printf("\nTop Student's ID is : %d and His Name is : %s\n", list->PLastStudent->ID, list->PLastStudent->name);
	return list->PLastStudent;
}










// getting the middle node informations
struct Sstudent* GET_MIDDLE_NODE(Student_List* list){
	struct Sstudent* pMidStudent;
	struct Sstudent* pCurrStudent = list->PFirstStudent;
	if( (list->count%2) == 0.5 )
	{
		for(int i = 0; i < (list->count / 2) + 1 ; i++){
			pMidStudent = pCurrStudent;
			pCurrStudent = pCurrStudent->PNextStudent;
		}
		printf("\nMiddle Student's ID is : %d and His Name is : %s \n", pMidStudent->ID, pMidStudent->name);
		return pMidStudent;
	}

	for(int i = 0; i < (list->count / 2) + 1 ; i++){
		pMidStudent = pCurrStudent;
		pCurrStudent = pCurrStudent->PNextStudent;
	}
	printf("\nMiddle Student's ID is : %d and His Name is : %s\n", pMidStudent->ID, pMidStudent->name);
	return pMidStudent;
}







// getting the Nth node informations
struct Sstudent* GET_Nth_NODE(Student_List* list){

	char temp_text[40];
	int num;

	printf("\nEnter the Number of student that you want to show : ");
	fflush(stdout);
	gets(temp_text);
	fflush(stdin);
	num = atoi(temp_text);

	struct Sstudent* pPrevStudent;
	struct Sstudent* pCurrStudent = list->PFirstStudent;

	for(int i = 0; i < num ; i++){
		pPrevStudent = pCurrStudent;
		pCurrStudent = pCurrStudent->PNextStudent;
	}
	printf("\nNumber %d Student's ID is : %d and His Name is : %s\n", num, pPrevStudent->ID, pPrevStudent->name);
	return pPrevStudent;
}






// getting the Nth node from the back informations
struct Sstudent* GET_Nth_NODE_FROM_BACK(Student_List* list){

	char temp_text[40];
	int num;

	printf("\nEnter the Number of student that you want to show : ");
	fflush(stdout);
	gets(temp_text);
	fflush(stdin);
	num = atoi(temp_text);

	struct Sstudent* pPrevStudent;
	struct Sstudent* pCurrStudent = list->PFirstStudent;

	for(int i = 0; i < (list->count - num) ; i++){
		pPrevStudent = pCurrStudent;
		pCurrStudent = pCurrStudent->PNextStudent;
	}
	printf("\nNumber %d Student's ID is : %d and His Name is : %s\n", num, pPrevStudent->ID, pPrevStudent->name);
	return pPrevStudent;
}












// Viewing all the students in the linked list
void PRINT_LIST(Student_List* list){
	int count = 0;
	struct Sstudent*  temp = list->PFirstStudent;

	if(list->PFirstStudent == NULL)
		printf("\nList is Empty\n");

	while(temp){
		printf("======== Record Number %d ========\n", count+1);
		printf("ID : %d \n", temp->ID);
		printf("Name : %s \n", temp->name);
		printf("Height : %f \n\n", temp->height);
		temp = temp->PNextStudent;
		count++;
	}
}













// clear the whole list
void CLEAR_LIST(Student_List* list){
	struct Sstudent*  pCurStudent = list->PFirstStudent;

	if(list->PFirstStudent == NULL)
		printf("\nList is Empty");
	while(pCurStudent){
		struct Sstudent*  pTempStudent = pCurStudent;
		pCurStudent = pCurStudent->PNextStudent;
		free(pTempStudent);
	}
	list->PFirstStudent = NULL;
	list->PLastStudent = NULL;
	list->count = 0;

	printf("\nClearing the list is done");

}







// getting the length of the linked list
unsigned int GET_LENGTH(Student_List* list){
	printf("\nThe List Length is %d \n", list->count);
	return list->count;
}













