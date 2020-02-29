/*
 * Joseph Downs
 * LAB 06
 * 2020.02.28
 * This program can add, delete, and view contact information for any person
 * the user wants.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu_prompt();
void add_contact();
void delete_contact();
void list_contacts();

/* Struct to be hold contact info, each is put into array */
struct contact
{
  char contact_first[50];
  char contact_last[50];
  char contact_number[50];
};

/* Array of structures to hold contacts themselves */
struct contact *phonebook;

int user_choice = 0;
int current_index = 0;
  
void menu_prompt()
{
  printf("Phone Book Options\n");
  printf(" 1. Add Contact\n");
  printf(" 2. Delete Contact\n");
  printf(" 3. List Contacts\n");
  printf(" 4. Exit\n");
  printf("\n");
  printf("Choose an option: ");
  scanf("%d", &user_choice);
  printf("\n");
}

void add_contact()
{
  char first_name[50] = {"\0"};
  char last_name[50] = {"\0"};
  char phone_number[50] = {"\0"};
  printf("First Name: ");
  scanf("%s", first_name);
  printf("Last Name: ");
  scanf("%s", last_name);
  printf("Phone Number: ");
  scanf("%s", phone_number);
  phonebook = realloc(phonebook, (current_index + 1) * sizeof(struct contact));
  if (phonebook != NULL)
    {
      strcpy(phonebook[current_index].contact_first, first_name);
      strcpy(phonebook[current_index].contact_last, last_name);
      strcpy(phonebook[current_index].contact_number, phone_number);
    }
  else
    {
      printf("Failed to allocate memory.\n");
    }
  current_index = current_index + 1;
  printf("\n");
  printf("Contact added to phone book.\n");
  printf("\n");
}

void delete_contact()
{
  int n;
  int contact_found = 0; /* 0 = FALSE; 1 = TRUE */
  char deleted_first[50] = {"\0"};
  char deleted_last[50] = {"\0"};
  struct contact *tmp;
  printf("Choose the contact to delete.\n");
  printf("First Name: ");
  scanf("%s", deleted_first);
  printf("Last Name: ");
  scanf("%s", deleted_last);
  if (current_index > 0)
    {
      for (n = 0; n < current_index; n++)
	{
	  if ((strcmp(phonebook[n].contact_first, deleted_first)) == 0 &&
	      ((strcmp(phonebook[n].contact_last, deleted_last)) == 0))
	    {
	      for (n = n; n < current_index; n++)
		{
		  phonebook[n] = phonebook[n+1];
		}
	      contact_found = 1;
	      current_index = current_index - 1;
	      tmp = realloc(phonebook, current_index * sizeof(struct contact));
	      if (tmp == NULL)
		{
		  printf("Failed to allocate memory.\n");
		}
	      else
		{
		  phonebook = tmp;
		}
	    }
	}
    }
  printf("\n");
  if (contact_found == 1)
    {
      printf("Deleted %s %s from the list.\n", deleted_first, deleted_last);
    }
  else if (contact_found == 0)
    {
      printf("The contact could not be found.\n");
    }
  printf("\n");
}

void list_contacts()
{
  int i;
  if (current_index == 0)
  {
    printf("You have added no contacts.\n");
  }
  else
    {
      printf("Contacts:\n");
      for (i = 0; i < current_index; ++i)
	{
	  printf("%s\t%s %s\n",
		 phonebook[i].contact_number,
		 phonebook[i].contact_first,
		 phonebook[i].contact_last);
	}
    }
  printf("\n");
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
  free(phonebook);
}
