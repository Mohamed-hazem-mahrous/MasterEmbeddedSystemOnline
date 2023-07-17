/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : Lesson 6
 Name        : Example 5
 Description : Find Area of Circle Using Macros
 ======================================================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define PI 3.14159
#define AREA(radius) (PI * (radius) * (radius))

int main() {
    double radius, area;

    printf("Enter the radius: ");
    fflush(stdout);
    scanf("%lf", &radius);

    area = AREA(radius);

    printf("Area = %.2lf", area);

    return 0;
}
