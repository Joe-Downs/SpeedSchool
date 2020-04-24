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
void playPoker();
int takeBet();
void playHand(int bet);
void outcome(int bet);
void generateReport();

/* Card class that has a numeric value and a suit */
class Card
{
public:
  int value;
  char suit;
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
  cout<<"Everyday I'm shuffling..."<<endl;
  random_shuffle(begin(deck), end(deck));
}

 /* Player starts with 100 USD */
int playerBalance = 100;
int handsPlayed = 0;
int handsWon = 0;

void playPoker()
{
  char playerResponse;
  int playerBet;
  cout<<"Would you like to play a hand? ";
  cin>>playerResponse;
  if (playerResponse == 'n' || playerResponse == 'N')
    {
      return;
    }
  if (playerBalance <= 0)
    {
      cout<<"Too rich for your blood, sorry."<<endl;
      return;
    }
  else
    {
      cin.clear();
      cin.ignore(1000, '\n');
      playerBet = takeBet();
      playHand(playerBet);
      playPoker();
    }
}

int takeBet()
{
  int bet = 0;
  cout<<"What is your bet? [1-"<<playerBalance<<"] ";
  cin>>bet;
  if (bet >= 1 && bet <= playerBalance)
    {
      return bet;
    }
  cin.clear();
  cin.ignore(1000, '\n');
  takeBet();
}

/* Takes bet, plays hand, and updates bank accordingly by calling outcome() */
void playHand(int bet)
{
  shuffleDeck();
  cout<<endl;
  int i;
  for (i = 0; i < 4; i++)
    {
      deck[i].printCard();
    }
  cout<<endl;
  cout<<endl;
  outcome(bet);
}

/* Determines and prints the results and updates the bank */
void outcome(int bet)
{
  handsPlayed += 1;
  int winMultiplier;
  string winType;
  int n;
  int sortedValues[4];
  for (n = 0; n < 3; n++)
    {
      sortedValues[n] = deck[n].value;
    }
  sort(begin(sortedValues), end(sortedValues));
  int val1 = sortedValues[0];
  int val2 = sortedValues[1];
  int val3 = sortedValues[2];
  int val4 = sortedValues[3];
  char suit1 = deck[0].suit;
  char suit2 = deck[1].suit;
  char suit3 = deck[2].suit;
  char suit4 = deck[3].suit;
  if ((val1 == val2) && (val2 == val3) && (val3 == val4))
    {
      winMultiplier = 400;
      winType = "Four of a Kind";
    }
  else if ((val1 + 1 == val2) && (val2 + 1 == val3) && (val3 + 1 == val4))
    {
      winMultiplier = 200;
      winType = "Straight";
      if ((suit1 == suit2) && (suit2 == suit3) && (suit3 == suit4))
	{
	  winMultiplier = 300;
	  winType = "Straight Flush";
	}
    }
  else if ((suit1 == suit2) && (suit2 == suit3) && (suit3 == suit4))
    {
      winMultiplier = 250;
      winType = "Flush";
    }
  else if (((val1 == val2) && (val2 == val3)) || ((val2 == val3) && (val3 == val4)))
    {
      winMultiplier = 150;
      winType = "Three of a Kind";
    }
  else if (((val1 == val2) && (val3 == val4)) || ((val1 == val4) && (val2 == val3)))
    {
      winMultiplier = 100;
      winType = "Two Pair";
    }
  else if ((val1 == val2) || (val1 == val3) || (val1 == val4) || (val2 == val3) || (val2 == val4) || (val3 == val4))
    {
      winMultiplier = 1;
      winType = "Two of a Kind";
    }
  else
    {
      cout<<"Sorry, you got Bubkiss and have lost "<<bet<<" USD."<<endl;
      playerBalance -= bet;
      return;
    }
  handsWon += 1;
  playerBalance += (bet * winMultiplier);
  cout<<"Congratulations! You got a "<<winType<<" and made "<<bet * winMultiplier<<" USD."<<endl;
}

void generateReport()
{
  
}

int main()
{
  cout<<"Welcome to Poker!"<<endl;
  cout<<"You start with "<<playerBalance<<endl;
  cout<<endl;
  playPoker();
  generateReport();
  cout<<"Thanks for playing!"<<endl;
}
