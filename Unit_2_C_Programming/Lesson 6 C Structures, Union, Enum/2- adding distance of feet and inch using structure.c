/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : Lesson 6
 Name        : Example 2
 Description : Adding Distance in feet & inch using structure
 ======================================================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Sdistance{
	int feet;
	float inch;

};

struct Sdistance sum_distance(struct Sdistance dis1, struct Sdistance dis2){
	struct Sdistance dis3;

	dis3.feet = dis2.feet + dis1.feet;
	dis3.inch = dis2.inch + dis1.inch;

	if(dis3.inch>12){
		dis3.inch /= 12;
		dis3.inch --;
		dis3.feet++;
	}
	return dis3;
}


int main() {

	struct Sdistance distance1;
	struct Sdistance distance2;

	struct Sdistance sum_dis;

	printf("Enter Information for the First Distance\n");
	printf("Enter Feet: ");
	fflush(stdout);
	scanf("%d", &distance1.feet);

	printf("Enter Inch: ");
	fflush(stdout);
	scanf("%f",&distance1.inch);


	printf("Enter Information for the Second distance\n");
	printf("Enter Feet: ");
	fflush(stdout);
	scanf("%d", &distance2.feet);

	printf("Enter Inch: ");
	fflush(stdout);
	scanf("%f",&distance2.inch);

	sum_dis = sum_distance(distance1, distance2);

	printf("\nSum of Distance is = %d\' %.2f\"", sum_dis.feet, sum_dis.inch);

    return 0;
}