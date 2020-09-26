// Test driver
#include <iostream>
#include <fstream>

#include "StackType.h"

using namespace std;

bool wellFormedParExp(string expr)
{
  bool isWellFormed = true;
  int strLength = expr.length();
  StackType<char> expressionStack;
  StackType<char> bracketStack;
  /*
   * Iterate through expression, checking
   * if the latest openining parentheses matches
   * with the next closing one
   */
  for (int i = 0; i < strLength; i++)
    { 
      if (expr[i] == '{' || expr[i] == '(' || expr[i] == '[')
	{
	  cout << expr[i];
	  bracketStack.Push(expr[i]);
	}
      else if (expr[i] == '}')
	{
	  try
	    {
	      if (bracketStack.Peek() == '{')
		{
		  bracketStack.Pop();
		}
	      else
		{
		  isWellFormed = false;
		  break;
		}
	    }
	  catch (EmptyStack)
	    {
	      isWellFormed = false;
	      break;
	    }
	}
      else if (expr[i] == ')')
	{
	 try
	    {
	      if (bracketStack.Peek() == '(')
		{
		  bracketStack.Pop();
		}
	      else
		{
		  isWellFormed = false;
		}
	    }
	 catch (EmptyStack)
	   {
	     isWellFormed = false;
	     break;
	   }
	}
      else if (expr[i] == ']')
	{
	  try
	    {
	      if (bracketStack.Peek() == '[')
		{
		  bracketStack.Pop();
		}
	      else
		{
		  isWellFormed = false;
		  break;
		}
	    }
	  catch (EmptyStack)
	    {
	      isWellFormed = false;
	      break;
	    }
	}
    }
  if (!bracketStack.IsEmpty())
    {
      isWellFormed = false;
    }
  return isWellFormed;
}

int main()
{

  ifstream inFile;       // file containing operations
  ofstream outFile;      // file containing output
  string inFileName;     // input file external name
  string outFileName;    // output file external name
  string outputLabel;     
  string command;        // operation to be executed
  /* String to be checked */
  string inputString;
  
  int item;
  StackType<int> stack(5);
  int numCommands;

  /*
  // Prompt for file names, read file names, and prepare files
  cout << "Enter name of input command file; press return." << endl;
  cin  >> inFileName;
  inFile.open(inFileName.c_str());

  cout << "Enter name of output file; press return." << endl;
  cin  >> outFileName;
  outFile.open(outFileName.c_str());

  cout << "Enter name of test run; press return." << endl;
  cin  >> outputLabel;
  outFile << outputLabel << endl;
  */
  cout << "Enter expression to test; press return." << endl;
  cin >> inputString;

  if (wellFormedParExp(inputString))
    {
      cout << "Your expression is well-formed!" << endl;
    }
  else
    {
      cout <<"Your expression is not well-formed." << endl;
    }
  /*
  inFile >> command;


  numCommands = 0;
  while (command != "Quit")
  { 
    try 
    {
      if (command == "Push")
      {
        inFile >> item; 
        stack.Push(item);
      }
      else if (command == "Pop")
        stack.Pop();
      else if (command == "Peek")
      {
        item = stack.Peek(); 
        outFile<< "Top element is " << item << endl;
      } 
      else if (command == "IsEmpty") 
        if (stack.IsEmpty())
          outFile << "Stack is empty." << endl;
        else 
          outFile << "Stack is not empty." << endl;
             
      else if (command == "IsFull")
        if (stack.IsFull())
          outFile << "Stack is full." << endl;
        else outFile << "Stack is not full."  << endl;  
	  else cout << "Command not recognized." << endl;
    }
    catch (FullStack)
    {
      outFile << "FullStack exception thrown." << endl;
    }
    
    catch (EmptyStack)
    {
      outFile << "EmtpyStack exception thrown." << endl;
    }    
    numCommands++;
    cout <<  " Command number " << numCommands << " completed." 
         << endl;
    inFile >> command;
 
  };
 
  cout << "Testing completed."  << endl;
  inFile.close();
  outFile.close();
  */
  return 0;
}


