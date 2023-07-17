/*
 ======================================================================================================================
 Author      : Mohamed Hazem
 Unit		 : 2 C Programming
 Lesson		 : Lesson 6
 Name        : Example 3
 Description : Adding Two Complex Numbers using structure
 ======================================================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Scomplex{
	float real;
	float imag;

};

struct Scomplex sum_complex(struct Scomplex com1, struct Scomplex com2){
	struct Scomplex com3;

	com3.real = com2.real + com1.real;
	com3.imag = com2.imag + com1.imag;

	return com3;
}


int main() {

	struct Scomplex comp1;
	struct Scomplex comp2;

	struct Scomplex sum_comp;

	printf("1st Complex number\n");
	printf("Enter Real Part: ");
	fflush(stdout);
	scanf("%f", &comp1.real);

	printf("Enter Imaginary Part: ");
	fflush(stdout);
	scanf("%f", &comp1.imag);


	printf("\n2nd Complex number\n");
	printf("Enter Real Part: ");
	fflush(stdout);
	scanf("%f", &comp2.real);

	printf("Enter Imaginary Part: ");
	fflush(stdout);
	scanf("%f", &comp2.imag);

	sum_comp = sum_complex(comp1, comp2);

	if(sum_comp.imag > 0)
		printf("\nSum = %.1f + %.1f i", sum_comp.real, sum_comp.imag);
	else
		printf("\nSum = %.1f%.1f i", sum_comp.real, sum_comp.imag);

    return 0;
}
