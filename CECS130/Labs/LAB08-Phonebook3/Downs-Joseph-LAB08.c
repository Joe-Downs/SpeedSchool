/*
 * Joseph Downs
 * LAB 08
 * 2020.03.21
 * This program builds upon LAB 6 and LAB 7's phonebook and can add,
 * delete,and view contact information for any person the user wants.
 * In addition, the user can sort the list of entries by last name,
 * list a specific contact's information, randomly select a contact,
 * and delete every contact in the phonebook at once. LAB 8 adds the
 * ability for the user to save the contact list to a .txt file and
 * load from a previously saved .txt file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void menu_prompt();
void add_to_array(char first_name[50], char last_name[50], char phone_number[50]);
void add_contact();
void delete_contact();
void list_all();
void print_contact(int);
int contact_search();
void individual_search();
void sort_phonebook();
int sort_entry(int, int);
void clear_phonebook();
void random_contact();
void save_phonebook();
void load_phonebook();

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
  printf(" 1.  Add Contact\n");
  printf(" 2.  Delete Contact\n");
  printf(" 3.  List Contacts\n");
  printf(" 4.  Individual Search\n");
  printf(" 5.  Sort Phone Book\n");
  printf(" 6.  Clear Phone Book\n");
  printf(" 7.  Randomly Select Contact\n");
  printf(" 8.  Save to File\n");
  printf(" 9.  Load from File\n");
  printf(" 10. Exit\n");
  printf("\n");
  printf("Choose an option: ");
  scanf("%d", &user_choice);
  printf("\n");
}

void add_to_array(char first_name[50], char last_name[50], char phone_number[50])
{
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
  add_to_array(first_name, last_name, phone_number); 
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
  printf("First Name: ");
  scanf("%s", search_first);
  printf("Last Name: ");
  scanf("%s", search_last);
  for (n = 0; n < current_index; n++)
    {
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

/* Deletes contact as specified by the user */
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
  char deleted_first[50];
  char deleted_last[50];
  strcpy(deleted_first, phonebook[found_index].contact_first);
  strcpy(deleted_last, phonebook[found_index].contact_last);
  struct contact *tmp;
  for (n = found_index; n < current_index - 1; n++)
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
      printf("\n");
      printf("Deleted %s %s from the list.\n", deleted_first, deleted_last);
    }
  printf("\n");
}

/* Calls print_contact() function for every contact in the array */
void list_all()
{
  int i;
  if (current_index == 0)
    {
      printf("You have added no contacts.\n");
      printf("\n");
      return;
    }
  printf("Contacts:\n");
  for (i = 0; i < current_index; ++i)
    {
      print_contact(i);
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

void individual_search()
{
  if (current_index == 0)
    {
      printf("You have added no contacts.\n");
      printf("\n");
      return;
    }
  int desired_index;
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

/* Decides which entry goes before or after another */
int sort_entry(int entry1_index, int entry2_index)
{
  int n;
  char entry1_last[50];
  char entry2_last[50];
  strcpy(entry1_last, phonebook[entry1_index].contact_last);
  strcpy(entry2_last, phonebook[entry2_index].contact_last);
  for (n = 0; n < 49; n++)
    {
      if (entry1_last[n] > entry2_last[n])
	{
	  return 2;
	}
      else if (entry1_last[n] < entry2_last[n])
	{
	  return 1;
	}
      return 1;
    }
  return 1;
}

/* Sorts phonebook by last name */
void sort_phonebook()
{
  if (current_index == 0)
    {
      printf("You have added no contacts.\n");
      printf("\n");
      return;
    }
  int n;
  int i;
  int index_first = 0; /* Index of first-occurring value */
  struct contact tmp_entry;
  for (i = 0; i < current_index - 1; i++)
    {
      index_first = i;
      for (n = i; n < current_index; n++)
	{
	  if (n == current_index - 1)
	    {
	      /* Do nothing, no following indices to compare against */
	    }
	  else if (sort_entry(index_first, n+1) == 1)
	    {
	      /* Do nothing, index_first is (as of now) the first contact, alphabetically */
	    }
	  else
	    {
	      index_first = n+1;
	    }
	}
      if (i == index_first)
	{
	  /* Do nothing, contact is already where it should be */
	}
      else
	{
	  tmp_entry = phonebook[i];
	  phonebook[i] = phonebook[index_first];
	  for (n = index_first; n > i; n--)
	    {
	      phonebook[n] = phonebook[n-1];
	    }
	  phonebook[i+1] = tmp_entry;
	}
    }
  printf("Phone book has been sorted.\n");
  printf("\n");
}

void clear_phonebook()
{
  if (current_index == 0)
    {
      printf("The phone book is already clear.\n");
      printf("\n");
      return;
    }
  free(phonebook);
  phonebook = calloc(1, sizeof(struct contact));
  current_index = 0;
  printf("The phone book has been cleared.\n");
  printf("\n");
}

/* Selects then prints random contact from phone book */
void random_contact()
{
  if (current_index == 0)
  {
    printf("You have added no contacts.\n");
    printf("\n");
    return;
  }
  srand(time(NULL));
  /* Generates random number from 0 to the length of the phone book - 1 */
  int rand_index = rand() % current_index;
  print_contact(rand_index);
  printf("\n");
}

/* 
 * Prompts user to enter filename to save the current phone book as in
 * the current working directory
 */
void save_phonebook()
{
  FILE *write;
  char saved_filename[50];
  if (current_index == 0)
    {
      printf("You have added no contacts.\n");
      printf("\n");
      return;
    }
  printf("What would you like to call this phone book?\n");
  printf("(Without extension or filepath - it will be saved in the current working directory)\n");
  scanf("%s", saved_filename);
  strcat(saved_filename, ".txt");
  write = fopen(saved_filename, "w");
  /* Iterate through phone book array and write each contact to the file */
  int n;
  for (n = 0; n < current_index; n++)
    {
      fprintf(write, "%s %s %s\n",
	    phonebook[n].contact_first,
	    phonebook[n].contact_last,
	    phonebook[n].contact_number);
    }
  fclose(write);
  printf("\n");
  printf("The phonebook has been saved to %s\n", saved_filename);
  printf("\n");
}

/* Prompts user for name of their saved phone book to load */
void load_phonebook()
{
  FILE *read;
  char open_filename[50];
  if (current_index > 0)
    {
      char user_input;
      printf("There are already contacts in the phone book.\n");
      printf("Loading a phone book will delete any contacts not saved to a file.\n");
      printf("Do you wish to proceed?(Y/N) ");
      scanf("%s", &user_input);
      printf("\n");
      if (user_input == 'n' || user_input == 'N')
      {
	return;
      }
      clear_phonebook();
    }
  printf("What is the name of your phone book's save file? (without extension or filepath)\n");
  printf("NOTE: the file must be in the program's current working directory\n");
  scanf("%s", open_filename);
  strcat(open_filename,".txt");
  read = fopen(open_filename, "r");
  if (read == NULL)
    {
      printf("\n");
      printf("File cannot be opened.\n");
      printf("\n");
      return;
    }
  char file_first[50];
  char file_last[50];
  char file_number[50];
  do
    {
      fscanf(read, "%s%s%s", file_first, file_last, file_number);
      if (!feof(read))
	{
	  add_to_array(file_first, file_last, file_number);
	}
    }
  while (!feof(read));
  fclose(read);
  printf("\n");
  printf("%s has been loaded into the program.\n", open_filename);
  printf("\n");
}

int main()
{
  while (user_choice != 10)
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
	  individual_search();
	}
      else if (user_choice == 5)
	{
	  sort_phonebook();
	}
      else if (user_choice == 6)
	{
	  clear_phonebook();
	}
      else if (user_choice == 7)
	{
	  random_contact();
	}
      else if (user_choice == 8)
	{
	  save_phonebook();
	}
      else if (user_choice == 9)
	{
	  load_phonebook();
	}
    }
  free(phonebook);
}
