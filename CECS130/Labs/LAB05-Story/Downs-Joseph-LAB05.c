/*
 * Joseph Downs
 * LAB 05
 * 2020.02.21
 * This program generates interactive stories by asking the user information
 * about themselves, and inputting that information into a defined structure.
 */

#include <stdio.h>

void take_input();

void take_input()
{
  int age = 0;
  char name[50] = {"\0"};
  char color[50] = {"\0"};
  char language[50] = {"\0"};
  
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

int main()
{
  take_input();
}
