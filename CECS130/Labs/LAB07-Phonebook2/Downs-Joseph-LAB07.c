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
void print_contact(int);
int contact_search();
void sort_phonebook(int);
int sort_entry(int, int);

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
  printf(" 4. Individual Search\n");
  printf(" 5. Sort Phone Book\n");
  printf(" 6. Exit\n");
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
  int n = -1; /* Default value = NOT FOUND */
  char search_first[50] = {"\0"};
  char search_last[50] = {"\0"};
  if (current_index == 0)
    {
      printf("You have added no contacts.\n");
      printf("\n");
      return n;
    }
  else
    {
      printf("First Name: ");
      scanf("%s", search_first);
      printf("Last Name: ");
      scanf("%s", search_last);
      for (n = 0; n < current_index; n++)
	{
	  /*
	  printf("n = %d\n", n);
	  printf("%d\n", strcmp(phonebook[n].contact_first, search_first));
	  printf("%d\n", strcmp(phonebook[n].contact_last, search_last));
	  */
	  if (strcmp(phonebook[n].contact_first, search_first) == 0 && strcmp(phonebook[n].contact_last, search_last) == 0)
	    {
	      return n;
	    }
	}
      printf("\n");
      printf("The contact could not be found.\n");
      printf("\n");
      n = -1;
      return n;
    } 
}

void delete_contact()
{
  printf("Choose the contact to delete.\n");
  printf("\n");
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
  if (tmp == NULL && current_index > 0)
    {
      printf("Failed to allocate memory.\n");
    }
  else
    {
      phonebook = tmp;
    }
  printf("\n");
  /*
  printf("Deleted %s %s from the list.\n", deleted_first, deleted_last);
  printf("\n");
  */
}

/* Calls print_contact() function for every contact in the array */
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
	  print_contact(i);
	}
    }
  printf("\n");
}

/* Prints out one single contact given the index */
void print_contact(int index)
{
  printf("%s\t%s %s\n",
	 phonebook[index].contact_number,
	 phonebook[index].contact_first,
	 phonebook[index].contact_last);
}

/* Decides if which entry goes before or after another */
int sort_entry(int entry1, int entry2)
{
  
}

/* Sorts phonebook by first (1) or last (2) name */
void sort_phonebook(int sort)
{
  int n;
  int i;
  int index_first; /* Index of first-occurring value */
  if (sort == 1)
    {
      for (n = 0, n < current_index; ++n)
	{
	  
	}
    }
  else if (sort == 2)
    {
      
    }
  else
    {
      printf("Sorry, that is not a valid option");
      return;
    }
  printf("Phone book has been sorted.\n");
  printf("\n");
}

int main()
{
  int desired_index = -1;
  int sort_choice;
  while (user_choice != 6)
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
      else if (user_choice == 4)
	{
	  printf("Who would you like to call?\n");
	  printf("\n");
	  desired_index = contact_search();
	  if (desired_index != -1)
	    {
	      printf("\n");
	      print_contact(desired_index);
	      printf("\n");
	    }
	}
      else if (user_choice == 5)
	{
	  printf("Sort phone book by:\n");
	  printf("(1) First\n");
	  printf("(2) Last Name\n");
	  printf("Choose an option: ");
	  scanf("%d", &sort_choice);
	  printf("\n");
	  sort_phonebook(sort_choice);
	}
      
    }
  free(phonebook);
}
