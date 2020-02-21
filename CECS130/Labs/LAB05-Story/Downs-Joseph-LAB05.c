/*
 * Joseph Downs
 * LAB 05
 * 2020.02.21
 * This program generates stories by asking the user information about
 * themselves, and inputting that information into a defined structure.
 */

#include <stdio.h>
#include <time.h>

void take_input();
void print_story();
int rand();
int srand();

int age = 0;
char name[50] = {"\0"};
char color[50] = {"\0"};
char language[50] = {"\0"};

/* 
 * Takes int and string inputs from the user and stores them in variables to
 * be used within the randomly 'generated' story.
 */
void take_input()
{ 
  printf("Please answer some questions.\n");
  printf("What is your name? ");
  scanf("%s", name);
  printf("How old are you? ");
  scanf("%d", &age);
  printf("What is your favorite color? ");
  scanf("%s", color);
  printf("What language do you speak? ");
  scanf("%s", language);
  printf("Your name is %s and you are %d years old.\n", name, age);
  printf("You speak %s.\n", language);
}
char *favorite_item;
char *fav_item_verb;
char *fav_item_make;
char *activity_time;
char *language_activity;
char *fav_item_preposition;

/*
 * Uses the input taken from take_input() and prints out the randomly 'generated'
 * story to console.
 */
void print_story()
{
  srand(time(NULL));
  /* Random int from 0 to 2. */
  int rand_num1 = rand() % 3;
  if (rand_num1 == 0)
    {
      favorite_item = "car";
      fav_item_verb = "driving";
      fav_item_make = "Ferrari LaFerrari";
      language_activity = "speak";
      fav_item_preposition = "in";
    }
  else if (rand_num1 == 1)
    {
      favorite_item = "computer";
      fav_item_verb = "gaming on";
      fav_item_make = "Alienware";
      language_activity = "type";
      fav_item_preposition = "on";
    }
  else if (rand_num1 == 2)
    {
      favorite_item = "guitar";
      fav_item_verb = "strumming";
      fav_item_make = "Fender";
      language_activity = "sing in";
      fav_item_preposition = "while playing";
    }
  
  /* Generates second random int from 0 to 2 */
  int rand_num2 = rand() % 3;
  if (rand_num2 == 1)
    {
      activity_time = "hours";
    }
  else if (rand_num2 == 1)
    {
      activity_time = "minutes";
    }
  else if (rand_num2 == 2)
    {
      activity_time = "seconds";
    }
  
  printf("%s is %d years old and likes their %s %s. ", name, age, color, favorite_item);
  printf("%s spends many %s per day %s their %s. ", name, activity_time, fav_item_verb, favorite_item);
  printf("It is a %s. ", fav_item_make);
  printf("They also like to %s %s %s their %s %s. ",
	 language_activity,
	 language,
	 fav_item_preposition,
	 color,
	 favorite_item);
  printf("%s wishes they could spend all day %s their %s!\n", name, fav_item_verb, favorite_item);
}

int main()
{
  take_input();
  print_story();
  
}
