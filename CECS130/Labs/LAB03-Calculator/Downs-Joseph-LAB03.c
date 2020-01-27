/*
Name: Joseph Downs
Lab 02
2020.01.24

A simple calculator that can perform addition, subtraction, multiplication,
division, modulus, and a primality test.
*/

#include <stdio.h>

char menu_prompt();

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
}
