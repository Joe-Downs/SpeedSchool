/*
 * Joseph Downs
 * LAB 06
 * 2020.02.28
 * This program can add, delete, and view contact information for any person
 * the user wants.
 */

#include <stdio.h>

void menu_prompt();

int user_choice = 0;

void menu_prompt()
{
  printf("Phone Book\n");
  printf(" 1. Add Friend\n");
  printf(" 2. Delete Friend\n");
  printf(" 3. List contacts\n");
  printf(" 4. Exit\n");
  printf("\n");
  printf("Choose an option: ");
  scanf("%d", &user_choice);
}

int main()
{
  while (user_choice != 4)
    {
      menu_prompt();
    }
}
