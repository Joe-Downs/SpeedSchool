/*
 * Joseph Downs
 * FINAL PROJECT
 * 2020.04.22
 * This program allows the user to play a single-player
 * poker game. 
 */

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctype.h>
#include <string.h>
#include <time.h>

using namespace std;

void shuffleDeck();

/* Card class that has a numeric value and a suit */
class Card
{
private:
  int value;
  char suit;
public:
  Card(int val, char s)
  {
    value = val;
    suit = s;
  }
  void printCard();
};

/* Prints out the suit and value of a card; leaves space for more */
void Card::printCard()
{
  cout<<value<<suit<<" ";
}

/* The inititally ordered deck */
Card deck[36] = {{1, 'H'}, {2, 'H'}, {3, 'H'}, {4, 'H'}, {5, 'H'}, {6, 'H'}, {7, 'H'}, {8, 'H'}, {9, 'H'},
		 {1, 'C'}, {2, 'C'}, {3, 'C'}, {4, 'C'}, {5, 'C'}, {6, 'C'}, {7, 'C'}, {8, 'C'}, {9, 'C'},
		 {1, 'S'}, {2, 'S'}, {3, 'S'}, {4, 'S'}, {5, 'S'}, {6, 'S'}, {7, 'S'}, {8, 'S'}, {9, 'S'},
		 {1, 'D'}, {2, 'D'}, {3, 'D'}, {4, 'D'}, {5, 'D'}, {6, 'D'}, {7, 'D'}, {8, 'D'}, {9, 'D'}};

/* Shuffles deck[] using the std::random_shuffle function */
void shuffleDeck()
{
  srand(time(NULL));
  random_shuffle(begin(deck), end(deck));
}

int main()
{
  
}
