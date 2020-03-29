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
#include <time.h>

using namespace std;

void update_board(char row, int column, char choice);
void print_board();
void user_move();
void cpu_move();
bool is_valid(char row, int column);
bool is_over();

class board
{
public:
  /* Locations for each square; can be empty, X, or O */
  char A1, A2, A3;
  char B1, B2, B3;
  char C1, C2, C3;
};

board TTT_board;


/* Arrays to hold the strings used to construct the TTT board. */
string squares[27] = {"     ", "     ", "     ",  /* A1 */
		      "     ", "     ", "     ",  /* A2 */
		      "     ", "     ", "     ",  /* A3 */
		      "     ", "     ", "     ",  /* B1 */
		      "     ", "     ", "     ",  /* B2 */
		      "     ", "     ", "     ",  /* B3 */
		      "     ", "     ", "     ",  /* C1 */
		      "     ", "     ", "     ",  /* C2 */
		      "     ", "     ", "     ",};/* C3 */

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
  int row_offset;
  if (row == 'A')
    {
      row_offset = 0;
    }
  else if (row == 'B')
    {
      row_offset = 9;
    }
  else if (row == 'C')
    {
      row_offset = 18;
    }
  int index = 3 * (column - 1) + row_offset;
  squares[index] = line1;
  squares[index+1] = line2;
  squares[index+2] = line3;
}
  
/* Prints out updated board after each move */
void print_board()
{
  int n;
  string row_letter;
  string row_blank = "  ";
  string * letter_pointer = &row_letter;
  string * blank_pointer = &row_blank;
  string * row_label[3] = {blank_pointer, letter_pointer, blank_pointer};
  cout<<endl;
  cout<<"    1     2     3         "<<endl;
  row_letter = "A ";
  for (n = 0; n < 3; n++)
    {
      cout<<*row_label[n];
      cout<<squares[n]<<"|"<<squares[n+3]<<"|"<<squares[n+6]<<endl;
    }
  cout<<"  -----+-----+-----"<<endl;
  row_letter = "B ";
  for (n = 0; n < 3; n++)
    {
      cout<<*row_label[n];
      cout<<squares[n+9]<<"|"<<squares[n+12]<<"|"<<squares[n+15]<<endl;
    }
  cout<<"  -----+-----+-----"<<endl;
  row_letter = "C ";
  for (n = 0; n < 3; n++)
    {
      cout<<*row_label[n];
      cout<<squares[n+18]<<"|"<<squares[n+21]<<"|"<<squares[n+24]<<endl;
    }
  cout<<endl;
}

bool is_valid(char row, int column)
{
  if (row == 'A')
    {
      if (column == 1)
	{
	  if (TTT_board.A1 == 'X'|| TTT_board.A1 == 'O')
	    {
	      return false;
	    }
	  return true;
	}
      else if (column == 2)
	{
	  if (TTT_board.A2 == 'X'|| TTT_board.A2 == 'O')
	    {
	      return false;
	    }
	  return true; 
	}
      else if (column == 3)
	{
	  if (TTT_board.A3 == 'X'|| TTT_board.A3 == 'O')
	    {
	      return false;
	    }
	   return true;
	}
    }
  else if (row == 'B')
    {   
      if (column == 1)
	{
	  if (TTT_board.B1 == 'X'|| TTT_board.B1 == 'O')
	    {
	      return false;
	    }
	  return true;
	}
      else if (column == 2)
	{
	  if (TTT_board.B2 == 'X'|| TTT_board.B2 == 'O')
	    {
	      return false;
	    }
	  return true;
	}
      else if (column == 3)
	{
	  if (TTT_board.B3 == 'X'|| TTT_board.B3 == 'O')
	    {
	      return false;
	    }
	  return true;
	}
    }
  else if (row == 'C')
    {   
      if (column == 1)
	{
	  if (TTT_board.C1 == 'X'|| TTT_board.C1 == 'O')
	    {
	      return false;
	    }
	  return true;
	}
      else if (column == 2)
	{
	  if (TTT_board.C2 == 'X'|| TTT_board.C2 == 'O')
	    {
	      return false;
	    }
	  return true;
	}
      else if (column == 3)
	{
	  if (TTT_board.C3 == 'X'|| TTT_board.C3 == 'O')
	    {
	      return false;
	    }
	  return true;
	}
    }
  return false;
}

void user_move()
{
  char user_row;
  int user_column;
  cout<<"Choose a square: ";
  cin>>user_row>>user_column;
  if (is_valid(user_row, user_column))
    {
      update_board(user_row, user_column, 'X');
      return;
    }
  else
    {
      cout<<"Not a valid move. Please try again."<<endl;
      user_move();
    }
}

void cpu_move()
{
  
}

bool is_over()
{
  
}


int main()
{
  string win_message;
  string usr_win = "You have won! Congratulations!";
  string cpu_win = "CPU has won. Better luck next time!";
  
  srand(time(NULL));
  int first_play = rand() % 2;
  cout<<endl;
  
  /* User plays first */
  if (first_play == 0)
    {
      cout<<"User plays first."<<endl;
      cout<<endl;
      do
	{
	  print_board();
	  user_move();
	  if (is_over())
	    {
	      /* User has won, no need for CPU to play */
	      win_message = usr_win;
	    }
	  else
	    {
	      cpu_move();
	      win_message = cpu_win;
	    }
	}
      while (!is_over());
    }
  /* CPU plays first */
  else
    {
      cout<<"CPU plays first."<<endl;
      cout<<endl;
      do
	{
	  print_board();
	  cpu_move();
	  if (is_over())
	    {
	      /* CPU has won, no need for user to play */
	      win_message = cpu_win;
	    }
	  else
	    {
	      user_move();
	      win_message = usr_win;
	    }
	}
      while (!is_over());
    }
  cout<<win_message<<endl;
  cout<<endl;
  cout<<"Thanks for playing!"<<endl;
  cout<<endl;
  
}
