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
void modulo();
void primality_test();
void factorial();
void power()
void fibonacci();


int main()
{
  /* Variable definition */
  float num1;
  float num2;
  int inum1;
  int inum2;
  int user_input;
  int user_choice;
  int fibonacci_sequence[500]; /* Max of first 500 terms of the sequence */

  /* 
   * A functuin which outputs main program menu and prompts user for their choice.
   * Takes no inputs and returns the user's number choice as type char.
   */
  int menu_prompt()
  {
    printf("Calculator Menu:\n");
    printf("(1)\tAddition\n");
    printf("(2)\tSubtraction\n");
    printf("(3)\tMultiplication\n");
    printf("(4)\tDivision\n");
    printf("(5)\tModulo\t\t(Integers)\n");
    printf("(6)\tPrimality Test\t(Integers)\n");
    printf("(7)\tFactorial\t(Integers)\n");
    printf("(8)\tPower\n");
    printf("(9)\tFibonacci Sequence to nth Term (Max: 500)\n");
    printf("(0)\tExit\n");
    printf("\n");
    printf("Please choose an option: ");
    scanf("%i",&user_input);
    return user_input;
  }    
  /* 
   * operation_header() uses a pre-defined string variable, and prints out a
   * header declaring the operation, and prompts the user for two numbers.
   * Applicable for addition, subtraction, division, multiplication, and modulo.
   */
  void operation_header(int inputs)
  {
    printf("\n");
    if (inputs == 2)
      {
	printf("Enter your first number: ");
	if (user_input == 5) /* Prompts user for int if modulo */
	  {
	    scanf("%i", &inum1);
	  }
	else
	  {
	    scanf("%f", &num1);
	  }
	printf("Enter your second number: ");
	if (user_input == 5) /* Prompts user for int if modulo */
	  {
	    scanf("%i", &inum2);
	  }
	else
	  {
	    scanf("%f", &num2);
	  }
      }
    else /* Only need one number */
      {
	printf("Enter your number to compute: ");
	scanf("%i", &inum1);
      }
    printf("\n");
  }

  /* Functions for the various operations that the calculator can perform. */
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

  void multiplication()
  {
    float product = num1 * num2;
    printf("%.2f * %.2f = %.2f\n", num1, num2, product);
    printf("\n");
  }

  void division()
  {
    if (num2 == 0)
      {
	printf("ERROR: Divide by Zero\n");
      }
    else
      {
	float quotient = num1 / num2;
	printf("%.2f / %.2f = %.2f\n", num1, num2, quotient);
      }
    printf("\n");
  }

  void modulo()
  {
    if (inum2 == 0)
      {
	printf("ERROR: Divide by Zero\n");
	printf("\n");
      }
    else
      {
	int modulus = inum1 % inum2;
	printf("%d %% %d = %d\n", inum1, inum2, modulus);
	printf("\n");
      }
  }

  void primality_test()
  {
    int primality = 1; /* 0 is false, 1 is true */
    if (inum1 == 1)
      {
	primality = 0;
      }
    else if (inum1 == 2 ||
	inum1 == 3 ||
	inum1 == 5 ||
	inum1 == 7)
      {
	primality = 1;
      }
    else if ((inum1 % 2) == 0)
      {
	primality = 0;
      }
    else if ((inum1 % 3) == 0)
      {
	primality = 0;
      }
    else if ((inum1 % 5) == 0)
      {
	primality = 0;
      }
    else if ((inum1 % 7) == 0)
      {
	primality = 0;
      }
    else if ((inum1 % 9) == 0)
      {
	primality = 0;
      }
    else
      {
	primality = 1;
      }
    if (primality == 0)
      {
	printf("%d is not prime\n", inum1);
      }
    else
      {
	printf("%d is prime\n", inum1);
      }
    printf("\n");
  }

  void 
  
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
	case 3: /* Option 3, Multiplication */
	  {
	    operation_header(2);
	    multiplication();
	    break;
	  }
	case 4: /* Option 4, Division */
	  {
	    operation_header(2);
	    division();
	    break;
	  }
	case 5: /* Option 5, Modulo */
	  {
	    operation_header(2);
	    modulo();
	    break;
	  }
	case 6: /* Option 6, Primality Test */
	  {
	    operation_header(1);
	    primality_test();
	    break;
	  }
	} 
    }
  while (user_choice != 0);
}
