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
int board_plays_index(char row, int column);
void user_move();
void cpu_move();
bool is_valid(char row, int column);
bool do_match(char row1, int col1, char row2, int col2);
bool is_over();

class Board
{
public:
  void place_piece(char row, int column, char choice);
  /* 
   * Locations for each square; can be empty, X, or O
   * Index 0 = A1, 1 = A2, 2 = A3, and so on
   */
  char board_plays[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
};

Board TTT_board;

void Board::place_piece(char row, int column, char choice)
{
  int play_index = board_plays_index(row, column);
  board_plays[play_index] = choice;
}


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
int board_plays_index(char row, int column)
{
  int row_offset;
  int index;
  if (column > 3)
    {
      return -1;
    }
  if (row == 'A')
    {
      row_offset = 0;
    }
  else if (row == 'B')
    {
      row_offset = 3;
    }
  else if (row == 'C')
    {
      row_offset = 6;
    }
  index = row_offset + (column - 1);
  return index;
}


bool is_valid(int index)
{
  if (index == -1)
    {
      return false;
    }
  if (TTT_board.board_plays[index] == 'X' || TTT_board.board_plays[index] == 'O')
    {
      return false;
    }
  else
    {
      return true;
    }
}

void user_move()
{
  char user_row;
  int user_column;
  int index;
  cout<<"Choose a square: ";
  cin>>user_row>>user_column;
  index = board_plays_index(user_row, user_column);
  if (is_valid(index))
    {
      update_board(user_row, user_column, 'X');
      TTT_board.place_piece(user_row, user_column, 'X');
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

/* Checks if two spaces have the same choice */
bool do_match(char row1, int col1, char row2, int col2)
{
  int index1 = board_plays_index(row1, col1);
  int index2 = board_plays_index(row2, col2);
  /*
  cout<<TTT_board.board_plays[index1]<<endl;
  cout<<TTT_board.board_plays[index2]<<endl;
  */
  if (TTT_board.board_plays[index1] == ' ' || TTT_board.board_plays[index2] == ' ')
    {
      return false;
    }
  if (TTT_board.board_plays[index1] == TTT_board.board_plays[index2])
    {
      return true;
    }
  else
    {
      return false;
    }
}

bool is_over()
{
  int n, i;
  int row_matches;
  int col_matches;
  char rows[3] = {'A', 'B', 'C'};
  for (n = 0; n < 3; n++)
    {
      row_matches = 0;
      col_matches = 0;
      for (i = 0; i < 2; i++)
	{
	  if (do_match(rows[n], i+1, rows[n], i+2))
	    {
	      cout<<"1"<<endl;
	      row_matches += 1;
	    }
	  cout<<rows[i]<<n+1<<endl;
	  cout<<rows[i+1]<<n+1<<endl;
	  if (do_match(rows[i], n+1, rows[i+1], n+1))
	    {
	      cout<<"2"<<endl;
	      col_matches += 1;
	    }
	}
      if (row_matches == 2)
	{
	  cout<<"3"<<endl;
	  return true;
	}
      if (col_matches == 2)
	{
	  cout<<"4"<<endl;
	  return true;
	}
    }
  if (do_match(rows[0], 1, rows[1], 2) && do_match(rows[1], 2, rows[2], 3))
    {
      cout<<"5"<<endl;
      return true;
    }
  if (do_match(rows[2], 1, rows[1], 2) && do_match(rows[1], 2, rows[0], 3))
    {
      cout<<"6"<<endl;
      return true;
    }
  cout<<"7"<<endl;
  return false;
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
  print_board();
  cout<<win_message<<endl;
  cout<<endl;
  cout<<"Thanks for playing!"<<endl;
  cout<<endl;
  
}
