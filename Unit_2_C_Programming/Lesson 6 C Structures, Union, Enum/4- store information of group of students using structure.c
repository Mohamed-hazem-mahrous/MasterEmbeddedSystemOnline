/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : Lesson 6
 Name        : Example 4
 Description : Storing information of 10 students in a structure
 ======================================================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct SStudent {
    char s_name[50];
    int s_roll;
    int s_mark;
};

int main() {
    struct SStudent student[3];
    int size = sizeof(student) / sizeof(student[0]);

    printf("Enter Information of The Students\n");

    for (int i = 0; i < size; i++) {
        printf("\nFor Roll Number: %d\n", i + 1);
        student[i].s_roll = i + 1;

        printf("Enter Name: ");
        fflush(stdout);
        fgets(student[i].s_name, sizeof(student[i].s_name), stdin);

        printf("Enter Marks: ");
        fflush(stdout);
        scanf("%d", &student[i].s_mark);
        getchar();

    }

    printf("\nDisplaying Information of The Students\n");

    for (int i = 0; i < size; i++) {
        printf("\nInformation for Roll: %d", student[i].s_roll);
        printf("\nName: %s", student[i].s_name);
        printf("Marks: %d\n", student[i].s_mark);
    }

    return 0;
}
