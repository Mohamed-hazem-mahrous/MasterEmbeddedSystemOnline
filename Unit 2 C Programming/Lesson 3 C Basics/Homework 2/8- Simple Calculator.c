/*
 ======================================================================================================================
 Name        : Example 8
 Author      : Mohamed Hazem
 Description : Simple Calculator
 ======================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char operator;
	float num1, num2;

	printf("Enter an operator either + or - or * or /: ");
	fflush(stdout);
	scanf("%c", &operator);

	printf("Enter two operands: ");
	fflush(stdout);
	scanf("%f %f", &num1, &num2);

	switch (operator)
	{
    	case '+':{
    		printf("%.2f + %.2f = %.2f", num1, num2, num1 + num2);
    		break;
    	}
    	case '-':{
    		printf("%.2f - %.2f = %.2f", num1, num2, num1 - num2);
    		break;
    	}
    	case '*':{
    		printf("%.2f * %.2f = %.2f", num1, num2, num1 * num2);
    		break;
    	}
    	case '/':{
    		printf("%.2f / %.2f = %.2f", num1, num2, num1 / num2);
    		break;
    	}
    	default:
    		printf("Error!!! the Operator is not Correct");
    		break;
	}
	return EXIT_SUCCESS;
}

