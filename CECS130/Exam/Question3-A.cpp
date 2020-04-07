#include <iostream>
#include <cstdlib>

using namespace std;

string myString = "Hi hello      A ";

int lastNonBlank(string searchedString)
{
  int i = 0;
  int index = -1;
  bool done = false;
  while (!done)
    {
      if (searchedString[i] == ' ')
	{
	  done = false;
	}
      else if (searchedString[i] == '\0')
	{
	  done = true;
	}
      else
	{
	  index = i;
	  done = false;
	}
      i++;
      
    }
  return index;
}

int main()
{
  
  int index = lastNonBlank(myString);
  cout<<index<<endl;
}
