/*
 * Joseph Downs
 * LAB 07
 * 2020.03.06
 * This program builds upon LAB 6's phonebook and can add, delete,
 * and view contact information for any person the user wants. In
 * addition, LAB 7 adds the options for the user to sort the list
 * of entries by first or last name, list a specific contact's
 * information, randomly select a contact, and delete every
 * contact in the phonebook at once. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu_prompt();
void add_contact();
void delete_contact();
void list_all();
void display_contact(int, int);
int contact_search();

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

/* 
 * Prompts user for a first and last name, searches through phonebook for
 * contact and returns index number of its location or -1 if the contact
 * could not be found.
 */
int contact_search()
{
  int n;
  int index = -1; /* Default value = NOT FOUND */
  char search_first[50] = {"\0"};
  char search_last[50] = {"\0"};
  printf("First Name: ");
  scanf("%s", search_first);
  printf("Last Name: ");
  scanf("%s", search_last);
  if (current_index > 0)
    {
      for (n = 0; n < current_index; n++)
	{
	  if ((strcmp(phonebook[n].contact_first, search_first) == 0) &&
	      (strcmp(phonebook[n].contact_last, search_first) == 0))
	    {
	      return n;
	    }
	}
      if (n == -1)
	{
	  printf("The contact could not be found.\n");
	  return n;
	}
    } 
}

void delete_contact()
{
  printf("Choose the contact to delete.\n");
  int found_index = contact_search();
  int n;
  if (found_index == -1)
    {
      return;
    }
  struct contact *tmp;
  /*
  char deleted_first[50];
  strcpy(deleted_first, phonebook[found_index].contact_first);
  printf("%s", phonebook[1].contact_first);
  char deleted_last[50];
  strcpy(deleted_last, phonebook[found_index].contact_last);
  printf("%s", phonebook[1].contact_first);
  /*
  int contact_found = 0; /* 0 = FALSE; 1 = TRUE 
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
  */
  for (n = found_index; n < current_index; n++)
    {
      phonebook[n] = phonebook[n+1];
    }
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
  printf("\n");
  /*  printf("Deleted %s %s from the list.\n", deleted_first, deleted_last);*/
  printf("\n");
}

/* Calls list_contact() function for every contact in the array */
void list_all()
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

/* Prints out one single contact */
void display_contact(int is_one, int index)
{
  /* 0 = FALSE; 1 = TRUE */
  if (is_one == 1)
    {
      
    }
  
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
	  list_all();
	}
      
    }
  free(phonebook);
}
