#ifndef LinkedList_H_
#define LinkedList_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct Sstudent{
	int ID;
	char name[40];
	float height;
	struct Sstudent* PNextStudent;
};

typedef struct{
	struct Sstudent* PFirstStudent;
	struct Sstudent* PLastStudent;
	unsigned int count;
}Student_List;

typedef enum{
	LIST_No_Error,
	LIST_EMPTY,
	LIST_NOT_EMPTY,
	LIST_NULL,
	LIST_STUDENT_NOT_FOUND
} Student_List_EN;

void FILL_RECORD(struct Sstudent* PNewStudent);

Student_List_EN LIST_INIT(Student_List* list);
Student_List_EN ADD_STUDENT(Student_List* list);
Student_List_EN DELETE_STUDENT(Student_List* list);
Student_List_EN IS_LIST_EMPTY(Student_List* list);

struct Sstudent* GET_TOP_NODE(Student_List* list);
struct Sstudent* GET_MIDDLE_NODE(Student_List* list);
struct Sstudent* GET_Nth_NODE(Student_List* list);
struct Sstudent* GET_Nth_NODE_FROM_BACK(Student_List* list);

void PRINT_LIST(Student_List* list);
void REVERSE_LIST(Student_List* list);
void CLEAR_LIST(Student_List* list);

unsigned int GET_LENGTH(Student_List* list);




#endif /* Linkedlist_H_ */
