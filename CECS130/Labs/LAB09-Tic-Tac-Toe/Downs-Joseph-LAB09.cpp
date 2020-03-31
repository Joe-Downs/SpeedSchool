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
#include <string.h>
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
bool is_draw();

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
  if (row == 'A' || row == 'a')
    {
      row_offset = 0;
    }
  else if (row == 'B' || row == 'b')
    {
      row_offset = 9;
    }
  else if (row == 'C' || row == 'c')
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
  if (column > 3 || column < 1 || row == ' ')
    {
      return -1;
    }
  if (row == 'A' || row == 'a')
    {
      row_offset = 0;
    }
  else if (row == 'B' || row == 'b')
    {
      row_offset = 3;
    }
  else if (row == 'C' || row == 'c')
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

string cpu_plays[5];
int cpu_plays_index = 0;

void cpu_move()
{
  int center_index = board_plays_index('B', 2);
  char rows[6] = {' ', 'A', 'B', 'C', ' ', ' '};
  int n;
  int cpu_col;
  if (is_valid(center_index))
    {
      update_board('B', 2, 'O');
      TTT_board.place_piece('B', 2, 'O');
      cpu_plays[cpu_plays_index] = "B2";
      cpu_plays_index += 1;
      return;
    }
  if (cpu_plays_index == 0)
    {
      update_board('A', 1, 'O');
      TTT_board.place_piece('A', 1, 'O');
      cpu_plays[cpu_plays_index] = "A1";
      cpu_plays_index += 1;
      return;
      
    }
  int row_letter_index;
  int cpu_play_index;
  for (n=0; n < cpu_plays_index; n++)
    {
      if (cpu_plays[n].rfind("A") == 0)
	{
	  row_letter_index = 1;
	}
      else if (cpu_plays[n].rfind("B") == 0)
	{
	  row_letter_index = 2;
	}
      else if (cpu_plays[n].rfind("C") == 0)
	{
	  row_letter_index = 3;
	}
      if (cpu_plays[n].rfind("1") == 1)
	{
	  cpu_col = 1;
	}
      else if (cpu_plays[n].rfind("2") == 1)
	{
	  cpu_col = 2;
	}
      else if (cpu_plays[n].rfind("3") == 1)
	{
	  cpu_col = 3;
	}
      int c, r;
      for (c = -1; c < 3; c++)
	{
	  int new_col = cpu_col + c;
	  cout<<"New Col = "<<new_col<<endl;
	  for (r = -1; r < 3; r++)
	    {
	      int new_row_index = row_letter_index + r;
	      char new_row = rows[new_row_index];
	      cpu_play_index = board_plays_index(new_row, new_col);
	      cout<<"Checking "<<new_row<<new_col<<endl;
	      if (is_valid(cpu_play_index))
		{
		  cout<<"Found match!"<<endl;
		  update_board(new_row, new_col, 'O');
		  TTT_board.place_piece(new_row, new_col, 'O');
		  char new_location[3] = {new_row};
		  new_location[1] = (char) new_col;
		  cpu_plays[cpu_plays_index] = new_location;
		  cpu_plays_index;
		  return;
		}
	    }
	}
    }
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
	      row_matches += 1;
	    }
	  if (do_match(rows[i], n+1, rows[i+1], n+1))
	    {
	      col_matches += 1;
	    }
	}
      if (row_matches == 2)
	{
	  return true;
	}
      if (col_matches == 2)
	{
	  return true;
	}
    }
  if (do_match(rows[0], 1, rows[1], 2) && do_match(rows[1], 2, rows[2], 3))
    {
      return true;
    }
  if (do_match(rows[2], 1, rows[1], 2) && do_match(rows[1], 2, rows[0], 3))
    {
      return true;
    }
  return false;
}

/* 
 * Calls is_valid() function for each square on the board, if each is NOT
 * valid, then the board is full. If the board is full, and is_over() is 
 * FALSE, then a draw has occurred.
 */
bool is_draw()
{
  int n;
  for (n=0; n < 9; n++)
    {
      if (is_valid(n))
	{
	  return false;
	}
    }
  return true;
}

int main()
{
  string end_message;
  string usr_win = "You have won! Congratulations!";
  string cpu_win = "CPU has won. Better luck next time!";
  string draw = "Draw. Everyone loses.";
  
  srand(time(NULL));
  int first_play = rand() % 2;
  cout<<endl;
  
  /* User plays first */
  if (first_play == 0)
    {
      cout<<"User plays first."<<endl;
      cout<<endl;
      while (!is_over() ^ is_draw())
	{
	  print_board();
	  user_move();
	  if (is_over() ^ is_draw())
	    {
	      /* User has won OR draw, no need for CPU to play */
	      end_message = usr_win;
	    }
	  else
	    {
	      cpu_move();
	      end_message = cpu_win;
	    }
	}
    }
  /* CPU plays first */
  else
    {
      cout<<"CPU plays first."<<endl;
      cout<<endl;
      while (!is_over() ^ is_draw())
	{
	  cpu_move();
	  print_board();
	  if (is_over() ^ is_draw())  
	    {
	      /* CPU has won OR draw, no need for user to play */
	      end_message = cpu_win;
	    }
	  else
	    {
	      user_move();
	      end_message = usr_win;
	    }
	}
    }
  if (is_draw() && !is_over())
    {
      end_message = draw;
    }
  print_board();
  cout<<end_message<<endl;
  cout<<endl;
  cout<<"Thanks for playing!"<<endl;
  cout<<endl;
  
}
