#ifndef BUFFER_H_
#define BUFFER_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// User Configuration ==================
#define Course_Num 5        // Defines the number of courses for every student
#define student_num 10       // Defines how many students can be added to the saved file
#define QUEUE_LEN 50        // Defines the length of the data structure used for the queue


// Definition of a structure to hold student data
struct Saved_Date {
    char fname[student_num][50];    // First names of students
    char lname[student_num][50];    // Last names of students
    int ID[student_num];            // Student IDs
    float GPA[student_num];         // GPAs of students
    int CourseID[student_num][Course_Num];    // IDs of courses taken by students
};


// Extern declaration of the structure to store saved data
extern struct Saved_Date DATA_FILE;


// Definition of a structure to represent a student
struct Sstudent {
    char fname[50];         // First name of student
    char lname[50];         // Last name of student
    int ID;                 // Student ID
    float GPA;              // Student GPA
    int CourseID[Course_Num];    // IDs of courses taken by student
};


// Definition of a FIFO (First-In-First-Out) queue structure
typedef struct {
    unsigned int length;        // Total length of the queue
    unsigned int count;         // Number of elements in the queue
    struct Sstudent* head;      // Pointer to the first element (head) of the queue
    struct Sstudent* tail;      // Pointer to the last element (tail) of the queue
    struct Sstudent* base;      // Pointer to the base of the queue
} FIFO_Queue_st;

// Enum to define different status codes for the FIFO queue operations
typedef enum {
    FIFO_ERROR,
    FIFO_NO_ERROR,
    FIFO_FULL,
    FIFO_NOT_FULL,
    FIFO_EMPTY,
    FIFO_NOT_EMPTY,
    FIFO_NULL
} FIFO_STATUS_EN;



// Function prototypes for FIFO queue operations
FIFO_STATUS_EN QUEUE_INIT(FIFO_Queue_st *QUEUE, struct Sstudent *student, int length);
FIFO_STATUS_EN ENQUEUE(FIFO_Queue_st *QUEUE, struct Sstudent student);

FIFO_STATUS_EN IS_QUEUE_FULL(FIFO_Queue_st *QUEUE);
FIFO_STATUS_EN IS_QUEUE_EMPTY(FIFO_Queue_st *QUEUE);

FIFO_STATUS_EN ADD_STUDENT_FROM_FILE(FIFO_Queue_st *QUEUE);
FIFO_STATUS_EN ADD_STUDENT_MANUALY(FIFO_Queue_st *QUEUE);

FIFO_STATUS_EN GET_STUDENT_BY_ROLL(FIFO_Queue_st *QUEUE);
FIFO_STATUS_EN GET_STUDENT_BY_FNAME(FIFO_Queue_st *QUEUE);
FIFO_STATUS_EN GET_STUDENT_BY_COURSE(FIFO_Queue_st *QUEUE);

FIFO_STATUS_EN DELETE_STUDENT(FIFO_Queue_st *QUEUE);
FIFO_STATUS_EN UPDATE_STUDENT(FIFO_Queue_st *QUEUE);

FIFO_STATUS_EN GET_LENGTH(FIFO_Queue_st *QUEUE);
FIFO_STATUS_EN PRINT_LIST(FIFO_Queue_st *QUEUE);
FIFO_STATUS_EN PRINT_STUDENT(FIFO_Queue_st *QUEUE, int Stud_ID);

#endif /* BUFFER_H_ */
