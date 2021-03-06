/*
 * Name: Joseph Downs
 * Lab 04
 * 2020.02.07
 *
 * A simple calculator that can perform addition, subtraction, multiplication,
 * division, modulus, a primality test, compute factorials, and up to the nth
 * digit of the Fibonacci Sequence (up to the 500th term)
 */

#include <stdio.h>

int menu_prompt();
void operation_header();
void addition();
void subtraction();
void multiplication();
void division();
void modulo();
void primality_test();
void factorial();
void power();
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
  }
  
  void subtraction()
  {
    float difference = num1 - num2;
    printf("%.2f - %.2f = %.2f\n", num1, num2, difference);
  }

  void multiplication()
  {
    float product = num1 * num2;
    printf("%.2f * %.2f = %.2f\n", num1, num2, product);
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
  }

  void modulo()
  {
    if (inum2 == 0)
      {
	printf("ERROR: Divide by Zero\n");
      }
    else
      {
	int modulus = inum1 % inum2;
	printf("%d %% %d = %d\n", inum1, inum2, modulus);
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
  }

  void factorial()
  {
    if (inum1 < 0)
      {
	printf("Cannot take the factorial of a negative integer.\n");
      }
    else
      {
	int i;
	double factorial = 1;
	for (i = 1; i <= inum1; i++)
	  {
	    factorial = factorial * i;
	  }
	printf("%i! = %.0lf\n", inum1, factorial);
      }
  }

  void power()
  {
    float power = 1;
    int i;
    if (num2 == 0)
    {
      if (num1 == 0 && num2 == 0)
	{
	  printf("0 ** 0 = Undefined\n");
	}
      else
	{
	  printf("%.2f ** %.0f = 1\n", num1, num2);
	}
    }
    else
      {
	for (i = 1; i <= num2; i++)
	  {
	    power = power * num1;
	  }		  
	printf("%.2f ** %.2f = %.2f\n", num1, num2, power);
      }
  }

  void fibonacci()
  {
    double sequence[500] = {0, 1};
    int n = inum1;
    int i;
    for (i = 2; i <= n; i++)
      {
	sequence[i] = sequence[i-1] + sequence[i-2];
      }
    printf("The values of the Fibonacci sequence from n=0 to n=%d are:\n", inum1);
    for (i = 0; i <= n; i++)
      {
	printf("%.0lf", sequence[i]);
	if (i == n)
	  {
	    printf("...\n");
	  }
	else
	  {
	    printf(", "); 
	  }
      }
  }
  
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
	case 7: /* Option 7, Factorial */
	  {
	    operation_header(1);
	    factorial();
	    break;
	  }
	case 8: /* Option 8, Power */
	  {
	    operation_header(2);
	    power();
	    break;
	  }
	case 9: /* Option 9, Fibonacci Sequence */
	  {
	    operation_header(1);
	    fibonacci();
	    break;
	  }
	}
      printf("\n");
    }
  while (user_choice != 0);
}
