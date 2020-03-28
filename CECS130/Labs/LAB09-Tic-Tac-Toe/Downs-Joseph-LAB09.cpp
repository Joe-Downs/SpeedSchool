/*
 * Joseph Downs
 * LAB 09
 * 2020.03.27
 * This programs utilzies ASCII art to display a Tic-Tac-Toe
 * board. The user plays against the computer (who goes first
 * is randomly decided before play begins). O's and X's are 
 * 'drawn' in after each move is made. If an illegal move is
 * made, the user is informed so that they can try again.
 */

#include <iostream>
#include <ctype.h>
#include <string>

using namespace std;

void update_board(char row, int column, char choice);
void print_board();

class board
{
public:
  /* Locations for each square; can be empty, X, or O */
  char A1, A2, A3;
  char B1, B2, B3;
  char C1, C2, C3;
};

board TTT_board;


/* 
 * Arays to hold the strings used to construct the TTT board.
 * Each index is a line that makes up the three lines of the block
 */
string A1[3] = {"     ", "     ", "     "};
string A2[3] = {"     ", "     ", "     "};
string A3[3] = {"     ", "     ", "     "};
string B1[3] = {"     ", "     ", "     "};
string B2[3] = {"     ", "     ", "     "};
string B3[3] = {"     ", "     ", "     "};
string C1[3] = {"     ", "     ", "     "};
string C2[3] = {"     ", "     ", "     "};
string C3[3] = {"     ", "     ", "     "};

void update_board(char row, int column, char choice)
{
  string line1;
  string line2;
  string line3;
  if (choice == 'X')
    {
      line1 = " \\ / ";
      line2 = "  X  ";
      line3 = " / \\ ";
    }
  else
    {
      line1 = " / \\ ";
      line2 = " | | ";
      line3 = " \\ / ";
    }
  if (row == 'A')
    {
      if (column == 1)
	{
	  A1[0] = line1;
	  A1[1] = line2;
	  A1[2] = line3;
	}
      else if (column == 2)
	{
	  A2[0] = line1;
	  A2[1] = line2;
	  A2[2] = line3;
	}
      else if (column == 3)
	{
	  A3[0] = line1;
	  A3[1] = line2;
	  A3[2] = line3;
	}
    }
  else if (row == 'B')
    {   
      if (column == 1)
	{
	  B1[0] = line1;
	  B1[1] = line2;
	  B1[2] = line3;
	}
      else if (column == 2)
	{
	  B2[0] = line1;
	  B2[1] = line2;
	  B2[2] = line3;
	}
      else if (column == 3)
	{
	  B3[0] = line1;
	  B3[1] = line2;
	  B3[2] = line3;
	}
    }
  else if (row == 'C')
    {   
      if (column == 1)
	{
	  C1[0] = line1;
	  C1[1] = line2;
	  C1[2] = line3;
	}
      else if (column == 2)
	{
	  C2[0] = line1;
	  C2[1] = line2;
	  C2[2] = line3;
	}
      else if (column == 3)
	{
	  C3[0] = line1;
	  C3[1] = line2;
	  C3[2] = line3;
	}
    }
}
  
/* Prints out updated board after each move */
void print_board()
{
  cout<<endl;
  cout<<"    1     2     3         "<<endl; 
  cout<<"  "<<A1[0]<<"|"<<A2[0]<<"|"<<A3[0]<<endl;
  cout<<"A "<<A1[1]<<"|"<<A2[1]<<"|"<<A3[1]<<endl;
  cout<<"  "<<A1[2]<<"|"<<A2[2]<<"|"<<A3[2]<<endl;
  cout<<"  -----+-----+-----"<<endl;
  cout<<"  "<<B1[0]<<"|"<<B2[0]<<"|"<<B3[0]<<endl;
  cout<<"B "<<B1[1]<<"|"<<B2[1]<<"|"<<B3[1]<<endl;
  cout<<"  "<<B1[2]<<"|"<<B2[2]<<"|"<<B3[2]<<endl;
  cout<<"  -----+-----+-----"<<endl;
  cout<<"  "<<C1[0]<<"|"<<C2[0]<<"|"<<C3[0]<<endl;
  cout<<"C "<<C1[1]<<"|"<<C2[1]<<"|"<<C3[1]<<endl;
  cout<<"  "<<C1[2]<<"|"<<C2[2]<<"|"<<C3[2]<<endl;
  cout<<endl;
}


int main()
{
  print_board();
  update_board('A', 1, 'O');
  print_board();
  update_board('C', 3, 'X');
  print_board();
}
