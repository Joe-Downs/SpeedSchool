/*
 * Joseph Downs
 * LAB 10
 * 2020.05.04
 * This programs utilzies ASCII art to display a 3D Tic-Tac-Toe
 * board. (Three normal TTT boards stacked on top of each other)
 * The user plays against the computer (who goes first is
 * randomly decided before play begins). O's and X's are 
 * 'drawn' in after each move is made. If an illegal move is
 * made, the user is informed so that they can try again.
 */

#include <iostream>
#include <cstdlib>
#include <ctype.h>
#include <string>
#include <time.h>

using namespace std;

void update_board(int layer, char row, int column, char choice);
void print_board();
int board_plays_index(int layer, char row, int column);
void user_move();
void cpu_move();
bool is_valid(char row, int column);
bool do_match(char row1, int col1, char row2, int col2);
bool is_over();
bool is_draw();

class Board
{
public:
  void place_piece(int layer, char row, int column, char choice);
  /* 
   * Locations for each square; can be empty, X, or O
   * Index 0 = A11, 1 = A12, 2 = A3, and so on
   */
  char board_plays[27] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			 ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			 ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
};

Board TTT_board;

/* Places a piece on the class instance of Board */
void Board::place_piece(int layer, char row, int column, char choice)
{
  int play_index = board_plays_index(layer, row, column);
  board_plays[play_index] = choice;
}

/* Arrays to hold the strings used to construct the TTT board. */
string squares[81] = {"     ", "     ", "     ", /* A1-1 */
		      "     ", "     ", "     ", /* A1-2 */
		      "     ", "     ", "     ", /* A1-3 */
		      "     ", "     ", "     ", /* B1-1 */
		      "     ", "     ", "     ", /* B1-2 */
		      "     ", "     ", "     ", /* B1-3 */
		      "     ", "     ", "     ", /* C1-1 */
		      "     ", "     ", "     ", /* C1-2 */
		      "     ", "     ", "     ", /* C1-3 */
		      "     ", "     ", "     ", /* A2-1 */
		      "     ", "     ", "     ", /* A2-2 */
		      "     ", "     ", "     ", /* A2-3 */
		      "     ", "     ", "     ", /* B2-1 */
		      "     ", "     ", "     ", /* B2-2 */
		      "     ", "     ", "     ", /* B2-3 */
		      "     ", "     ", "     ", /* C2-1 */
		      "     ", "     ", "     ", /* C2-2 */
		      "     ", "     ", "     ", /* C2-3 */
		      "     ", "     ", "     ", /* A3-1 */
		      "     ", "     ", "     ", /* A3-2 */
		      "     ", "     ", "     ", /* A3-3 */
		      "     ", "     ", "     ", /* B3-1 */
		      "     ", "     ", "     ", /* B3-2 */
		      "     ", "     ", "     ", /* B3-3 */
		      "     ", "     ", "     ", /* C3-1 */
		      "     ", "     ", "     ", /* C3-2 */
		      "     ", "     ", "     "};/* C3-3 */

/* Updates the 'physical' board given a row, column, and choice */
void update_board(int layer, char row, int column, char choice)
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
      line2 = " |O| ";
      line3 = " \\ / ";
    }
  int layer_offset = 27 * (layer - 1);
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
  int index = layer_offset + (3 * (column - 1)) + row_offset;
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
  cout<<"       Layer 1     \t     Layer 2     \t     Layer 3"<<endl;
  cout<<"    1     2     3  \t  1     2     3  \t  1     2     3"<<endl;
  row_letter = "A ";
  for (n = 0; n < 3; n++)
    {
      cout<<*row_label[n];
      cout<<squares[n]<<"|"<<squares[n+3]<<"|"<<squares[n+6]<<"\t";
      cout<<squares[n+27]<<"|"<<squares[n+30]<<"|"<<squares[n+33]<<"\t";
      cout<<squares[n+54]<<"|"<<squares[n+57]<<"|"<<squares[n+60]<<endl;
    }
  cout<<"  -----+-----+-----\t-----+-----+-----\t-----+-----+-----"<<endl;
  row_letter = "B ";
  for (n = 0; n < 3; n++)
    {
      cout<<*row_label[n];
      cout<<squares[n+9]<<"|"<<squares[n+12]<<"|"<<squares[n+15]<<"\t";
      cout<<squares[n+36]<<"|"<<squares[n+39]<<"|"<<squares[n+42]<<"\t";
      cout<<squares[n+63]<<"|"<<squares[n+66]<<"|"<<squares[n+69]<<endl;
    }
  cout<<"  -----+-----+-----\t-----+-----+-----\t-----+-----+-----"<<endl;
  row_letter = "C ";
  for (n = 0; n < 3; n++)
    {
      cout<<*row_label[n];
      cout<<squares[n+18]<<"|"<<squares[n+21]<<"|"<<squares[n+24]<<"\t";
      cout<<squares[n+45]<<"|"<<squares[n+48]<<"|"<<squares[n+51]<<"\t";
      cout<<squares[n+72]<<"|"<<squares[n+75]<<"|"<<squares[n+78]<<endl;
    }
  cout<<endl;
}

/* 
 * Given a layer, row, and column, returns the index corresponding to the
 * index of the Board class' array of squares.
 */
int board_plays_index(int layer, char row, int column)
{
  int layer_offset = 9 * (layer-1);
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
  index = layer_offset + row_offset + (column - 1);
  return index;
}

/*
 * Checks if the space on a board is open. TRUE if it is.
 * Index refers to the index of the Board class' array of squares
 */
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

/* Prompts user for their move and updates the boards accordingly */
void user_move()
{
  int user_layer;
  char user_row;
  int user_column;
  int index;
  cout<<"Please input your choice as [Layer][Row][Column]"<<endl;
  cout<<"e.g., 1A1 is on Layer 1, Row A, Column 1"<<endl;
  cout<<"Choose a square: ";
  cin>>user_layer>>user_row>>user_column;
  index = board_plays_index(user_layer, user_row, user_column);
  if (is_valid(index))
    {
      update_board(user_layer, user_row, user_column, 'X');
      TTT_board.place_piece(user_layer, user_row, user_column, 'X');
      return;
    }
  else
    {
      cout<<"Not a valid move. Please try again."<<endl;
      user_move();
    }
}

/* Keeps track of where the CPU has played its pieces */
string cpu_plays[5];
int cpu_plays_index = 0;

/* 
 * Plays piece for the CPU. First move (if available is the center).
 * Then, it looks around its already played spaces for other valid
 * moves in hopes of creating a three-in-a-row.
 */
void cpu_move()
{
  int center_index = board_plays_index(1, 'B', 2);
  char rows[6] = {' ', 'A', 'B', 'C', ' ', ' '};
  int n;
  int cpu_col;
  if (is_valid(center_index))
    {
      update_board(1, 'B', 2, 'O');
      TTT_board.place_piece(1,'B', 2, 'O');
      cpu_plays[cpu_plays_index] = "1B2";
      cpu_plays_index += 1;
      return;
    }
  if (cpu_plays_index == 0)
    {
      update_board(1, 'A', 1, 'O');
      TTT_board.place_piece(1, 'A', 1, 'O');
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
	  for (r = -1; r < 3; r++)
	    {
	      int new_row_index = row_letter_index + r;
	      char new_row = rows[new_row_index];
	      cpu_play_index = board_plays_index(new_row, new_col);
	      if (is_valid(cpu_play_index))
		{
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

/* Checks if two spaces have the same choice. TRUE if they do. */
bool do_match(char row1, int col1, char row2, int col2)
{
  int index1 = board_plays_index(row1, col1);
  int index2 = board_plays_index(row2, col2);
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

/* Checks if the game is over. TRUE if it is */
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
 * FALSE, then a draw has occurred. Returns TRUE if there is a draw.
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
