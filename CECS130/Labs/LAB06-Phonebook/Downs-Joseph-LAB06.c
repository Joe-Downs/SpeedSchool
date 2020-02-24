/*
 * Joseph Downs
 * LAB 06
 * 2020.02.28
 * This program can add, delete, and view contact information for any person
 * the user wants.
 */

#include <stdio.h>

void menu_prompt();
void add_contact();
void delete_contact();
void list_contacts();

int user_choice = 0;

void menu_prompt()
{
  printf("Phone Book\n");
  printf(" 1. Add Contact\n");
  printf(" 2. Delete Contact\n");
  printf(" 3. List Contacts\n");
  printf(" 4. Exit\n");
  printf("\n");
  printf("Choose an option: ");
  scanf("%d", &user_choice);
}

void add_contact()
{
}

void delete_contact()
{
}

void list_contacts()
{
}

int main()
{
  while (user_choice != 4)
    {
      menu_prompt();
      if (user_choice == 1)
	{
	  add_contact();
	}
      else if (user_choice == 2)
	{
	  delete_contact();
	}
      else if (user_choice == 3)
	{
	  list_contacts();
	}
    }
}
