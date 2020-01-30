/*
 * Name: Joseph Downs
 * Lab 02
 * 2020.01.31
 *
 * A simple calculator that can perform addition, subtraction, multiplication,
 * division, modulus, and a primality test.
 */

#include <stdio.h>

int menu_prompt();
void operation_header(char operation);
void addition();
void subtraction();
void multiplication();
void division();
void modulus();
void primality_test();

int main()
{
  /* 
   * A functuin which outputs main program menu and prompts user for their choice.
   * Takes no inputs and returns the user's number choice as type char.
   */
  int menu_prompt()
  {
    int user_input;
    printf("Calculator Menu:\n");
    printf("(1)\tAddition\n");
    printf("(2)\tSubtraction\n");
    printf("(3)\tMultiplication\n");
    printf("(4)\tDivision\n");
    printf("(5)\tModulus\t\t(Integers)\n");
    printf("(6)\tPrimality Test\t(Integers)\n");
    printf("(7)\tExit\n");
    printf("\n");
    printf("Please choose an option: ");
    scanf("%i",&user_input);
    return user_input;
  }  
  float num1;
  float num2;
  
  /* 
   * operation_header() uses a pre-defined string variable, and prints out a
   * header declaring the operation, and prompts the user for two numbers.
   * Applicable for addition, subtraction, division, multiplication, and modulus.
   */
  void operation_header(int inputs)
  {
    printf("\n");
    if (inputs == 2)
      {
	printf("Enter your first number: ");
	scanf("%f", &num1);
	printf("Enter your second number: ");
	scanf("%f", &num2);
      }
    else
      {
	printf("Enter the number to test: ");
	scanf("%f", &num1);
      }
    printf("\n");
  }
  
  void addition()
  {
    float sum = num1 + num2;
    printf("%.2f + %.2f = %.2f\n", num1, num2, sum);
    printf("\n");
  }
  
  void subtraction()
  {
    float difference = num1 - num2;
    printf("%.2f - %.2f = %.2f\n", num1, num2, difference);
    printf("\n");
  }
  
  int user_choice; 
  do
    {
      user_choice = menu_prompt();
      switch (user_choice)
	{
	case 1: /* Option 1, Addition */
	  {
	    operation_header(2);
	    addition();
	    break;
	  }
	case 2: /* Option 2, Subtraction */
	  {
	    operation_header(2);
	    subtraction();
	    break;
	  }
	} 
    } while (user_choice != 7);

}
