/*
 * Name: Joseph Downs
 * Lab 02
 * 2020.01.24
 *
 * A simple calculator that can perform addition, subtraction, multiplication,
 * division, modulus, and a primality test.
 */

#include <stdio.h>

char menu_prompt();
void operation_header(char operation);
float addition(float num1, float num2);
float subtraction(float num1, float num2);
float multiplication(float num1, float num2);
float division(float num1, float num2);
float modulus(float num1, float num2);
void primality_test(float num1);

int main()
{
  /* 
   * A functuin which outputs main program menu and prompts user for their choice.
   * Takes no inputs and returns the user's number choice as type char.
   */
  char menu_prompt()
  {
    char user_input;
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
    scanf("%c",&user_input);
    return user_input;
  }
  char user_choice = menu_prompt();
  float num1;
  float num2;
  char operation[];
  /* 
   * operation_header() uses a pre-defined string variable, and prints out a
   * header declaring the operation, and prompts the user for two numbers.
   * Applicable for addition, subtraction, division, multiplication, and modulus.
   */
  void operation_header()
  {
    printf("\n");
    printf("=====%s=====\n", operation);
    printf("Enter your first number: ");
    scanf("%f", &num1);
    printf("Enter your second number: ");
    scanf("%f", &num2);
  }
  
  float addition(float num1, float num2)
  {
    
  }
}
