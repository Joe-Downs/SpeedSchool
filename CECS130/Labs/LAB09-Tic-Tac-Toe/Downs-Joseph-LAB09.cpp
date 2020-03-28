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

class board
{
public:
  void print_board();
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
  
/* Prints out updated board after each move */
void print_board()
{
  cout<<endl;
  cout<<A1[0]<<"|"<<A2[0]<<"|"<<A3[0]<<endl;
  cout<<A1[1]<<"|"<<A2[1]<<"|"<<A3[1]<<endl;
  cout<<A1[2]<<"|"<<A2[2]<<"|"<<A3[2]<<endl;
  cout<<"-----+-----+-----"<<endl;
  cout<<B1[0]<<"|"<<B2[0]<<"|"<<B3[0]<<endl;
  cout<<B1[1]<<"|"<<B2[1]<<"|"<<B3[1]<<endl;
  cout<<B1[2]<<"|"<<B2[2]<<"|"<<B3[2]<<endl;
  cout<<"-----+-----+-----"<<endl;
  cout<<C1[0]<<"|"<<C2[0]<<"|"<<C3[0]<<endl;
  cout<<C1[1]<<"|"<<C2[1]<<"|"<<C3[1]<<endl;
  cout<<C1[2]<<"|"<<C2[2]<<"|"<<C3[2]<<endl;
  cout<<endl;
}


int main()
{
  print_board();
}
